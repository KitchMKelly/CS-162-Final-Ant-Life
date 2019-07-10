/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: grassClass.cpp is the Grass class function implementation
**	file. Grass class inherits from Space class.
******************************************************************************/
#include "grassClass.hpp"

/******************************************************************************
*	Grass::Grass()
*	Constructor for the Grass class.
*	Initially sets member pointers 'north', 'south', 'east', and 'west' to nullptr.
*	Member pointers will be connected to adjacent Space objects by the Ant object.
*	Sets xCoordinate and yCoordinate to input (shoud be equal to xCoordinate and
*	yCoordinate of the Ant).
*	Randomly generates the event number that determines the event that occurs in
*	this space, and randomly generates event numbers for unexplored adjacent spaces.
*	Randomly generates spaceType number that determines the derived class of
*	unexplored adjacent spaces.
******************************************************************************/
Grass::Grass(int xCoordIn, int yCoordIn)
{
	setNorth(nullptr);
	setSouth(nullptr);
	setEast(nullptr);
	setWest(nullptr);
	setXCoord(xCoordIn);
	setYCoord(yCoordIn);
	setSpaceTypeHere(2);
	setActionCompleted(false);
}

/******************************************************************************
*	Grass::~Grass
*	Default destructor for the Grass class.
******************************************************************************/
Grass::~Grass() {}

/******************************************************************************
*	Grass::action
*	Action available on to the player in grass spaces.
*	Returns either 1 or 0, signifying the point value the player gains in their crop from foraging.
*	1 = success, 0 = failure
*	50% chance to find fruit
******************************************************************************/
int Grass::action() 
{
	if (getActionCompleted() == false)
	{
		cout << "\nYou search the grass for something edible..." << endl;
		srand(time(0));
		int success = rand() % 2;
		if (success == 1)
		{
			cout << "You find a small amount of fruit in the tall grass." << endl;
			setActionCompleted(true);
			return 1;
		}
		
		if (success == 0)
		{
			cout << "You search the entire patch of tall grass here, but find nothing edible." << endl;
			setActionCompleted(true);
			return 0;
		}
	}
	else
	{
		cout << "\nYou've already searched this grass for something edible." << endl;
		return 0;
	}
}

/******************************************************************************
*	Grass::displayIntro
*	Alerts the player to the type of space they are on when entering a Grass space.
******************************************************************************/
void Grass::displayIntro()
{
	cout << "\nThe grass grows tall here." << endl;
	if (getActionCompleted() == false)
		cout << "If you're lucky, you may be able to find some fruit or seeds here." << endl;
	else
		cout << "You've already foraged here. You doubt you'll find anything else here." << endl;
}