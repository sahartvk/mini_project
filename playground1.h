#include<string>
class playground1
{
public:
	playground1();
	void showboard();
	bool gameover();
	bool win();
	bool push_back(string n, string m);
	
private:
	string name;
	string playground[3][3];
	int leftMoves();
	bool rowcrossed();
	bool columncrossed();
	bool diagonalcrossed();
};
