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
using namespace std;

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
	string s;
	_wIndex = 1;
	_roundWin = 100;
	s = "0";
	return s;
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






