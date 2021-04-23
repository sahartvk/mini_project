#include<iostream>
#include<string>
#include"playground5.h"
using namespace std;


playground5::playground5()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			playground[i][j] = "-1";
	playground[0][0] = "A";
	playground[0][1] = "B";
	playground[0][2] = "C";
	playground[0][3] = "D";
	playground[1][0] = "E";
	playground[1][1] = "F";
	playground[1][2] = "G";
	playground[1][3] = "H";
	playground[2][0] = "I";
	playground[2][1] = "J";
	playground[2][2] = "K";
	playground[2][3] = "L";
	playground[3][0] = "M";
	
	winner = "";
}
void playground5::showboard() {
	cout << "\t\t\t                " << "\x1B[33m" << playground[0][0] << "\033[0m\n";
	cout << "\x1B[36m\t\t\t               /|\\ \033[0m\n";
	cout << "\x1B[36m\t\t\t              / | \\ \033[0m\n";
	cout << "\x1B[36m\t\t\t             /  |  \\ \033[0m\n";
	cout << "\x1B[36m\t\t\t            /   \033[0m" << "\x1B[33m" << playground[0][1] << "\033[0m" <<"\x1B[36m   \\ \n";
	cout << "\t\t\t           /    |    \\ \n";
	cout << "\t\t\t          /     |     \\ \n";
	cout << "\t\t\t         /      \033" << "\x1B[33m" <<playground[0][2] << "\033[0m"<<"\x1B[36m      \\ \n";
	cout << "\t\t\t        /       /\\      \\ \n";
	cout << "\t\t\t      \033" << "\x1B[33m" <<playground[0][3] << "\033[0m"<<"\x1B[36m        /  \\      \033[0m" << "\x1B[33m" <<playground[1][0] << "\033[0m"<<endl;
	cout << "\x1B[36m\t\t\t      /       \033" << "\x1B[33m" <<playground[1][1] << "\033[0m"<<"    " << "\x1B[33m" <<playground[1][2] << "\033[0m"<< "\x1B[36m      \\ \n";
	cout << "\t\t\t     /       /      \\      \\ \n";
	cout << "\t\t\t    /       /        \\      \\ \n";
	cout << "\t\t\t   /       \033" << "\x1B[33m" <<playground[1][3] << "\033[0m"<<"\x1B[36m ____\033[0m" << "\x1B[33m" <<playground[2][0] << "\033[0m"<<"\x1B[36m____\033[0m" << "\x1B[33m" << playground[2][1] << "\033[0m"<< "\x1B[36m      \\ \n";
	cout << "\t\t\t  /                           \\ \n";
	cout << "\t\t\t /                             \\ \n";
	cout << "\t\t\t\033[0m" << "\x1B[33m" <<playground[2][2] << "\033[0m"<<"\x1B[36m ______________\033[0m" << "\x1B[33m" <<playground[2][3] << "\033[0m"<<"\x1B[36m______________\033[0m " << "\x1B[33m" << playground[3][0] << "\033[0m"<< "  \n";
}
bool playground5::gameover()
{

	if (win() == true)
		return true;
	if (leftMoves() == 0)
		return true;

	return false;
}
int playground5::leftMoves()
{
	int leftmoves = 13;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (playground[i][j] == "*" || playground[i][j] == "#")
				leftmoves--;
		}
	return leftmoves;
}
bool playground5::push_back(string n, string m)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (playground[i][j] == n)
			{
				playground[i][j] = m;
				return true;
			}
	return false;
}
bool playground5::rowcrossed() {

	if (playground[2][2] == playground[2][3] && playground[2][3] == playground[3][0])
	{
		winner = playground[2][2];
		return (true);
	}
	
	if (playground[1][3] == playground[2][0] && playground[2][0] == playground[2][1])
	{
		winner = playground[1][3];
		return (true);
	}

	return(false);
}
bool playground5::columncrossed() {

	if (playground[0][0] == playground[0][1] && playground[0][1] == playground[0][2])
	{
		winner = playground[0][0];
		return (true);
	}
	
	return false;
}
bool playground5::diagonalcrossed() {
	if (playground[0][0] == playground[0][3] && playground[0][3] == playground[2][2])
	{
		winner = playground[2][2];
		return (true);
	}

	if (playground[0][0] == playground[1][0] && playground[1][0] == playground[3][0])
	{
		winner = playground[1][0];
		return (true);
	}
	if (playground[0][2] == playground[1][1] && playground[1][1] == playground[1][3])
	{
		winner = playground[0][2];
		return (true);
	}

	if (playground[0][2] == playground[1][2] && playground[1][2] == playground[2][1])
	{
		winner = playground[1][2];
		return (true);
	}
	return(false);
}
bool playground5::win() {
	return(rowcrossed() || columncrossed() || diagonalcrossed());
}
string playground5::getWinner()
{
	return winner;
}
