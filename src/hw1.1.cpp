//============================================================================
// Name        : HW1 -- Wheel of Fortune
// Author      : John Wolf
// Professor   : Dr. St.Clair
// Class       : CSCE 306
// Description : Uses classes GamePhrases and GameState to run a game
//============================================================================

#include <iostream>
using namespace std;

#include "GamePhrases.h"
#include "GameState.h"

/*
 * There is in issue with the random seed not working in phrases and presumably in state as well. It needs to be addressed, but finish
 * setting up the code first
 */

int main()
{
	/*string phraseFile;
	cout << "Enter file name that contains phrases: " << endl;
	cin >> phraseFile;
	phraseFile = "data.txt";
	GamePhrases phrases(phraseFile, 10);
	string prizeFile = "prize.txt", player1 = "player1", player2 = "player2";
	GameState game(phrases.getPhrase(), prizeFile, 5, player1, player2);
	game.test_showPhrase();
	game.test_completePhrase();*/
	/*
	 * Setup variables
	 */
	string player1, player2, phraseFile, prizeFile, input;
	int p1winnings, p2winnings, phraseCount, prizeCount;
	cout << "Welcome to a Wheel of Fortune game by John Wolf. At any prompt for input, you may enter '0' to exit the game" << endl;
	cout << "==============================================================" << endl;
	input = ""; int count = 0;
	while(input != "0" && count < 7)
	{
		if(input == "0") {cout << "Exiting";}
		if(count >= 5) {cout << "Enter the ";}
		if(count == 0)
		{
			cout << "txt file phrases will";
		}
		else if(count == 1)
		{
			phraseFile = input;
			cout << "number of lines from " << phraseFile;
		}
		else if(count == 2)
		{
			phraseCount = stoi(input);
			cout << "txt file prizes will";
		}
		else if(count == 3)
		{
			prizeFile = input;
			cout << "number of lines from " << prizeFile;
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
		else if(count == 6)
		{
			player2 = input;
		}
		if(count < 6)
		{
			if(count < 4) {cout << " be read from: " << endl;}
			cin >> input;
		}
		count++;
	}
	if(input != "0")
	{
		GamePhrases phrases(phraseFile, phraseCount);
		p1winnings = p2winnings = 0;
		int winner;
		string sent = "";
		while(sent != "0")
		{
			GameState game(phrases.getPhrase(), prizeFile, prizeCount, player1, player2);
			sent = game.runGame();
			winner = game.getWinnerIndex();
			if(winner == 1) {p1winnings += game.getRoundPrize();}
			else {p2winnings += game.getRoundPrize();}
			cout << "In loop, sent = " << sent << ", winner = " << game.getWinnerIndex() << ", prize = " << game.getRoundPrize() << endl;
			cout << "\n\nTesting prize spin: " << endl;
			for(int i = 0; i < 5; i++)
			{
				cout << "Prize = " << game.spinWheel() << endl;
			}
		}
	}
	cout << player1 << " won $" << p1winnings << " total" << endl;
	cout << player2 << " won $" << p2winnings << " total" << endl;
	cout << "Goodbye!" << endl;
	return 0;
}










