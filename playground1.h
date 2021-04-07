#include<string>
class playground1
{
public:
	playground1();
	void showboard();
	bool gameover();
	bool win();
	bool push_back(std::string n, std::string m);

private:
	std::string name;
	std::string playground[3][3];
	int leftMoves();
	bool rowcrossed();
	bool columncrossed();
	bool diagonalcrossed();
};