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
}
void playground2:: show() {
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

	if (check() == true)
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
bool playground2::check()
{
	int star = 0, numsign = 0;
	for (int i = 0; i < 5; i++)
	{
		star = 0, numsign = 0;
		if (i == 2)
			continue;
		for (int j = 0; j < 5; j++)
			if (playground[i][j] == "*")
				star++;
			else if (playground[i][j] == "#")
				numsign++;
		if (star == 3 || numsign == 3)
			return true;
	}
	for (int j = 0; j < 5; j++)
	{
		star = 0, numsign = 0;
		if (j == 2)
			continue;
		for (int i = 0; i < 5; i++)
			if (playground[i][j] == "*")
				star++;
			else if (playground[i][j] == "#")
				numsign++;
		if (star == 3 || numsign == 3)
			return true;
	}
	return false;
}
