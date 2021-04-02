#include<iostream>
#include<string>
using namespace std;

class playground1
{
public:
	playground1();
	void showboard();
	bool finish();
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
playground1::playground1() {
	playground[0][0] = "1";
	playground[0][1] = "2";
	playground[0][2] = "3";
	playground[1][0] = "4";
	playground[1][1] = "5";
	playground[1][2] = "6";
	playground[2][0] = "7";
	playground[2][1] = "8";
	playground[2][2] = "9";
}
void playground1::showboard() {
	cout<<"\n\n";

	cout << "\t\t\t" << playground[0][0] << " | " << playground[0][1] << " | " << playground[0][2] << "\n";
	cout<<"\t\t\t--------------\n";
	cout << "\t\t\t " << playground[1][0] << " | " << playground[1][1] << " | " << playground[1][2] << " \n";
	cout<<"\t\t\t--------------\n";
	cout << "\t\t\t " << playground[2][0] << " | " << playground[2][1] << " | " << playground[2][2] << " \n\n";
	return;
}

bool playground1::finish() {
	if (win() == true)
		return true;
	if (leftMoves() == 0)
		return true;

	return false;
}
bool playground1::win() {
	return(rowcrossed() || columncrossed() || diagonalcrossed());
}

int playground1::leftMoves() {
	int leftmoves = 9;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (playground[i][j] == "*" || playground[i][j] == "#")
				leftmoves--;
		}
	return leftmoves;
}
bool playground1::push_back(string n, string m) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (playground[i][j] == n)
			{
				playground[i][j] = m;
				return true;
			}
	return false;
}
bool playground1::rowcrossed() {
	for (int i = 0; i < 3; i++)
	{
		if (playground[i][0] == playground[i][1] && playground[i][1] == playground[i][2] )
			return (true);
	}
	return(false);
}

bool playground1:: columncrossed() {
	for (int i = 0; i < 3; i++)
	{
		if (playground[0][i] == playground[1][i] && playground[1][i] == playground[2][i] )
			return (true);
	}
	return(false);
}

bool playground1::diagonalcrossed() {
	if (playground[0][0] == playground[1][1] && playground[1][1] == playground[2][2] )
		return(true);

	if (playground[0][2] == playground[1][1] && playground[1][1] == playground[2][0] )
		return(true);

	return(false);
}
