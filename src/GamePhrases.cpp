/*
 * GamePhrases.cpp
 *
 *  Created on: Sep 14, 2020
 *      Author: jwolf
 */

#include "GamePhrases.h"

#include <string>
#include <fstream>
#include <ctime>
#include <iostream> // delete before turning in, this is for testing only
using namespace std;

/**
 * n-argument constructor for GamePhrases class object
 *
 * @param fileName- name of the file that contains phrases
 * @param lineCount- number of lines to read from file
 *
 * @return null
 */
GamePhrases::GamePhrases(string fileName, int lineCount)
{
	_fn = fileName;
	_infile.open(fileName);
	if(!_infile) {exit(-1);}
	_infile.close();
	_lines = lineCount;
}
/**
 * Gets a phrase from a random line in the given file
 *
 * @return phrase to be used for GameState
 */
string GamePhrases::getPhrase()
{
	_infile.open(_fn);
	string temp, phrase, phrases[_lines];
	srand(time(0));
	int count = 0, x = rand()%_lines;
	while(count < _lines && _infile)
	{
		getline(_infile, temp);
		phrases[count] = temp;
		count++;
	}
	_infile.close();
	phrase = phrases[x];
	cout << "x = " << x << endl;
	cout << "phrase: " << phrase << endl;
	return phrase;
}

