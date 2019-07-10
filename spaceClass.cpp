/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: spaceClass.cpp is the Space class function implementation
**	file. Space class is the parent class of the Puddle, Grass, and Asphalt classes.
**	This is an abstract class, so only getters/setters defined here.
******************************************************************************/
#include "spaceClass.hpp"

/******************************************************************************
*	Space::setNorth
*	Sets the member pointer 'north' to input.
******************************************************************************/
void Space::setNorth(Space * northIn)
{
	north = northIn;
}

/******************************************************************************
*	Space::getNorth
*	Returns the member pointer 'north'.
******************************************************************************/
Space * Space::getNorth()
{
	return north;
}

/******************************************************************************
*	Space::setSouth
*	Sets the member pointer 'south' to input.
******************************************************************************/
void Space::setSouth(Space * southIn)
{
	south = southIn;
}

/******************************************************************************
*	Space::getSouth
*	Returns the member pointer 'south'.
******************************************************************************/
Space * Space::getSouth()
{
	return south;
}

/******************************************************************************
*	Space::setEast
*	Sets the member pointer 'east' to input.
******************************************************************************/
void Space::setEast(Space * eastIn)
{
	east = eastIn;
}

/******************************************************************************
*	Space::getEast
*	Returns the member pointer 'east'.
******************************************************************************/
Space * Space::getEast()
{
	return east;
}

/******************************************************************************
*	Space::setWest
*	Sets the member pointer 'west' to input.
******************************************************************************/
void Space::setWest(Space * westIn)
{
	west = westIn;
}

/******************************************************************************
*	Space::getWest
*	Returns the member pointer 'west'.
******************************************************************************/
Space * Space::getWest()
{
	return west;
}

/******************************************************************************
*	Space::setEventHere
*	Sets the value of the member integer 'eventHere' to input.
******************************************************************************/
void Space::setEventHere(int eventIn)
{
	eventHere = eventIn;
}

/******************************************************************************
*	Space::getEventHere
*	Returns the value of the member integer 'eventHere'.
******************************************************************************/
int Space::getEventHere()
{
	return eventHere;
}

/******************************************************************************
*	Space::setSpaceTypeHere
*	Sets the value of the member integer 'spaceTypeHere' to input.
******************************************************************************/
void Space::setSpaceTypeHere(int spaceTypeIn)
{
	spaceTypeHere = spaceTypeIn;
}

/******************************************************************************
*	Space::getSpaceTypeHere
*	Returns the value of the member integer 'spaceTypeHere'.
******************************************************************************/
int Space::getSpaceTypeHere()
{
	return spaceTypeHere;
}

/******************************************************************************
*	Space::setSpaceTypeNorth
*	Sets the value of the member integer 'spaceTypeNorth' to input.
******************************************************************************/
void Space::setSpaceTypeNorth(int spaceTypeIn)
{
	spaceTypeNorth = spaceTypeIn;
}

/******************************************************************************
*	Space::getSpaceTypeNorth
*	Returns the value of the member integer 'spaceTypeNorth'.
******************************************************************************/
int Space::getSpaceTypeNorth()
{
	return spaceTypeNorth;
}

/******************************************************************************
*	Space::setSpaceTypeSouth
*	Sets the value of the member integer 'spaceTypeSouth' to input.
******************************************************************************/
void Space::setSpaceTypeSouth(int spaceTypeIn)
{
	spaceTypeSouth = spaceTypeIn;
}

/******************************************************************************
*	Space::getSpaceTypeSouth
*	Returns the value of the member integer 'spaceTypeSouth'.
******************************************************************************/
int Space::getSpaceTypeSouth()
{
	return spaceTypeSouth;
}

/******************************************************************************
*	Space::setSpaceTypeEast
*	Sets the value of the member integer 'spaceTypeEast' to input.
******************************************************************************/
void Space::setSpaceTypeEast(int spaceTypeIn)
{
	spaceTypeEast = spaceTypeIn;
}

/******************************************************************************
*	Space::getSpaceTypeEast
*	Returns the value of the member integer 'spaceTypeEast'.
******************************************************************************/
int Space::getSpaceTypeEast()
{
	return spaceTypeEast;
}

/******************************************************************************
*	Space::setSpaceTypeWest
*	Sets the value of the member integer 'spaceTypeWest' to input.
******************************************************************************/
void Space::setSpaceTypeWest(int spaceTypeIn)
{
	spaceTypeWest = spaceTypeIn;
}

/******************************************************************************
*	Space::getSpaceTypeWest
*	Returns the value of the member integer 'spaceTypeWest'.
******************************************************************************/
int Space::getSpaceTypeWest()
{
	return spaceTypeWest;
}

/******************************************************************************
*	Space::setXCoord
*	Sets the value of the member integer 'xCoordinate' to input.
******************************************************************************/
void Space::setXCoord(int xCoordIn)
{
	xCoordinate = xCoordIn;
}

/******************************************************************************
*	Space::getXCoord
*	Returns the value of the member integer 'xCoordinate'.
******************************************************************************/
int Space::getXCoord()
{
	return xCoordinate;
}

/******************************************************************************
*	Space::setYCoord
*	Sets the value of the member integer 'yCoordinate' to input.
******************************************************************************/
void Space::setYCoord(int yCoordIn)
{
	yCoordinate = yCoordIn;
}

/******************************************************************************
*	Space::getYCoord
*	Returns the value of the member integer 'yCoord'.
******************************************************************************/
int Space::getYCoord()
{
	return yCoordinate;
}

/******************************************************************************
*	Space::setActionCompleted
*	Sets the value of the member bool 'actionCompleted' to input.
******************************************************************************/
void Space::setActionCompleted(bool completedIn)
{
	actionCompleted = completedIn;
}

/******************************************************************************
*	Space::getActionCompleted
*	Returns the value of the member bool 'actionCompleted'.
******************************************************************************/
bool Space::getActionCompleted()
{
	return actionCompleted;
}