#pragma once
#include<string>
class playground2
{
public:
	playground2();
	bool gameover();
	bool push_back(char n, char m);
private:
	std::string name;
	char playground[5][5];
	int leftMoves();
	bool check();

};