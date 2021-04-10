#include<iostream>
#include<string>
#include "playground3.h"
using namespace std;


playground3::playground3()
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			playground[i][j] = "-1";
	playground[0][0] = "A";
	playground[0][3] = "B";
	playground[0][6] = "C";
	playground[1][1] = "D";
	playground[1][3] = "E";
	playground[1][5] = "F";
	playground[2][2] = "G";
	playground[2][3] = "H";
	playground[2][4] = "I";
	playground[3][0] = "J";
	playground[3][1] = "K";
	playground[3][2] = "L";
	playground[3][4] = "M";
	playground[3][5] = "N";
	playground[3][6] = "O";
	playground[4][2] = "P";
	playground[4][3] = "Q";
	playground[4][4] = "R";
	playground[5][1] = "S";
	playground[5][5] = "T";
	playground[6][0] = "U";
	playground[6][6] = "V";
	winner = "";

}
void playground3::showboard()
{
printf("\n\n");
	cout << "\t\t\t " << playground[0][0] << " _____________________ " << playground[0][3] << " _____________________ " << playground[0][6] << " \n";
	cout<<"\t\t\t | \\\t\t\t |\t\t       / |"<<endl;
	cout<<"\t\t\t |   \\\t\t\t |\t\t     /   |"<<endl;
	cout << "\t\t\t |  \t " << playground[1][1] << "______________ " << playground[1][3] << " _____________ " << playground[1][5] << "\t | \n";
	cout<<"\t\t\t |\t | \\\t\t |\t       / |\t |"<<endl;
	cout<<"\t\t\t |\t |   \\\t\t |\t     /   |\t |"<<endl;
	cout << "\t\t\t |\t |\t " << playground[2][2] << " _____ " << playground[2][3] <<" _____ " << playground[2][4] << "\t | \t | \n";
	cout<<"\t\t\t |\t |\t | \t\t | \t | \t |"<<endl;
	cout << "\t\t\t " << playground[3][0] << " _____ " << playground[3][1] <<" _____ "<< playground[3][2] << "\t \t " << playground[3][4] << " _____ " << playground[3][5] << " _____ " << playground[3][6] << "\n";
	cout<<"\t\t\t |\t |\t | \t\t | \t | \t |"<<endl;
	cout << "\t\t\t |\t |\t " << playground[4][2] << " _____ " << playground[4][3] << " _____ " << playground[4][4] << "\t | \t |\n";
        cout<<"\t\t\t |\t |   /\t\t\t     \\   |\t |"<<endl;
	cout<<"\t\t\t |\t | /\t\t\t       \\ |\t |"<<endl;
	cout << "\t\t\t |\t " << playground[5][1] << " _____________________________ " << playground[5][5] << "\t | \n";
	cout<<"\t\t\t |    /\t\t\t\t\t    \\    |"<<endl;
	cout<<"\t\t\t |  /\t\t\t\t\t      \\  |"<<endl;
	cout << "\t\t\t " << playground[6][0] << " ______________________________________________" << playground[6][6] << "\t |\n";
}

bool playground3::gameover()
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
	{
		winner = playground[0][0];
		return true;
	}
	else if (playground[1][1] == playground[1][3] && playground[1][3] == playground[1][5])
	{
		winner = playground[1][1];
		return true;
	}
	else if (playground[2][2] == playground[2][3] && playground[2][3] == playground[2][4])
	{
		winner = playground[2][2];
		return true;
	}
	else if (playground[3][0] == playground[3][1] && playground[3][1] == playground[3][2])
	{
		winner = playground[3][0];
		return true;
	}
	else if (playground[3][4] == playground[3][5] && playground[3][5] == playground[3][6])
	{
		winner = playground[3][4];
		return true;
	}
	else if (playground[4][2] == playground[4][3] && playground[4][3] == playground[4][4])
	{
		winner = playground[4][2];
		return true;
	}

	return(false);
}

bool playground3::columncrossed()
{
	if (playground[0][0] == playground[3][0] && playground[3][0] == playground[6][0])
	{
		winner = playground[0][0];
		return true;
	}
	else if (playground[1][1] == playground[3][1] && playground[3][1] == playground[5][1])
	{
		winner = playground[1][1];
		return true;
	}
	else if (playground[2][2] == playground[3][2] && playground[3][2] == playground[4][2])
	{
		winner = playground[2][2];
		return true;
	}
	else if (playground[0][3] == playground[1][3] && playground[1][3] == playground[2][3])
	{
		winner = playground[0][3];
		return true;
	}
	else if (playground[2][4] == playground[3][4] && playground[3][4] == playground[4][4])
	{
		winner = playground[2][4];
		return true;
	}
	else if (playground[1][5] == playground[3][5] && playground[3][5] == playground[5][5])
	{
		winner = playground[1][5];
		return true;
	}
	else if (playground[0][6] == playground[3][6] && playground[3][6] == playground[6][6])
	{
		winner = playground[0][6];
		return true;
	}
	return(false);
}
bool playground3::diagonalcrossed() {

	if (playground[0][0] == playground[1][1] && playground[1][1] == playground[2][2])
	{
		winner = playground[0][0];
		return true;
	}
	if (playground[0][6] == playground[1][5] && playground[1][5] == playground[2][4])
	{
		winner = playground[0][6];
		return true;
	}
	if (playground[4][2] == playground[5][1] && playground[5][1] == playground[6][3])
	{
		winner = playground[4][2];
		return true;
	}
	if (playground[4][4] == playground[5][5] && playground[5][5] == playground[6][6])
	{
		winner = playground[4][4];
		return true;
	}
	return false;
}
string playground3::getWinner()
{
	return winner;
}
