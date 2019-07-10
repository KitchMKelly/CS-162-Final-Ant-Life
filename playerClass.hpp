/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/19/2019
** Description: playerClass.hpp is the Player class specification file.
**	Player class used by Menu class to implement leaderboard functionality.
******************************************************************************/
#ifndef PLAYER_CLASS
#define PLAYER_CLASS
#include <string>
using std::string;

class Player
{
private:
	string name;
	int points;
public:
	Player(string nameIn, int pointsIn);
	void setName(string nameIn);
	string getName();
	void setPoints(int pointsIn);
	int getPoints();
};
#endif
