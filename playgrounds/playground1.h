#include<string>
class playground1
{
public:
	playground1();
	void showboard();
	bool gameover();
	bool push_back(std::string n, std::string m);
	std::string getWinner();

private:
	std::string name;
	std::string playground[3][3];
	int leftMoves();
	bool rowcrossed();
	bool columncrossed();
	bool diagonalcrossed();
	std::string winner;
	bool win();
};
