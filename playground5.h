#pragma once
#include<string>
class playground5
{
public:
	playground5();
	bool gameover();
	bool push_back(std::string n, std::string m);
	void showboard();
	std::string getWinner();
private:
	std::string name;
	std::string playground[4][4];
	int leftMoves();
	bool columncrossed();
	bool rowcrossed();
	bool diagonalcrossed();
	bool win();
	std::string winner;

};
