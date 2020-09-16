//============================================================================
// Name        : John Wolf
// Project     : HW1 -- Wheel of Fortune
// Professor   : Dr. St.Clair
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
 * =======================================================================================================================================================
 */

int main()
{
	/*
	 * Variable initialization
	 */
	string player1, player2, phraseFile, prizeFile, input;
	int p1winnings, p2winnings, phraseCount, prizeCount;

	/*
	 * Welcome screen
	 */
	cout << "Welcome to a Wheel of Fortune game by John Wolf. At any prompt for input, you may enter '0' to exit the game" << endl;
	cout << "==============================================================" << endl;
	input = ""; int count = 0;

	/*
	 * This loop is to get all of the information that both GamePhrases and GameState will use, such as file names and lines to be read as well as player
	 * names. It is controlled by a sentinel value of 0, which is the same value as the main loop below
	 *
	 * !!! Make sure this is not commented out for the final version !!!
	 *
	 */

	/*while(input != "0" && count < 7)
	{
		if(input == "0") {cout << "Exiting";}
		if(count >= 5) {cout << "Enter the ";}
		if(count == 0) {cout << "txt file phrases will";}
		else if(count == 1)
		{
			phraseFile = input;
			cout << "number of lines from " << phraseFile << "to be";
		}
		else if(count == 2)
		{
			phraseCount = stoi(input);
			cout << "txt file prizes will";
		}
		else if(count == 3)
		{
			prizeFile = input;
			cout << "number of lines from " << prizeFile << "to be";
		}
		else if(count == 4)
		{
			prizeCount = stoi(input);
			cout << "name of player 1: " << endl;
		}
		else if(count == 5)
		{
			player1 = input;
			cout << "name of player 2" << endl;
		}
		else if(count == 6) {player2 = input;}
		if(count < 6)
		{
			if(count < 4) {cout << " be read from: " << endl;}
			cin >> input;
		}
		count++;
	}*/

	/*
	 * This is for testing purposes, delete this before turning in
	 */
	phraseFile = "data.txt";
	phraseCount = 10;
	prizeFile = "prize.txt";
	prizeCount = 5;
	player1 = "p1";
	player2 = "p2";
	if(input != "0")
	{
		GamePhrases phrases(phraseFile, phraseCount);
		p1winnings = p2winnings = 0;
		int winner, prize;
		string sent = "";
		/*
		 * Loop that runs each instance of GameState. The loop is skipped if the user decides to enter a 0 for any entry above. Once inside the loop,
		 * it is controlled by a sentinel value that is returned from the runGame method in GameState
		 */
		while(sent != "0")
		{
			GameState game(phrases.getPhrase(), prizeFile, prizeCount, player1, player2);
			sent = game.runGame();
			winner = game.getWinnerIndex();
			prize = game.getRoundPrize();
			if(prize < 0) {prize = 0;}
			if(winner == 0) {p1winnings += prize;}
			else {p2winnings += prize;}
		}
	}
	cout << player1 << " won $" << p1winnings << "in total" << endl;
	cout << player2 << " won $" << p2winnings << "in total" << endl;
	cout << "Goodbye!" << endl;
	return 0;
}










