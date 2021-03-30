#include<iostream>
#include<string>
using namespace std;

class playground1
{
public:
	playground1();
	void showboard(char[][7]);
	bool gameover(char[][7]);
	bool win();
	bool push_back(char n, char m);
	bool rowcrossed(char[][7]);
	bool columncrossed(char[][7]);
	
private:
	string name;
	char playground[7][7];
	int leftMoves();
};
playground1::playground1()
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			playground[i][j] = '-1';
	playground[0][0] = '1';
	playground[0][3] = '2';
	playground[0][6] = '3';
	playground[1][1] = '4';
	playground[1][3] = '5';
	playground[1][5] = '6';
	playground[2][2] = '7';
	playground[2][3] = '8';
	playground[2][4] = '9';
	playground[3][0] = '10';
	playground[3][1] = '11';
	playground[3][2] = '12';
	playground[3][4] = '13';
	playground[3][5] = '14';
	playground[3][6] = '15';
	playground[4][2] = '16';
	playground[4][3] = '17';
	playground[4][4] = '18';
	playground[5][1] = '19';
	playground[5][3] = '20';
	playground[5][5] = '21';
	playground[6][0] = '22';
	playground[6][3] = '23';
	playground[6][6] = '24';
}
void playground1::showboard(char playground[7][7])
{
	printf("\n\n");

	printf("\t\t\t %c\t\t\t %c \t\t\t %c \n\n", playground[0][0], playground[0][3], playground[0][6]);
	printf("\t\t\t\t %c\t\t %c \t\t %c \n\n", playground[1][1], playground[1][3], playground[1][5]);
	printf("\t\t\t\t\t %c\t %c \t %c \n\n", playground[2][2], playground[2][3], playground[2][4]);
	printf("\t\t\t %c\t%c\t %c\t \t  %c \t %c \t %c\n\n", playground[3][0], playground[3][1], playground[3][2], playground[3][4], playground[3][5], playground[3][6]);
	printf("\t\t\t\t\t %c\t %c \t %c \n\n", playground[4][2], playground[4][3], playground[4][4]);
	printf("\t\t\t\t %c\t\t %c \t\t %c \n\n", playground[5][1], playground[5][3], playground[5][5]);
	printf("\t\t\t %c\t\t\t %c \t\t\t %c \n", playground[6][0], playground[6][3], playground[6][6]);
	return;
}

bool playground1::gameover(char playground[][7])
{
	if (leftMoves() == 0)
		return true;

	return false;
}
bool playground1::win() {
	return(rowcrossed(playground) || columncrossed(playground));
}

int playground1::leftMoves()
{
	int leftmoves = 24;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			if (playground[i][j] == '*' || playground[i][j] == '#')
				leftmoves--;
		}
	return leftmoves;
}
bool playground1::push_back(char n, char m)
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
bool playground1::rowcrossed(char playground[][7])
{
	int star = 0, numsign = 0;
	for (int i = 0; i < 7; i++)
	{
		star = 0, numsign = 0;
		if (i == 2)
			continue;
		for (int j = 0; j < 7; j++)
			if (playground[i][j] == '*')
				star++;
			else if (playground[i][j] == '#')
				numsign++;
		if (star == 3 || numsign == 3)
			return true;
	}
	return(false);
}

bool playground1::columncrossed(char playground[][7])
{
	int star = 0, numsign = 0;
	for (int j = 0; j < 7; j++)
	{
		star = 0, numsign = 0;
		if (j == 2)
			continue;
		for (int i = 0; i < 7; i++)
			if (playground[i][j] == '*')
				star++;
			else if (playground[i][j] == '#')
				numsign++;
		if (star == 3 || numsign == 3)
			return true;
	}
	return(false);
}


