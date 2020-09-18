//============================================================================
// Name        : John Wolf
// Project     : HW1 -- Wheel of Fortune
// Professor   : Dr.St.Clair
// Class       : CSCE 306
// Description : Uses classes GamePhrases and GameState to run a game
//============================================================================

#include <iostream>
using namespace std;

#include "GamePhrases.h"
#include "GameState.h"

/*
 *========================================================================================================================================================
 * Notes:
 *
 * There is in issue with the random seed not working in phrases and presumably in state as well. It needs to be addressed, but finish
 * setting up the code first -- fixed
 *
 * It seems to be running ok now with a few tests. Have to come up with a test method to throw random strings to test it and track the score of each
 * round. Also need to show incorrect guesses in runGame()
 *
 * You uploaded the .txt files you used for testing to the git hub repository. Make sure you delete/don't do that again, idiot
 *
 * The printing is really sloppy, it needs to get fixed asap
 *
 * To fix:
 * -The container in game phrases can't be an array, they need to be pointers and we can't use those, went with original idea to use a vector instead
 * 	--This is also true for game states prizes
 * 	 --FIXED
 * -The print lines in run game, they're sloppy and aren't as easy as they should be to follow
 * 	--
 * -Add a check in run game to see if the entries are letters
 * 	--
 *
 * -Fix prints after deciding to exit when prompted for settings
 * 	--
 *
 * =======================================================================================================================================================
 */

int main()
{
	//=============== To hard code game settings such as file names, lines read from each file, and player names, you may change these values=============
	/*1*/ string phraseFile = "";
	/*2*/ int phraseCount = 0;
	/*3*/ string prizeFile = "";
	/*4*/ int prizeCount = 0;
	/*5*/ string player1 = "";
	/*6*/ string player2 = "";
	//====================================================================================================================================================

	string input = "";
	cout << "Welcome to a Wheel of Fortune game by John Wolf. At any prompt for input, you may enter '0' to exit the game" << endl;
	cout << "==============================================================" << endl;



	//============================== This block is to get any left over variables that were not hard coded above ========================================
	if(phraseFile == "")
	{
		cout << "Enter the phrase file name: " << endl;
		cin >> input;
		phraseFile = input;
	}
	if(input != "0" && phraseCount == 0)
	{
		cout << "Enter the number of lines to read from " << phraseFile << ":" << endl;
		cin >> input;
		phraseCount = stoi(input);
	}
	if(input != "0" && prizeFile == "")
	{
		cout << "Enter the prize file name: " << endl;
		cin >> input;
		prizeFile = input;
	}
	if(input != "0" && prizeCount == 0)
	{
		cout << "Enter the number of lines to read from " << prizeFile << ":" << endl;
		cin >> input;
		prizeCount = stoi(input);
	}
	if(input != "0" && player1 == "")
	{
		cout << "Enter player 1's name:" << endl;
		cin >> input;
		player1 = input;
	}
	if(input != "0" && player2 == "")
	{
		cout << "Enter player 2's name:" << endl;
		cin >> input;
		player2 = input;
	}
	//====================================================================================================================================================



	int p1winnings, p2winnings;
	if(input != "0")
	{
		GamePhrases phrases(phraseFile, phraseCount);
		p1winnings = p2winnings = 0;
		int winner, prize;
		/*
		 * Loop that runs each instance of GameState. The loop is skipped if the user decides to enter a 0 for any entry above. Once inside the loop,
		 * it is controlled by a sentinel value that is returned from the runGame method in GameState
		 */
		while(input != "0")
		{
			GameState game(phrases.getPhrase(), prizeFile, prizeCount, player1, player2);
			input = game.runGame();
			winner = game.getWinnerIndex();
			prize = game.getRoundPrize();
			if(prize < 0) {prize = 0;}
			if(winner == 0) {p1winnings += prize;}
			else {p2winnings += prize;}
		}
		cout << player1 << " won $" << p1winnings << " in total" << endl;
		cout << player2 << " won $" << p2winnings << " in total" << endl;
		cout << "Goodbye!" << endl;
	}
	else {cout << "Exiting" << endl;}
	return 0;
}









