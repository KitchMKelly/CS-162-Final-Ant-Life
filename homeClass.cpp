/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: asphaltClass.cpp is the Asphalt class function implementation
**	file. Asphalt class inherits from Space class.
******************************************************************************/
#include "homeClass.hpp"

/******************************************************************************
*	Home::Home()
*	Constructor for the Home class.
*	Initially sets member pointers 'north', 'south', 'east', and 'west' to nullptr.
*	Member pointers will be connected to adjacent Space objects by the Ant object.
*	Sets xCoordinate and yCoordinate to input (shoud be equal to xCoordinate and
*	yCoordinate of the Ant).
*	Randomly generates the event number that determines the event that occurs in
*	this space, and randomly generates event numbers for unexplored adjacent spaces.
*	Randomly generates spaceType number that determines the derived class of
*	unexplored adjacent spaces.
******************************************************************************/
Home::Home(int xCoordIn, int yCoordIn)
{
	setNorth(nullptr);
	setSouth(nullptr);
	setEast(nullptr);
	setWest(nullptr);
	setXCoord(xCoordIn);
	setYCoord(yCoordIn);
	setSpaceTypeHere(0);
	setActionCompleted(false);
}

/******************************************************************************
*	Home::~Home
*	Default destructor for the Home class.
******************************************************************************/
Home::~Home() {}

/******************************************************************************
*	Home::action()
*	Action available to Ant when in the Home space.
*	Informs the player that they are dropping off food in their inventory at 
*	the nest. Point tallying in Ant::interpretAction
******************************************************************************/
int Home::action() 
{
	return 0;
}

/******************************************************************************
*	Home::displayIntro
*	Alerts the player to the type of space they are on when entering the Home space.
******************************************************************************/
void Home::displayIntro()
{
	cout << "\nThe comforting scent of the nest fills your senses. It's good to be home." << endl;
	cout << "If you have any food in my crop, you should probably deposit it here for your sisters to eat." << endl;
}