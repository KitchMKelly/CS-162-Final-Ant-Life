/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: spaceClass.hpp is the Space class specification file.
**	Space class is the parent class of the Puddle, Grass, and Asphalt classes.
**	This is an abstract class, so only getters/setters defined here.
******************************************************************************/
#ifndef SPACE_CLASS
#define SPACE_CLASS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Space
{
private:
	Space * north;
	Space * south;
	Space * east;
	Space * west;
	int eventHere;
	int spaceTypeHere;
	int spaceTypeNorth;
	int spaceTypeSouth;
	int spaceTypeEast;
	int spaceTypeWest;
	int xCoordinate;
	int yCoordinate;
	bool actionCompleted;
public:
	void setNorth(Space * northIn);
	Space * getNorth();
	void setSouth(Space * southIn);
	Space * getSouth();
	void setEast(Space * eastIn);
	Space * getEast();
	void setWest(Space * westIn);
	Space * getWest();
	void setEventHere(int eventIn);
	int getEventHere();
	void setSpaceTypeHere(int spaceTypeIn);
	int getSpaceTypeHere();
	void setSpaceTypeNorth(int spaceTypeIn);
	int getSpaceTypeNorth();
	void setSpaceTypeSouth(int spaceTypeIn);
	int getSpaceTypeSouth();
	void setSpaceTypeEast(int spaceTypeIn);
	int getSpaceTypeEast();
	void setSpaceTypeWest(int spaceTypeIn);
	int getSpaceTypeWest();
	void setXCoord(int xCoordIn);
	int getXCoord();
	void setYCoord(int yCoordIn);
	int getYCoord();
	void setActionCompleted(bool completedIn);
	bool getActionCompleted();

	virtual int action() = 0;
	virtual void displayIntro() = 0;
};

#endif