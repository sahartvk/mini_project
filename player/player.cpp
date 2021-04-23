#include "player.h"
#include<iostream>
#include<string>

using namespace std;

player::player()
{
	setOn();
}
void player::setId(string _id)
{
	id = _id;
}
void player::setOn()
{
	on_off = "online";
}
void player::setOff()
{
	on_off = "offline";
}
string player::getId()
{
	return id;
}
string player::getOn_Off()
{
	return on_off;
}
