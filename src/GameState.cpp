/*
 * GameState.cpp
 *
 *  Created on: Sep 14, 2020
 *      Author: jwolf
 */

#include "GameState.h"

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;


/*
 * ========================================================================================================================================================
 *
 * Notes for GameState:
 *
 * -Consider adding a check if(guess is in _incorrect) method, that would prevent the same letter from being in the vector
 *
 *========================================================================================================================================================
 */

/**
 * n-argument constructor for the GameState class object
 *
 * @param phrase- phrase to be used during the round
 * @param fileName- name of file that contains the prize amounts
 * @param lineCount- number of lines to read from file
 * @param player1- name of player1
 * @param player2- name of player2
 *
 * @return null
 */
GameState::GameState(string phrase, string fileName, int lineCount, string player1, string player2)
{
	_phrase = phrase;
	_fn = fileName;
	_infile.open(_fn);
	if(!_infile) {exit(-2);}
	_infile.close();
	_lines = lineCount;
	_wIndex = -1;
	_roundWin = -1;
	_activePlayer = 0;
	_p1 = player1;
	_p2 = player2;
	//
	cout << "Phrase in constructor: " << _phrase << endl;
	_visPhrase = "";
	char letter;
	int length = _phrase.length(), spaceCount = 0;
	for(int i = 0; i < length; i++)
	{
		letter = _phrase[i];
		if(letter == ' ' || letter == '-') {_visPhrase += letter; spaceCount++;}
		else {_visPhrase += '_';}
	}
	_remaining = length - spaceCount;
	cout << "Testing: phrase: " << _phrase << ", vis: " << _visPhrase << ", active: " << _activePlayer;
	cout << ", index: " << _wIndex << endl << "1: " << _p1 << ", 2: " << _p2 << ", lines: " << _lines << endl;
	cout << "remain: " << _remaining << endl << "End test" << endl;
}
/**
 * !!! Delete me !!!
 * Test method to show the phrase and visible phrase stored in GameState
 *
 * @return null
 */
void GameState::test_showPhrase()
{
	cout << "Phrase: " << _phrase << endl << "Visible: " << _visPhrase << endl << "Remaining letters: " << _remaining << endl;
}
/**
 * !!! Delete me !!!
 * Test method to complete the visible phrase
 *
 * @return null
 */
void GameState::test_completePhrase()
{
	char letter;
	int length = _phrase.length();
	cout << "Your phrase: " << _visPhrase << endl;
	for(int i = 0; i < length; i++)
	{
		letter = _phrase[i];
		_visPhrase[i] = letter;
		_remaining--;
		cout << _visPhrase << endl << "Remaining letters: " << _remaining << endl;
	}
}
/**
 * Runs the game in the current state
 *
 * @return string that is the sentinel value for main's loop
 */
string GameState::runGame()
{
	string input = "";
	int letCount, length = _phrase.length(), incorrectCount;
	char letter;
	int winnings[2];
	winnings[0] = 0;
	winnings[1] = 0;
	while(input != "0" && _remaining > 0)
	{
		incorrectCount = _incorrect.size();
		vector<int> indices;
		int prize = spinWheel();
		cout << "Your phrase is: " << _visPhrase << endl << "There are " << _remaining << " letter";
		if(_remaining == 1) {cout << "s";}
		cout << " remaining!" << endl << endl;
		cout << "Incorrect guesses: ";
		for(int i = 0; i < incorrectCount; i++)
		{
			cout << _incorrect[i] << " ";
		}
		cout << "\n\n\n";
		cout << "It is ";
		if(_activePlayer == 0) {cout << _p1;}
		else {cout << _p2;}
		cout << "'s turn! The wheel lands on $" << prize << "!" << endl << endl;
		letCount = 0;
		cout << "Enter a letter to guess: " << endl;
		cin >> input;
		letter = input[0];
		for(int i = 0; i < length; i++)
		{
			if(letter == _phrase[i])
			{
				letCount++;
				indices.push_back(i);
			}
		}
		if(indices.size() > 0)
		{
			for(int i = 0; i < letCount; i++)
			{
				_visPhrase[indices[i]] = letter;
				_remaining--;
			}
			winnings[_activePlayer] += (prize*letCount);
		}
		else if(indices.size() == 0 && input != "0")
		{
			cout << letter << " is not part of the phrase! " << endl;
			_incorrect.push_back(letter);
			/*
			 * I decided to use to_string(letter) here instead of input in case the user enters more that one letter in a string. this will only use the
			 * first letter in the string and ensure that there are not instances of a letter which would normally be correct being added to the incorrect
			 * vector. I might even switch this to a vector<char> as well
			 */
			if(_activePlayer == 0) {_activePlayer++;}
			else {_activePlayer--;}
		}
	}
	if(_remaining == 0)
	{
		if(_activePlayer == 0)
		{
			cout << _p1 << " wins this round and adds $" << winnings[0] << " to their total!" << endl;
		}
		else
		{
			cout << _p2 << " wins this round and adds $" << winnings[1] << " to their total!" << endl;
		}
		_wIndex = _activePlayer;
		_roundWin = winnings[_activePlayer];
		cout << "To play another round, enter new or enter 0 to exit: " << endl;
		cin >> input; // this is sloppy, fix it
	}
	return input;
}
/**
 * Returns a random integer value prize from the file
 *
 * @return random integer read from file
 */
int GameState::spinWheel()
{
	_infile.open(_fn);
	if(!_infile) {exit(-2);}
	string temp;
	srand(time(0));
	int count = 0, x = rand()%_lines, prize, prizes[_lines];
	while(_infile && count < _lines)
	{
		getline(_infile, temp);
		prize = stoi(temp);
		prizes[count] = prize;
		count++;
	}
	_infile.close();
	prize = prizes[x];
	return prize;
}






