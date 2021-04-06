#include<iostream>
#include<string>
#include"playground2.h"
using namespace std;


playground2::playground2()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			playground[i][j] = "-1";
	playground[0][0] = "A";
	playground[0][2] = "B";
	playground[0][4] = "C";
	playground[1][1] = "D";
	playground[1][2] = "E";
	playground[1][3] = "F";
	playground[2][0] = "G";
	playground[2][1] = "H";
	playground[2][3] = "I";
	playground[2][4] = "J";
	playground[3][1] = "K";
	playground[3][2] = "L";
	playground[3][3] = "M";
	playground[4][0] = "N";
	playground[4][2] = "O";
	playground[4][4] = "P";
	winner = "";
}
void playground2::showboard() {
	cout << "\t\t\t" << playground[0][0] << " _____" << playground[0][2] << " _____" << playground[0][4] << "\n";
	cout << "\t\t\t|      |      |  \n";
	cout << "\t\t\t|   " << playground[1][1] << " _" << playground[1][2] << " _" << playground[1][3] << "   |" << " \n";
	cout << "\t\t\t" << playground[2][0] << " _ " << playground[2][1] << "     " << playground[2][3] << " _ " << playground[2][4] << " \n";
	cout << "\t\t\t|   " << playground[3][1] << " _" << playground[3][2] << " _" << playground[3][3] << "   |" << " \n";
	cout << "\t\t\t|      |      |  \n";
	cout << "\t\t\t" << playground[4][0] << " _____" << playground[4][2] << " _____" << playground[4][4] << " \n\n";
}
bool playground2::gameover()
{

	if (win() == true)
		return true;
	if (leftMoves() == 0)
		return true;

	return false;
}
int playground2::leftMoves()
{
	int leftmoves = 16;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (playground[i][j] == "*" || playground[i][j] == "#")
				leftmoves--;
		}
	return leftmoves;
}
bool playground2::push_back(string n, string m)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (playground[i][j] == n)
			{
				playground[i][j] = m;
				return true;
			}
	return false;
}
bool playground2::rowcrossed() {

	if (playground[0][0] == playground[0][2] && playground[0][2] == playground[0][4])
	{
		winner = playground[0][0];
		return (true);
	}
	if (playground[1][1] == playground[1][2] && playground[1][2] == playground[1][3])
	{
		winner = playground[1][1];
		return (true);
	}
	if (playground[3][1] == playground[3][2] && playground[3][2] == playground[3][3])
	{
		winner = playground[3][1];
		return (true);
	}
	if (playground[4][0] == playground[4][2] && playground[4][2] == playground[4][4])
	{
		winner = playground[4][0];
		return (true);
	}

	return(false);
}
bool playground2::columncrossed() {

	if (playground[0][0] == playground[2][0] && playground[2][0] == playground[4][0])
	{
		winner = playground[0][0];
		return (true);
	}
	if (playground[1][1] == playground[2][1] && playground[2][1] == playground[3][1])
	{
		winner = playground[1][1];
		return (true);
	}
	if (playground[1][3] == playground[2][3] && playground[2][3] == playground[3][3])
	{
		winner = playground[1][3];
		return (true);
	}
	if (playground[0][4] == playground[2][4] && playground[2][4] == playground[4][4])
	{
		winner = playground[4][0];
		return (true);
	}

	return false;
}
bool playground2::win() {
	return(rowcrossed() || columncrossed());
}
string playground2::getWinner()
{
	return winner;
}
