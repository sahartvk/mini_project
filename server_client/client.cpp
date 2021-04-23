#include<iostream>
#include<boost/asio.hpp>
#include"playground1.h"
#include"playground2.h"
#include"playground3.h"
#include"playground4.h"
#include"playground5.h"

#include<conio.h>
#include<thread>
#include<chrono>
#include<stdlib.h>
#include<dos.h> 

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
int turn;
using namespace std;
using namespace boost::asio;
using namespace ip;
void show_name();
void connection();
void chooseGroundOrNot(tcp::socket& sock);
void chooseGround(tcp::socket& sock);
void ground(tcp::socket& sock);
void enterid(tcp::socket& sock);
template<typename PlayGround>
void game(tcp::socket& sock, PlayGround pg);
void timer(string& n);

int main()
{	
	show_name();
	connection();
}
void show_name() {
	cout << ANSI_COLOR_YELLOW "\n\n\t   .--.      .--.    .-''-.    .---.        _______      ,-----.    ,---.    ,---.    .-''-.   " << endl;
	cout << "\t   |  |_     |  |  .'_ _   \\   | ,_|       /   __  \\   .'  .-,  '.  |    \\  /    |  .'_ _   \\  " << endl;
	cout << "\t   | _( )_   |  | / ( ` )   ',-./  )      | ,_/  \\__) / ,-.|  \\ _ \\ |  ,  \\/  ,  | / ( ` )   ' " << endl;
	cout << "\t   |(_ o _)  |  |. (_ o _)  |\\  '_ '`)  ,-./  )      ;  \\  '_ /  | :|  |\\_   /|  |. (_ o _)  | " << endl;
	cout << "\t   | (_,_) \\ |  ||  (_,_)___| > (_)  )  \\  '_ '`)    |  _`,/ \\ _/  ||  _( )_/ |  ||  (_,_)___| " << endl;
	cout << "\t   |  |/    \\|  |'  \\   .---.(  .  .-'   > (_)  )  __: (  '\\_/ \\   ;| (_ o _) |  |'  \\   .---. " << endl;
	cout<<"\t   |  '  /\\  `  | \\  `-'    / `-'`-'|___(  .  .-'_/  )\\ `  / \\  ) / |  (_, _) |  | \\  `-'    / "<<endl;
	cout<<"\t   |    /  \\    |  \\       /   |        \\`-'`-'     /  '. \\_/``.'   |  |      |  |  \\       /  "<<endl;
	cout << "\t   `---'    `---`   `'-..-'    `--------`  `._____.'     '-----'    '--'      '--'   `'-..-'   " << endl;

	cout << "\n\n";
	cout << ANSI_COLOR_CYAN"\t\t\t  _   _                _                       _             " << endl;
	cout << "\t\t\t | |_(_) ___          | |_ ___   ___          | |_ ___   ___ " << endl;
	cout << "\t\t\t | __| |/ __|         | __/ _ \\ / __|         | __/ _ \\ / _ \\" << endl;
	cout << "\t\t\t | |_| | (__          | || (_) | (__          | || (_) |  __/" << endl;
	cout << "\t\t\t  \\__|_|\\___|  _____   \\__\\___/ \\___|  _____   \\__\\___/ \\___|" << endl;
	cout << "\t\t\t              |_____|                 |_____|                " << endl;
	_getch();
	system("cls");
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
	//system("Color D");
	string ID;
	cout << ANSI_COLOR_CYAN "enter Your ID: " << endl;
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
		cout << ANSI_COLOR_YELLOW " \twait for other client to choose the ground!\n";
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
		cout <<ANSI_COLOR_GREEN "\t\t\t\t choose one of the grounds below:\n";
		cout << ANSI_COLOR_YELLOW "1.playground1\n2.playground2\n3.playground3\n4.playground4\n5.playground5\n";
		cin >> pg;
		if (!(pg == "1" || pg == "playground1" || pg == "2" || pg == "playground2" || pg == "playground3" || pg == "3" || pg == "4" || pg == "playground4" || pg == "5" || pg == "playground5"))
		{
			stop = false;
			cout << ANSI_COLOR_RED "Invalid play ground, press any key to try again\n";
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
	system("cls");
	cout <<ANSI_COLOR_GREEN "play ground: " << g << endl;
	cout << "the game will start in 5 seconds!\n";
	this_thread::sleep_for(std::chrono::seconds(2));
	//sleep
	
	for (int i = 5; i != 0; i--)
	{
		
		system("cls");
		cout << "\n\n\n\n\n\n";	
		cout <<ANSI_COLOR_MAGENTA "\t\t\t\t " << i << endl;
		cout << ANSI_COLOR_YELLOW "\t\t\t\t___" << endl;
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
	else if (g == "4" || g == "playground4")
	{
		playground4 pg;
		game(sock, pg);
	}
	else if (g == "5" || g == "playground5")
	{
		playground5 pg;
		game(sock, pg);
	}
}

template<typename PlayGround>
void game(tcp::socket& sock, PlayGround pg)
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
	bool timer_finish = false;
	string time_loser = "";

	while (pg.gameover() == false && timer_finish == false)
	{
		int i;

		if (turn == 1)
		{
			bool push = false;
			//i
			n = "";
			thread _timer(timer, ref(n));
			for (i = 1; i <= 20; i++)
			{
				pg.showboard();
				cout << ANSI_COLOR_MAGENTA "\nyour turn, enter one of the characters:\n\n";
				//change ground
				push = pg.push_back(n, me);
				if (push == true)
				{
					_timer.detach();
					_timer.~thread();
					break;
				}
				//cout << "\t\t__\n";
				cout <<ANSI_COLOR_RED "\t\t\t\t" << i << endl;
				cout << ANSI_COLOR_MAGENTA"\t\t\t\t__" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				system("cls");

			}
			if (push == false)
			{
				_timer.detach();
				_timer.~thread();
			}

			if (i < 20)
			{
				n += "\n";
				write(sock, boost::asio::buffer(n));
			}
			else
			{
				n = "i==20\n";
				write(sock, boost::asio::buffer(n));
				timer_finish = true;
				time_loser = me;
			}
		}
		else if (turn == 2)
		{

			pg.showboard();
			boost::asio::streambuf buff1;
			cout << ANSI_COLOR_YELLOW "wait!\n";
			read_until(sock, buff1, "\n");
			//change
			n = buffer_cast<const char*>(buff1.data());
			n = n.substr(0, n.size() - 1);
			if (n == "i==20")
				timer_finish = true;
			else
				pg.push_back(n, competitor);

		}
		system("cls");
		if (pg.gameover() == true || timer_finish == true)
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
		cout << "\n  Congratulation! you win :)" << endl;
	}
	else if (pg.getWinner() == competitor) {
		system("Color C");
		cout << "\n YOU LOST :(" << endl;
	}
	else if (timer_finish == true)
	{
		if (time_loser == "")
		{
			system("Color 2");
			cout << "\n Congratulation! you won :)" << endl;
		}
		else if (time_loser == me)
		{
			system("Color C");
			cout << "\n time is up!  YOU LOST :(" << endl;
		}
	}
	else {
		system("Color B");
		cout << "\n No winner!" << endl;
	}
	cout << "\n\npress any key to exit!" << endl;
	_getch();
	//exit

	system("cls");

}
void timer(string& n)
{
	while (1)
	{
		cin >> n;
		this_thread::sleep_for(std::chrono::seconds(1));
	}
}
