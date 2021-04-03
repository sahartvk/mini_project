#include<iostream>
#include<boost/asio.hpp>
#include<string>

using namespace std;
using namespace boost::asio;
using namespace ip;

string chooseGround(tcp::socket& sock);
void game(tcp::socket& sock1, tcp::socket& sock2);

int main()
{
	io_service io1, io2;
	tcp::socket sock1(io1);
	tcp::socket sock2(io2);
	tcp::acceptor acc1(io1,tcp::endpoint(tcp::v4(), 1234));
	tcp::acceptor acc2(io2, tcp::endpoint(tcp::v4(), 1234));
	acc1.accept(sock1);
	cout << "client1 is connected!\n";
	acc1.accept(sock2);
	cout << "client2 is connected!\n";

	//---------------------
	//id

	write(sock2, boost::asio::buffer("false\n"));
	write(sock1, boost::asio::buffer("true\n"));
	string pg = chooseGround(sock1);
	
	pg += "\n";
	write(sock1, boost::asio::buffer(pg));
	write(sock2, boost::asio::buffer(pg));

	game(sock1, sock2);

}
string chooseGround(tcp::socket& sock)
{
	boost::asio::streambuf buff;
	string pg;

	read_until(sock, buff, "\n");
	pg = buffer_cast<const char*>(buff.data());
	pg = pg.substr(0, pg.size() - 1);

	cout << "play ground " << pg << " is chosen\n";
	return pg;
}
void game(tcp::socket& sock1, tcp::socket& sock2)
{
	string msg,gameover="false\n";
	int turn = 1;
	//write(sock1, boost::asio::buffer("1\n"));
	//write(sock2, boost::asio::buffer("2\n"));


	while (gameover=="false\n")
	{
		boost::asio::streambuf buff1, buff2, bufGO1, bufGO2;
		if (turn==1)
		{
			read_until(sock1, buff1, "\n");
			msg = buffer_cast<const char*>(buff1.data());
			write(sock2, boost::asio::buffer(msg));
			turn = 2;

		}
		else if (turn==2)
		{
			read_until(sock2, buff2, "\n");
			msg = buffer_cast<const char*>(buff2.data());
			write(sock1, boost::asio::buffer(msg));
			turn = 1;
		}

		read_until(sock1, bufGO1, "\n");
		read_until(sock2, bufGO2, "\n");
		gameover = buffer_cast<const char*>(bufGO1.data());
	}
	cout << "game over!\n";
}