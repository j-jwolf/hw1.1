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
	srand(time(0));
	_phrase = phrase;
	_fn = fileName;
	_lines = lineCount;
	_infile.open(_fn);
	if(!_infile) {exit(-2);}
	string temp;
	int count = 0, val;
	while(!_infile.eof() && count < _lines)
	{
		getline(_infile, temp);
		val = stoi(temp);
		_prizes.push_back(val);
		count++;
	}
	_infile.close();
	_wIndex = -1;
	_roundWin = -1;
	_activePlayer = 0;
	_p1 = player1;
	_p2 = player2;
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
}
/**
 * Runs the game in the current state
 *
 * @return string that is the sentinel value for main's loop
 */
string const GameState::runGame()
{
	string input = "";
	int letCount, length = _phrase.length(), incorrectCount;
	char letter;
	int winnings[2];
	winnings[0] = 0;
	winnings[1] = 0;
	cout << "===========================================================" << endl << endl;
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
			if(_activePlayer == 0) {_activePlayer++;}
			else {_activePlayer--;}
		}
		cout << "===========================================================" << endl << endl;
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
 * @return random integer from vector _prizes
 */
int const GameState::spinWheel()
{
	int prize;
	int index = rand()%(_lines-1);
	prize = _prizes[index];
	return prize;
}







