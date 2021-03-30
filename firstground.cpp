#include<iostream>
#include<string>
using namespace std;

class playground1
{
public:
	playground1();
	void showboard(char[][3]);
	bool gameover(char[][3]);
	bool win();
	bool push_back(char n, char m);
	bool rowcrossed(char[][3]);
	bool columncrossed(char[][3]);
	bool diagonalcrossed(char[][3]);
private:
	string name;
	char playground[3][3];
	int leftMoves();
};
playground1::playground1()
{
	playground[0][0] = '1';
	playground[0][1] = '2';
	playground[0][2] = '3';
	playground[1][0] = '4';
	playground[1][1] = '5';
	playground[1][2] = '6';
	playground[2][0] = '7';
	playground[2][1] = '8';
	playground[2][2] = '9';
}
void playground1::showboard(char playground[3][3])
{
	printf("\n\n");

	printf("\t\t\t %c | %c | %c \n", playground[0][0],
		playground[0][1], playground[0][2]);
	printf("\t\t\t--------------\n");
	printf("\t\t\t %c | %c | %c \n", playground[1][0],
		playground[1][1], playground[1][2]);
	printf("\t\t\t--------------\n");
	printf("\t\t\t %c | %c | %c \n\n", playground[2][0],
		playground[2][1], playground[2][2]);

	return;
}

bool playground1::gameover(char playground[][3])
{
	if (leftMoves() == 0)
		return true;

	return false;
}
bool playground1::win() {
	return(rowcrossed(playground) || columncrossed(playground) || diagonalcrossed(playground));
}

int playground1::leftMoves()
{
	int leftmoves = 9;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (playground[i][j] == '*' || playground[i][j] == '#')
				leftmoves--;
		}
	return leftmoves;
}
bool playground1::push_back(char n, char m)
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
bool playground1::rowcrossed(char playground[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (playground[i][0] == playground[i][1] && playground[i][1] == playground[i][2] && playground[i][0] != ' ')
			return (true);
	}
	return(false);
}

bool playground1:: columncrossed(char playground[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (playground[0][i] == playground[1][i] && playground[1][i] == playground[2][i] && playground[0][i] != ' ')
			return (true);
	}
	return(false);
}

bool playground1::diagonalcrossed(char playground[][3])
{
	if (playground[0][0] == playground[1][1] && playground[1][1] == playground[2][2] && playground[0][0] != ' ')
		return(true);

	if (playground[0][2] == playground[1][1] && playground[1][1] == playground[2][0] && playground[0][2] != ' ')
		return(true);

	return(false);
}
