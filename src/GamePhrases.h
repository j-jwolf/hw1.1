/*
 * GamePhrases.h
 *
 *  Created on: Sep 14, 2020
 *      Author: jwolf
 */

#ifndef GAMEPHRASES_H_
#define GAMEPHRASES_H_

#include <string>
#include <fstream>
#include <vector>
using namespace std;

class GamePhrases
{
private:
	ifstream _infile;
	string _fn;
	int _lines;
	vector<string> _phrases;
public:
	GamePhrases(){}
	GamePhrases(string, int);
	void setFileName(string fileName) {_fn = fileName;}
	void setLineCount(int lineCount) {_lines = lineCount;}
	void readPhrases();
	string getPhrase();
};

#endif /* GAMEPHRASES_H_ */
