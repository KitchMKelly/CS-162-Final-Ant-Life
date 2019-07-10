/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: asphaltClass.cpp is the Asphalt class function implementation
**	file. Asphalt class inherits from Space class.
******************************************************************************/
#include "asphaltClass.hpp"

/******************************************************************************
*	Asphalt::Asphalt()
*	Constructor for the Asphalt class.
*	Initially sets member pointers 'north', 'south', 'east', and 'west' to nullptr.
*	Member pointers will be connected to adjacent Space objects by the Ant object.
*	Sets xCoordinate and yCoordinate to input (shoud be equal to xCoordinate and
*	yCoordinate of the Ant).
*	Randomly generates the event number that determines the event that occurs in
*	this space, and randomly generates event numbers for unexplored adjacent spaces.
*	Randomly generates spaceType number that determines the derived class of 
*	unexplored adjacent spaces.
******************************************************************************/
Asphalt::Asphalt(int xCoordIn, int yCoordIn)
{
	setNorth(nullptr);
	setSouth(nullptr);
	setEast(nullptr);
	setWest(nullptr);
	setXCoord(xCoordIn);
	setYCoord(yCoordIn);
	setSpaceTypeHere(1);
	setActionCompleted(false);
}

/******************************************************************************
*	Asphalt::~Asphalt
*	Default destructor for the Asphalt class.
******************************************************************************/
Asphalt::~Asphalt() {}

/******************************************************************************
*	Asphalt::action
*	Action available on to the player in asphalt spaces.
*	Returns either 5 or 0, signifying the point value the player gains in their crop from foraging.
*	5 = success, 0 = failure
*	25% chance to find meat
******************************************************************************/
int Asphalt::action() 
{
	if (getActionCompleted() == false)
	{
		cout << "\nThe sun beats down on you as you search the rocky terrain for something edible." << endl;
		cout << "You lose an extra thirst..." << endl;
		srand(time(0));
		int success = rand() % 4;
		if (success == 3)
		{
			cout << "You find the remains of an insect among the rocks. Precious meat!" << endl;
			setActionCompleted(true);
			return 5;
		}

		else
		{
			cout << "You search this entire patch of rocky terrain, but find nothing edible." << endl;
			setActionCompleted(true);
			return 0;
		}
	}
	else
	{
		cout << "\nYou've already searched this rocky terrain for something edible." << endl;
		return 0;
	}
}

/******************************************************************************
*	Asphalt::displayIntro()
*	Alerts the player to the type of space they are on when entering an Asphalt space.
******************************************************************************/
void Asphalt::displayIntro()
{
	cout << "\nThe air is much warmer here, and the stony terrain stretches a far as the eye can see." << endl;
	if (getActionCompleted() == false)
	{
		cout << "The heat in this land has claimed the lives of many insects before you, including some of your more careless sisters." << endl;
		cout << "However, if you take care and make sure you don't become dehydrated, it may be worth the trouble to scavenge meat from the dead here." << endl;
	}
	else
		cout << "You've scavenged the rocks here already. There's nothing else here." << endl;
}