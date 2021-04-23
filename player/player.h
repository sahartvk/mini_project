#include<iostream>
#include<string>
using namespace std;

class player
{
public:
	player();
	void setId(std::string _id);
	void setOn();
	void setOff();
	std::string getId();
	std::string getOn_Off();
private:
	std::string id;
	std::string on_off;
};
