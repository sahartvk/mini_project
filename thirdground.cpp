#include<iostream>
#include<string>
using namespace std;

class playground3
{
public:
	playground3();
	void showboard();
	bool finish();
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
playground3::playground3()
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			playground[i][j] = "-1";
	playground[0][0] = "1";
	playground[0][3] = "2";
	playground[0][6] = "3";
	playground[1][1] = "4";
	playground[1][3] = "5";
	playground[1][5] = "6";
	playground[2][2] = "7";
	playground[2][3] = "8";
	playground[2][4] = "9";
	playground[3][0] = "10";
	playground[3][1] = "11";
	playground[3][2] = "12";
	playground[3][4] = "13";
	playground[3][5] = "14";
	playground[3][6] = "15";
	playground[4][2] = "16";
	playground[4][3] = "17";
	playground[4][4] = "18";
	playground[5][1] = "19";
	playground[5][5] = "20";
	playground[6][0] = "21";
	playground[6][6] = "22";
	
}
void playground3::showboard()
{
	printf("\n\n");
	cout << "\t\t\t" << playground[0][0] << "\t\t\t" << playground[0][3] << " \t\t\t " << playground[0][6] << " \n\n";
	cout << "\t\t\t\t " << playground[1][1] << "\t\t " << playground[1][3] << " \t\t " << playground[1][5] << " \n\n";
	cout << "\t\t\t\t\t " << playground[2][2] << "t " << playground[2][3] << " \t " << playground[2][4] << " \n\n";
	cout << "\t\t\t " << playground[3][0] << "\t" << playground[3][1] << "\t " << playground[3][2] << "\t \t  " << playground[3][4] << " \t " << playground[3][5] << " \t " << playground[3][6] << "\n\n";
	cout << "\t\t\t\t\t " << playground[4][2] << "\t " << playground[4][3] << " \t " << playground[4][4] << " \n\n";
	cout << "\t\t\t\t " << playground[5][1] << "\t\t    \t\t " << playground[5][5] << " \n\n";
	cout << "\t\t\t " << playground[6][0] << "\t\t\t    \t\t\t " << playground[6][6] << " \n";
}

bool playground3::finish()
{
	if (win() == true)
		return true;
	if (leftMoves() == 0)
		return true;

	return false;
}
bool playground3::win() {
	return(rowcrossed() || columncrossed() || diagonalcrossed());
}

int playground3::leftMoves()
{
	int leftmoves = 22;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (playground[i][j] == "*" || playground[i][j] == "#")
				leftmoves--;
		}
	return leftmoves;
}
bool playground3::push_back(string n, string m)
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			if (playground[i][j] == n)
			{
				playground[i][j] = m;
				return true;
			}
	return false;
}
bool playground3::rowcrossed()
{
	if (playground[0][0] == playground[0][3] && playground[0][3] == playground[0][6])
		return true;
	else if (playground[1][1] == playground[1][3] && playground[1][3] == playground[1][5])
		return true;
	else if (playground[2][2] == playground[2][3] && playground[2][3] == playground[2][4])
		return true;
	else if (playground[3][0] == playground[3][1] && playground[3][1] == playground[3][2])
		return true;
	else if (playground[3][4] == playground[3][5] && playground[3][5] == playground[3][6])
		return true;
	else if (playground[4][2] == playground[4][3] && playground[4][3] == playground[4][4])
		return true;

	return(false);
}

bool playground3::columncrossed()
{
	if (playground[0][0] == playground[3][0] && playground[3][0] == playground[6][0])
		return true;
	else if (playground[1][1] == playground[3][1] && playground[3][1] == playground[5][1])
		return true;
	else if (playground[2][2] == playground[3][2] && playground[3][2] == playground[4][2])
		return true;
	else if (playground[0][3] == playground[1][3] && playground[1][3] == playground[2][3])
		return true;
	else if (playground[2][4] == playground[3][4] && playground[3][4] == playground[4][4])
		return true;
	else if (playground[1][5] == playground[3][5] && playground[3][5] == playground[5][5])
		return true;
	else if (playground[0][6] == playground[3][6] && playground[3][6] == playground[6][6])
		return true;
	return(false);
}
bool playground3::diagonalcrossed() {

	if (playground[0][0] == playground[1][1] && playground[1][1] == playground[2][2])
		return true;
	if (playground[0][6] == playground[1][5] && playground[1][5] == playground[2][4])
		return true;
	if (playground[4][2] == playground[5][1] && playground[5][1] == playground[6][3])
		return true;
	if (playground[4][4] == playground[5][5] && playground[5][5] == playground[6][6])
		return true;
	return false;
}

