#include<iostream>
#include<boost/asio.hpp>
#include"playground2.h"
#include"playground1.h"
#include"playground3.h"
#include<conio.h>
#include<thread>
#include<chrono>

using namespace std;
using namespace boost::asio;
using namespace ip;

void chooseGround(tcp::socket& sock);
void ground(tcp::socket& sock);
void game(tcp::socket& sock, playground2 pg);
void game(tcp::socket& sock, playground1 pg);
void game(tcp::socket& sock, playground3 pg);

int main()
{
	io_service io2;
	tcp::socket sock2(io2);
	sock2.connect(tcp::endpoint(address::from_string("127.0.0.1"), 1234));

	//-----------------
	boost::asio::streambuf buff1, buff2;
	read_until(sock2, buff1, "\n");
	string msg = buffer_cast<const char*>(buff1.data());
	if (msg == "true\n")
		chooseGround(sock2);
	else
		cout << "wait for other client to choose the ground!\n";

	ground(sock2);
}
void chooseGround(tcp::socket& sock)
{
	string pg;
	bool stop = true;
	do
	{
		stop = true;
		cout << "choose one of the grounds below:\n";
		cout << "1.playground1\n2.playgroung2\n3.playgrond3\n";
		cin >> pg;
		if (!(pg == "1" || pg == "playground1" || pg == "2" || pg == "playgroung2" || pg == "playgrond3" || pg == "3"))
		{
			stop = false;
			cout << "Invalid play ground, press any ket to try again\n";
			char m=_getch();
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
void game(tcp::socket& sock, playground2 pg)
{
	string n, msg;
	boost::asio::streambuf buff;
	int turn = 2;
	//recieve turn from server
	//read_until(sock, buff, "\n");
	//msg = buffer_cast<const char*>(buff.data());
	//msg = msg.substr(0, msg.size() - 1);
	//turn = stoi(msg);

	while (pg.gameover() == false)
	{
		pg.showboard();
		bool push = false;
		if (turn == 1)
		{
			do {

				cout << "Your turn, enter one of the numbers:\n";
				cin >> n;
				//change grround
				push = pg.push_back(n, "#");

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
			pg.push_back(n, "*");

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
	cout << "press any key to exit!";
	_getch();
	//exit
	system("cls");

}
void game(tcp::socket& sock, playground1 pg)
{
	string n, msg;
	boost::asio::streambuf buff;
	int turn = 2;
	//recieve turn from server
	//read_until(sock, buff, "\n");
	//msg = buffer_cast<const char*>(buff.data());
	//msg = msg.substr(0, msg.size() - 1);
	//turn = stoi(msg);

	while (pg.gameover() == false)
	{
		pg.showboard();
		bool push = false;
		if (turn == 1)
		{
			do {

				cout << "Your turn, enter one of the numbers:\n";
				cin >> n;
				//change grround
				push = pg.push_back(n, "#");

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
			pg.push_back(n, "*");

		}
		system("cls");
		if (pg.gameover() == true)
			write(sock, boost::asio::buffer("true\n"));
		else if (pg.gameover() == false)
			write(sock, boost::asio::buffer("false\n"));
		if (turn == 1)
			turn = 2;
		else if(turn==2)
			turn = 1;

	}
	pg.showboard();
	cout << "press any key to exit!";
	_getch();
	//exit
	system("cls");

}
void game(tcp::socket& sock, playground3 pg)
{
	string n, msg;
	boost::asio::streambuf buff;
	int turn = 2;
	//recieve turn from server
	//read_until(sock, buff, "\n");
	//msg = buffer_cast<const char*>(buff.data());
	//msg = msg.substr(0, msg.size() - 1);
	//turn = stoi(msg);

	while (pg.gameover() == false)
	{
		pg.showboard();
		bool push = false;
		if (turn == 1)
		{
			do {

				cout << "Your turn, enter one of the numbers:\n";
				cin >> n;
				//change grround
				push = pg.push_back(n, "#");

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
			pg.push_back(n, "*");

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
	cout << "press any key to exit!";
	_getch();
	//exit
	system("cls");

}