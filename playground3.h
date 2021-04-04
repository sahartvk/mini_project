#include<string>
class playground3
{
public:
	playground3();
	void showboard();
	bool gameover();
	bool win();
	bool push_back(string n, string m);
	
private:
	string name;
	string playground[7][7];
	int leftMoves();
	bool rowcrossed();
	bool columncrossed();
	bool diagonalcrossed();
};
