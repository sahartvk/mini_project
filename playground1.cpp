#include<iostream>
#include "playground1.h"
#include<string>
using namespace std;


playground1::playground1() {
	playground[0][0] = "A";
	playground[0][1] = "B";
	playground[0][2] = "C";
	playground[1][0] = "D";
	playground[1][1] = "E";
	playground[1][2] = "F";
	playground[2][0] = "G";
	playground[2][1] = "H";
	playground[2][2] = "I";
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

bool playground1::gemeover() {
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
