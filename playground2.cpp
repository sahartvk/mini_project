#include<iostream>
#include<string>
#include"playground2.h"
using namespace std;


playground2::playground2()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			playground[i][j] = "-1";
	playground[0][0] = "1";
	playground[0][2] = "2";
	playground[0][4] = "3";
	playground[1][1] = "4";
	playground[1][2] = "5";
	playground[1][3] = "6";
	playground[2][0] = "7";
	playground[2][1] = "8";
	playground[2][3] = "9";
	playground[2][4] = "10";
	playground[3][1] = "11";
	playground[3][2] = "12";
	playground[3][3] = "13";
	playground[4][0] = "14";
	playground[4][2] = "15";
	playground[4][4] = "16";
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
