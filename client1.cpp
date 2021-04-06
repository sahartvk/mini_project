#include<iostream>
#include<boost/asio.hpp>
#include"playground2.h"
#include"playground1.h"
#include"playground3.h"
#include"player.h"
#include<conio.h>
#include<thread>
#include<chrono>
#include<stdlib.h>

int turn;
using namespace std;
using namespace boost::asio;
using namespace ip;

void connection();
void chooseGroundOrNot(tcp::socket& sock);
void chooseGround(tcp::socket& sock);
void ground(tcp::socket& sock);
void enterid(tcp::socket& sock);
template<typename PlayGround>
void game(tcp::socket& sock, PlayGround pg);

int main()
{	
	connection();
}
void connection()
{
	io_service io;
	tcp::socket sock(io);
	sock.connect(tcp::endpoint(address::from_string("127.0.0.1"), 1234));
	enterid(sock);
	chooseGroundOrNot(sock);

}
void enterid(tcp::socket& sock) {
	system("Color D");
	string ID;
	cout << "enter Your ID:" << endl;
	cin >> ID;
	ID += "\n";
	write(sock, boost::asio::buffer(ID));
	
}
void chooseGroundOrNot(tcp::socket& sock)
{
	boost::asio::streambuf buff;
	read_until(sock, buff, "\n");
	string msg = buffer_cast<const char*>(buff.data());
	if (msg == "true\n")
	{
		chooseGround(sock);
		turn = 1;
	}
	else
	{
		cout << "wait for other client to choose the ground!\n";
		turn = 2;
	}

	ground(sock);
}
void chooseGround(tcp::socket& sock)
{
	string pg;
	bool stop = true;
	do
	{
		stop = true;
		cout << "choose one of the grounds below:\n";
		cout << "1.playground1\n2.playground2\n3.playground3\n";
		cin >> pg;
		if (!(pg == "1" || pg == "playground1" || pg == "2" || pg == "playground2" || pg == "playground3" || pg == "3"))
		{
			stop = false;
			cout << "Invalid play ground, press any ket to try again\n";
			char m = _getch();
			system("cls");
		}
	} while (!stop);
	pg += "\n";
	write(sock, boost::asio::buffer(pg));
	system("cls");
}
void ground(tcp::socket& sock)
{
	string g;
	boost::asio::streambuf buff;
	read_until(sock, buff, "\n");
	g = buffer_cast<const char*>(buff.data());
	g = g.substr(0, g.size() - 1);

	cout << "play ground: " << g << endl;
	cout << "the game will start in 5 seconds!";
	//sleep
	system("cls");

	for (int i = 5; i != 0; i--)
	{
		system("Color B");
		system("cls");
		cout << "\n\n\n\n\n\n";	
		cout << "\t\t\t\t " << i << endl;
		cout << "\t\t\t\t___" << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
	}
	system("cls");

	if (g == "1" || g == "playground1")
	{
		playground1 pg;
		game(sock, pg);
	}
	else if (g == "2" || g == "playground2")
	{
		playground2 pg;
		game(sock, pg);
	}
	else if (g == "3" || g == "playground3")
	{
		playground3 pg;
		game(sock, pg);
	}
}

template<typename PlayGround>
void game(tcp::socket& sock, PlayGround pg)
{
	system("Color 6");
	string n, msg;
	boost::asio::streambuf buff;

	string me, competitor;
	if (turn == 1)
	{
		me = "*";
		competitor = "#";
	}
	else
	{
		me = "#";
		competitor = "*";
	}

	while (pg.gameover() == false)
	{
		pg.showboard();

		if (turn == 1)
		{
			bool push = false;
			do {

				cout << "your turn, enter one of the characters:\n";
				cin >> n;
				//change grround
				push = pg.push_back(n, me);

			} while (!push);

			n += "\n";
			write(sock, boost::asio::buffer(n));
		}
		else if (turn == 2)
		{
			boost::asio::streambuf buff1;
			cout << "wait!\n";
			read_until(sock, buff1, "\n");
			//change
			n = buffer_cast<const char*>(buff1.data());
			n = n.substr(0, n.size() - 1);
			pg.push_back(n, competitor);

		}
		system("cls");
		if (pg.gameover() == true)
			write(sock, boost::asio::buffer("true\n"));
		else if (pg.gameover() == false)
			write(sock, boost::asio::buffer("false\n"));
		if (turn == 1)
			turn = 2;
		else if (turn == 2)
			turn = 1;

	}
	pg.showboard();
	
	if (pg.getWinner() == me) {
		system("Color 2");
		cout << "Congratulation! you win :)" << endl;
	}
	else if (pg.getWinner() == competitor) {
		system("Color C");
		cout <<  "GAME OVER :(" << endl;
	}
	else {
		system("Color B");
		cout << "No winner!" << endl;
	}
	cout << "\n\npress any key to exit!" << endl;
	_getch();
	//exit

	system("cls");

}