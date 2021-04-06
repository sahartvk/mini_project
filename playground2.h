#pragma once
#include<string>
class playground2
{
public:
	playground2();
	bool gameover();
	bool push_back(std::string n, std::string m);
	void showboard();
	std::string getWinner();
private:
	std::string name;
	std::string playground[5][5];
	int leftMoves();
	bool columncrossed();
	bool rowcrossed();
	bool win();
	std::string winner;

};
