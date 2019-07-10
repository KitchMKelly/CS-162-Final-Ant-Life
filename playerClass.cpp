/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/19/2019
** Description: playerClass.cpp is the Player class function implementation
**	file. Player class used by Menu class to implement leaderboard functionality.
******************************************************************************/
#include "playerClass.hpp"

/******************************************************************************
*	Player::Player
*	Constructor for the player class.
*	Accepts input to the member string 'name' and member variable 'points'.
******************************************************************************/
Player::Player(string nameIn, int pointsIn)
{
	setName(nameIn);
	setPoints(pointsIn);
}

/******************************************************************************
*	Player::setName
*	Sets the member string 'name' to input.
******************************************************************************/
void Player::setName(string nameIn)
{
	name = nameIn;
}

/******************************************************************************
*	Player::getName
*	Returns the member string 'name'.
******************************************************************************/
string Player::getName()
{
	return name;
}

/******************************************************************************
*	Player::setPoints
*	Sets the member variable 'points' to input.
******************************************************************************/
void Player::setPoints(int pointsIn)
{
	points = pointsIn;
}

/******************************************************************************
*	Player::getPoints
*	Returns the member variable 'points'.
******************************************************************************/
int Player::getPoints()
{
	return points;
}