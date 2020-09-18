/*
 * GameState.h
 *
 *  Created on: Sep 14, 2020
 *      Author: jwolf
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <string>
#include <fstream>
#include <vector>
using namespace std;

class GameState
{
private:
	int _wIndex, _roundWin, _activePlayer, _lines, _remaining;
	string _p1, _p2, _phrase, _visPhrase, _fn;
	vector<char> _incorrect;
	vector<int> _prizes;
	ifstream _infile;
	void readPrizes();
public:
	GameState(){}
	GameState(string, string, int, string, string);
	void setPlayers(string, string);
	int const getWinnerIndex() {return _wIndex;}
	int const getRoundPrize() {return _roundWin;}
	int const spinWheel();
	string const runGame();
};

#endif /* GAMESTATE_H_ */
