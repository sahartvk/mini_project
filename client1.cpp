#include<iostream>
#include<boost/asio.hpp>
#include"playground2.h"
#include"playground1.h"
#include"playground3.h"
#include"player.h"
#include<conio.h>
#include<thread>
#include<chrono>

int turn;
using namespace std;
using namespace boost::asio;
using namespace ip;

void connection(player p1);
void chooseGroundOrNot(tcp::socket& sock,player p1);
void chooseGround(tcp::socket& sock);
void ground(tcp::socket& sock,player p1);
void enterid(tcp::socket& sock , player p1);
template<typename PlayGround>
void game(tcp::socket& sock, PlayGround pg , player p1);

int main()
{	
	player p1;
	connection(p1);
	p1.setOff();
}
void connection(player p1)
{
	io_service io;
	tcp::socket sock(io);
	sock.connect(tcp::endpoint(address::from_string("127.0.0.1"), 1234));
	enterid(sock,p1);
	
	//-----------------

	chooseGroundOrNot(sock,p1);

}
void enterid(tcp::socket& sock,player p1) {
	string ID;
	cout << "enter Your ID:" << endl;
	cin >> ID;
	ID += "\n";
	write(sock, boost::asio::buffer(ID));
	p1.setId(ID);
	p1.setOn();
}
void chooseGroundOrNot(tcp::socket& sock,player p1)
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

	ground(sock,p1);
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
void ground(tcp::socket& sock,player p1)
{
	string g;
	boost::asio::streambuf buff;
	read_until(sock, buff, "\n");
	g = buffer_cast<const char*>(buff.data());
	g = g.substr(0, g.size() - 1);

	cout << "play ground: " << g << endl;
	cout << "the game will start in 5 seconds!";
	//sleep

	for (int i = 5; i != 0; i--)
	{
		system("cls");
		cout << "\t\t___" << endl;
		cout << "\t\t " << i << endl;
		cout << "\t\t___" << endl;
		this_thread::sleep_for(std::chrono::seconds(1));
	}
	system("cls");

	if (g == "1" || g == "playground1")
	{
		playground1 pg;
		game(sock, pg,p1);
	}
	else if (g == "2" || g == "playground2")
	{
		playground2 pg;
		game(sock, pg,p1);
	}
	else if (g == "3" || g == "playground3")
	{
		playground3 pg;
		game(sock, pg,p1);
	}
}

template<typename PlayGround>
void game(tcp::socket& sock, PlayGround pg,player p1)
{
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
		if (pg.gameover() == true) {
			write(sock, boost::asio::buffer("true\n"));
			//win is private if it was public it was ok

			/*if (pg.win() == true)        
				cout <<"Congratulation ! "<< p1.getId() << " Win" << endl;
			if (pg.win() == false)
				cout << p1.getId() << " Lost" << endl << "GAME OVER" << endl;*/
		}
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
