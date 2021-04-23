#include<iostream>
#include<string>
#include"playground4.h"
using namespace std;


playground4::playground4()
{
	playground[0][0] = "A";
	playground[0][1] = "B";
	playground[0][2] = "C";
	playground[1][0] = "D";
	playground[1][1] = "E";
	playground[1][2] = "F";
	playground[2][0] = "G";
	playground[2][1] = "H";
	playground[2][2] = "I";
	
	winner = "";
}

void playground4::showboard() {
	cout << "\t\t\t      \x1B[31m" << playground[0][0] << "\033[0m\x1B[33m _____ \033[0m\x1B[31m" << playground[0][1] << "\033[0m\x1B[33m _____ \033[0m\x1B[31m" << playground[0][2] << "\033[0m" << endl;
	cout << "\x1B[33m\t\t\t      |\\      |      /|" << endl;
	cout << "\t\t\t      | \\     |     / |" << endl;
	cout << "\t\t\t      |  \\    |    /  |" << endl;
	cout << "\t\t\t      |   \\   |   /   |" << endl;
	cout << "\t\t\t      |    \\  |  /    |" << endl;
	cout << "\t\t\t      |     \\ | /     |\033[0m" << endl;
	cout << "\t\t\t      \x1B[31m" << playground[1][0] << "\033[0m\x1B[33m _____ \033[0m\x1B[31m" << playground[1][1] << "\033[0m\x1B[33m _____ \033[0m\x1B[31m" << playground[1][2] << "\033[0m" << endl;
	cout << "\x1B[33m\t\t\t      |     / | \\     |\n";
	cout << "\t\t\t      |    /  |  \\    |" << endl;
	cout << "\t\t\t      |   /   |   \\   |" << endl;
	cout << "\t\t\t      |  /    |    \\  |" << endl;
	cout << "\t\t\t      | /     |     \\ |" << endl;
	cout << "\t\t\t      |/      |      \\|\033[0m" << endl;
	cout << "\t\t\t      \x1B[31m" << playground[2][0] << "\033[0m\x1B[33m _____ \033[0m\x1B[31m" << playground[2][1] << "\033[0m\x1B[33m _____ \033[0m\x1B[31m" << playground[2][2] << "\033[0m" << endl;

}
bool playground4::gameover()
{

	if (win() == true)
		return true;
	if (leftMoves() == 0)
		return true;

	return false;
}
int playground4::leftMoves()
{
	int leftmoves = 9;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (playground[i][j] == "*" || playground[i][j] == "#")
				leftmoves--;
		}
	return leftmoves;
}
bool playground4::push_back(string n, string m)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (playground[i][j] == n)
			{
				playground[i][j] = m;
				return true;
			}
	return false;
}
bool playground4::rowcrossed() {

	if (playground[0][0] == playground[0][1] && playground[0][1] == playground[0][2])
	{
		winner = playground[0][0];
		return (true);
	}
	if (playground[1][0] == playground[1][1] && playground[1][1] == playground[1][2])
	{
		winner = playground[1][0];
		return (true);
	}
	if (playground[2][0] == playground[2][1] && playground[2][1] == playground[2][2])
	{
		winner = playground[2][0];
		return (true);
	}
	
	return(false);
}
bool playground4::columncrossed() {

	if (playground[0][0] == playground[1][0] && playground[1][0] == playground[2][0])
	{
		winner = playground[0][0];
		return (true);
	}
	if (playground[0][1] == playground[1][1] && playground[1][1] == playground[2][1])
	{
		winner = playground[0][1];
		return (true);
	}
	if (playground[0][2] == playground[1][2] && playground[1][2] == playground[2][2])
	{
		winner = playground[0][2];
		return (true);
	}
	
	return false;
}
bool playground4::diagonalcrossed() {
	if (playground[0][0] == playground[1][1] && playground[1][1] == playground[2][2]) {
		winner = playground[0][0];
		return true;
	}
	if (playground[0][2] == playground[1][1] && playground[1][1] == playground[2][0]) {
		winner = playground[0][2];
		return true;
	}
}
bool playground4::win() {
	return(rowcrossed() || columncrossed() || diagonalcrossed());
}
string playground4::getWinner()
{
	return winner;
}
