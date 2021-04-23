#pragma once
#include<string>
class playground4
{
public:
	playground4();
	bool gameover();
	bool push_back(std::string n, std::string m);
	void showboard();
	std::string getWinner();
private:
	std::string name;
	std::string playground[3][3];
	int leftMoves();
	bool columncrossed();
	bool rowcrossed();
	bool diagonalcrossed();
	bool win();
	std::string winner;

};
