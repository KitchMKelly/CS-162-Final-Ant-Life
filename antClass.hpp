/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: antClass.hpp is the Ant class specification file.
**	Ant object represents the player's avatar in the game.
******************************************************************************/
#ifndef ANT_CLASS
#define ANT_CLASS
#include "asphaltClass.hpp"
#include "grassClass.hpp"
#include "homeClass.hpp"
#include "puddleClass.hpp"
#include <vector>
using std::vector;
class Ant
{
private:
	Space * currentLocation;
	Space * previousLocation;
	vector <Space*> locationMemory;
	bool isAlive;
	bool spokeWithButterfly;
	int xCoordinate;
	int yCoordinate;
	int currentThirst;
	const int MAX_THIRST = 10;
	const int ARRAY_SIZE = 5;
	int antInventory[5];
	int turnCounter;
	int currentPoints;
	bool doodleHuntEnding;
public:

	Ant();
	~Ant();

	void setCurrentLocation(Space * spaceIn);
	Space * getCurrentLocation();
	void setPreviousLocation(Space * spaceIn);
	Space * getPreviousLocation();
	vector <Space *> getLocationMemory();
	void setAlive(bool aliveIn);
	bool getAlive();
	void setSpokeWithButterfly(bool spokeIn);
	bool getSpokeWithButterfly();
	void setXCoord(int xCoordIn);
	int getXCoord();
	void setYCoord(int yCoordIn);
	int getYCoord();
	bool setCurrentThirst(int thirstIn);
	int getCurrentThirst();
	int getMaxThirst();
	int getCurrentCrop();
	int getMaxCrop();
	void setTurnCounter(int turnIn);
	int getTurnCounter();
	string getTimeOfDay();
	void setCurrentPoints(int pointsIn);
	int getCurrentPoints();
	void setDoodleHuntEnding(bool huntIn);
	bool getDoodleHuntEnding();

	void move(int directionIn);
	void blown(int xCoord, int yCoord);
	void connect();
	void addToMemory(Space *locationIn);
	bool haveIBeenHere();
	bool addFood(int foodIn);
	bool giveMeat();
	void smell();
	bool isDigits(string &str);
	int menuChoice(string &userInput, int numberMenuOptions);
	void determineEventHere();
	void eventSwitch();
	void determineAdjacentSpaceTypes(Space * location);
	void interpretAction(int resultIn);
	void displayDoodleEnding();
};
#endif