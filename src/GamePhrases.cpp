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
	srand(time(0));
	_fn = fileName;
	_infile.open(fileName);
	if(!_infile) {exit(-1);}
	_infile.close();
	_lines = lineCount;
	readPhrases();
}
/**
 * Reads the phrases from filename and stores them in vector _phrases
 *
 * @return null
 */
void GamePhrases::readPhrases()
{
	_infile.open(_fn);
	string temp, phrase;
	int count = 0;
	while(count < _lines && !_infile.eof())
	{
		getline(_infile, temp);
		_phrases.push_back(temp);
		count++;
	}
	_infile.close();
}
/*
 * Returns a phrase from a random index in _phrases
 *
 * @return phrase to be used by game state
 */
string GamePhrases::getPhrase()
{
	int index;
	index = rand()%(_lines-1);
	string phrase = _phrases[index];
	return phrase;
}
