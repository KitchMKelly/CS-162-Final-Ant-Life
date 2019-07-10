/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: puddleClass.cpp is the Puddle class function implementation
**	file. Puddle class inherits from Space class.
******************************************************************************/
#include "puddleClass.hpp"

/******************************************************************************
*	Puddle::Puddle()
*	Constructor for the Puddle class.
*	Initially sets member pointers 'north', 'south', 'east', and 'west' to nullptr.
*	Member pointers will be connected to adjacent Space objects by the Ant object.
*	Sets xCoordinate and yCoordinate to input (shoud be equal to xCoordinate and
*	yCoordinate of the Ant).
*	Randomly generates the event number that determines the event that occurs in
*	this space, and randomly generates event numbers for unexplored adjacent spaces.
*	Randomly generates spaceType number that determines the derived class of
*	unexplored adjacent spaces.
******************************************************************************/
Puddle::Puddle(int xCoordIn, int yCoordIn)
{
	setNorth(nullptr);
	setSouth(nullptr);
	setEast(nullptr);
	setWest(nullptr);
	setXCoord(xCoordIn);
	setYCoord(yCoordIn);
	setSpaceTypeHere(3);
	setActionCompleted(false);
}

/******************************************************************************
*	Puddle::~Puddle
*	Default destructor for the Puddle class.
******************************************************************************/
Puddle::~Puddle() {}

/******************************************************************************
*	Puddle::action
*	Action available on to the player in puddle spaces.
*	Returns a random integer in range [2 .. 5] representing thirst recovered by
*	drinking from the puddle.
*	Thurst cannot exceed MAX_THURST = 20.
******************************************************************************/
int Puddle::action() 
{
	srand(time(0));
	if (getActionCompleted() == false)
	{
		cout << "\nYou drink the puddle dry. The water is cool and refreshing!" << endl;
		int drink = rand() % 4 + 2;
		cout << "You recover " << drink << " thirst." << endl;
		setActionCompleted(true);
		return drink;
	}
	else
	{
		cout << "\nThe puddle is gone. You drank it already." << endl;
		return 0;
	}
}

/******************************************************************************
*	Puddle::displayIntro()
*	Alerts the player to the type of space they are on when entering a Puddle space.
******************************************************************************/
void Puddle::displayIntro()
{
	if (getActionCompleted() == false)
		cout << "\nThere is a small puddle of fresh water here - just enough to quench your thirst." << endl;
	else
		cout << "\nThere is a small dark patch of dirt where the puddle used to be. Not enough to drink anymore." << endl;
}