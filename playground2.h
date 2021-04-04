#pragma once
#include<string>
class playground2
{
public:
	playground2();
	bool gameover();
	bool push_back(std::string n, std::string m);
	void showboard();
private:
	std::string name;
	std::string playground[5][5];
	int leftMoves();
	bool check();

};
