/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: antClass.cpp is the Ant class function implementation
**	file. Ant object represents the player's avatar in the game.
******************************************************************************/
#include "antClass.hpp"
#include "asphaltClass.hpp"
#include "grassClass.hpp"
#include "homeClass.hpp"
#include "puddleClass.hpp"

/******************************************************************************
*	Ant::Ant()
*	Default constructor for the ant class.
*	Sets initial X and Y coordinates to 0 and  sets initial thurst to maximum.
*	Creates a new Home space at point (0, 0) and adds that location to the
*	locationMemory vector (the Ant remembers where home is located).
*	Set Ant's current location to new Home space.
******************************************************************************/
Ant::Ant()
{
	cout << "\nThe sun rises on a beautiful morning." << endl;
	cout << "You know what they say, \"Another day, another chance to further the GLORY OF THE COLONY!\"" << endl;
	cout << "You'd better get started - or the Doodlebugs will catch you out after dark! And remember to stay hydrated!" << endl;
	
	setAlive(true);
	setSpokeWithButterfly(false);
	setDoodleHuntEnding(false);
	setXCoord(0);
	setYCoord(0);
	setCurrentThirst(MAX_THIRST);
	setTurnCounter(0);
	setCurrentPoints(0);
	Home * nest = new Home(0, 0);
	addToMemory(nest);
	setCurrentLocation(nest);
	determineAdjacentSpaceTypes(getCurrentLocation());
	determineEventHere();
	for (int i = 0; i < ARRAY_SIZE; ++i)
		antInventory[i] = 0;
}

/******************************************************************************
*	Ant::~Ant()
*	Default destructor for the ant class.
******************************************************************************/
Ant::~Ant()
{
	//Delete all spaces pointed to by pointers in locationMemory
	for (int i = 0; i < getLocationMemory().size(); ++i)
	{
		delete getLocationMemory().at(i);
		getLocationMemory().at(i) = nullptr;
	}
}

/******************************************************************************
*	Ant::setCurrentLocation
*	Sets the member pointer 'currentLocation' to input.
******************************************************************************/
void Ant::setCurrentLocation(Space * spaceIn)
{
	currentLocation = spaceIn;
}

/******************************************************************************
*	Ant::getCurrentLocation
*	Returns the member pointer 'currentLocation'.
******************************************************************************/
Space * Ant::getCurrentLocation()
{
	return currentLocation;
}

/******************************************************************************
*	Ant::setPreviousLocation
*	Sets the member pointer 'previousLocation' to input.
******************************************************************************/
void Ant::setPreviousLocation(Space * spaceIn)
{
	previousLocation = spaceIn;
}

/******************************************************************************
*	Ant::getPreviousLocation
*	Returns the member pointer 'previousLocation'.
******************************************************************************/
Space * Ant::getPreviousLocation()
{
	return previousLocation;
}

/******************************************************************************
*	Ant::getLocationMemory
*	Returns the vector 'locationMemory'
******************************************************************************/
vector <Space *> Ant::getLocationMemory()
{
	return locationMemory;
}

/******************************************************************************
*	Ant::setAlive
*	Sets the bool variable 'isAlive' to input.
******************************************************************************/
void Ant::setAlive(bool aliveIn)
{
	isAlive = aliveIn;
}

/******************************************************************************
*	Ant::getAlive
*	Returns the bool variable 'isAlive'.
******************************************************************************/
bool Ant::getAlive()
{
	return isAlive;
}

/******************************************************************************
*	Ant::setSpokeWithButterfly
*	Sets the bool variable 'spokeWithButterfly' to input.
******************************************************************************/
void Ant::setSpokeWithButterfly(bool spokeIn)
{
	spokeWithButterfly = spokeIn;
}

/******************************************************************************
*	Ant::getSpokeWithButterfly
*	Returns the bool variable 'spokeWithButterfly'.
******************************************************************************/
bool Ant::getSpokeWithButterfly()
{
	return spokeWithButterfly;
}

/******************************************************************************
*	Ant::setXCoord
*	Sets the member variable 'xCoordinate' to input.
******************************************************************************/
void Ant::setXCoord(int xCoordIn)
{
	xCoordinate = xCoordIn;
}

/******************************************************************************
*	Ant::getXCoord
*	Returns the member variable 'xCoordinate'.
******************************************************************************/
int Ant::getXCoord()
{
	return xCoordinate;
}

/******************************************************************************
*	Ant::setYCoord
*	Sets the member variable 'yCoordinate' to input.
******************************************************************************/
void Ant::setYCoord(int yCoordIn)
{
	yCoordinate = yCoordIn;
}

/******************************************************************************
*	Ant::getYCoord
*	Returns the member variable 'yCoordinate'.
******************************************************************************/
int Ant::getYCoord()
{
	return yCoordinate;
}

/******************************************************************************
*	Ant::setCurrentThirst
*	Sets the member variable 'currentThirst' to input.
*	Returns true if new currentThirst value is above zero. Returns false otherwise.
******************************************************************************/
bool Ant::setCurrentThirst(int thirstIn)
{
	currentThirst = thirstIn;
	if (currentThirst > 0)
		return true;
	else
		return false;
}

/******************************************************************************
*	Ant::getCurrentThirst
*	Returns the member variable 'currentThirst'.
******************************************************************************/
int Ant::getCurrentThirst()
{
	return currentThirst;
}

/******************************************************************************
*	Ant::getMaxThirst
*	Returns the member variable 'MAX_THIRST'.
******************************************************************************/
int Ant::getMaxThirst()
{
	return MAX_THIRST;
}

/******************************************************************************
*	Ant::getCurrentCrop
*	Returns the number of food items currently in the ant's crop.
******************************************************************************/
int Ant::getCurrentCrop()
{
	int counter = 0;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (antInventory[i] != 0)
			++counter;
	}
	return counter;
}

/******************************************************************************
*	Ant::getMaxCrop
*	Returns the value of the member variable 'ARRAY_SIZE'.
*	Represents the maximum amount of food the ant's crop can hold.
******************************************************************************/
int Ant::getMaxCrop()
{
	return ARRAY_SIZE;
}

/******************************************************************************
*	Ant::setTurnCounter
*	Sets the member variable 'turnCounter' to input.
******************************************************************************/
void Ant::setTurnCounter(int turnIn)
{
	turnCounter = turnIn;
}

/******************************************************************************
*	Ant::getTurnCounter
*	Returns the member variable 'turnCounter'.
******************************************************************************/
int Ant::getTurnCounter()
{
	return turnCounter;
}

/******************************************************************************
*	Ant::getTimeOfDay
*	Returns a string giving the player a general estimate of the current state
*	of the game's day-night cycle.
******************************************************************************/
string Ant::getTimeOfDay()
{
	string dayTimeName;
	int timeOfDay = getTurnCounter() % 20 + 1;		//returns a number from 1 to 20
	if (timeOfDay <= 4)
	{
		dayTimeName = "Morning";
		return dayTimeName;
	}
	else if (timeOfDay <= 8)
	{
		dayTimeName = "Early Afternoon";
		return dayTimeName;
	}
	else if (timeOfDay <= 12)
	{
		dayTimeName = "Late Afternoon (Warning: Doodlebugs Will Wake Up Soon! Be Advised!)";
		return dayTimeName;
	}
	else if (timeOfDay <= 16)
	{
		dayTimeName = "Evening (Warning: Doodlebugs Are Waking Up! Seek Shelter Soon!)";
		return dayTimeName;
	}
	else
	{
		dayTimeName = "Night (Warning: Doodlebugs Are Active! Seek Shelter Immediately!)";
		return dayTimeName;
	}
}

/******************************************************************************
*	Ant::setCurrentPoints()
*	Sets the member variable 'currentPoints' to input.
******************************************************************************/
void Ant::setCurrentPoints(int pointsIn)
{
	currentPoints = pointsIn;
}

/******************************************************************************
*	Ant::getCurrentPoints()
*	Returns the member variable 'currentPoints'.
******************************************************************************/
int Ant::getCurrentPoints()
{
	return currentPoints;
}

/******************************************************************************
*	Ant::setDoodleHuntEnding
*	Sets the member bool 'currentPoints' to input.
******************************************************************************/
void Ant::setDoodleHuntEnding(bool huntIn)
{
	doodleHuntEnding = huntIn;
}

/******************************************************************************
*	Ant::getDoodleHuntEnding()
*	Returns the member bool 'doodleHuntEnding'.
******************************************************************************/
bool Ant::getDoodleHuntEnding()
{
	return doodleHuntEnding;
}

/******************************************************************************
*	Ant::move
*	Moves the ant's previous location pointer to the space object pointed to by
*	the ant's current location pointer, and moves the ant's current location 
*	pointer from current space object to an adjacent space determined by the user. 
*	If the ant's current location pointer moves to null, a new space object is
*	created using information from the previous space, and is then connected
*	to any adjacent Space objects using coordinate information.
******************************************************************************/
void Ant::move(int directionIn)
{
	//move ant's previous location pointer to space pointed to by current location pointer
	setPreviousLocation(getCurrentLocation());

	//if in Asphalt terrain, subtract two from thirst to pay for movement
	//ant dies if thirst reaches zero
	if (getCurrentLocation()->getSpaceTypeHere() == 1)
	{
		cout << "\nThe sun beats down on you as you cross the rocky terrain. You lose one extra thirst." << endl;
		if (setCurrentThirst(getCurrentThirst() - 2) == false)
		{
			cout << "\nOh no! You've run out of water!" << endl;
			cout << "\"Man, I need to manage my resources better.\" you think to yourself as you slip into unconciousness." << endl;
			setAlive(false);
			return;
		}
	}

	//else, subtract one from thirst to pay for movement
	else
	{
		if (setCurrentThirst(getCurrentThirst() - 1) == false)
		{
			cout << "\nOh no! You've run out of water!" << endl;
			cout << "\"Man, I need to manage my resources better.\" you think to yourself as you slip into unconciousness." << endl;
			setAlive(false);
			return;
		}
	}

	//increase turn counter
	setTurnCounter(getTurnCounter() + 1);

	//use switch to determine which way the ant moves from the current space, determine the spaceType of the new space (if unexplored) and update x and y coordinates
	int spaceType;
	switch (directionIn)
	{
	//1 = move North; +1 to ant's yCoord
	case 1:
	{
		cout << "\nYou move to the north..." << endl;
		setCurrentLocation(getCurrentLocation()->getNorth());
		setYCoord(getYCoord() + 1);
		spaceType = getPreviousLocation()->getSpaceTypeNorth();
		break;
	}
	//2 = move South; -1 to ant's yCoord
	case 2:
	{
		cout << "\nYou move to the south..." << endl;
		setCurrentLocation(getCurrentLocation()->getSouth());
		setYCoord(getYCoord() - 1);
		spaceType = getPreviousLocation()->getSpaceTypeSouth();
		break;
	}
	//3 = move East; +1 to ant's xCoord
	case 3:
	{
		cout << "\nYou move to the east..." << endl;
		setCurrentLocation(getCurrentLocation()->getEast());
		setXCoord(getXCoord() + 1);
		spaceType = getPreviousLocation()->getSpaceTypeEast();
		break;
	}
	//4 = move West; -1 to ant's xCoord
	case 4:
	{
		cout << "\nYou move to the west..." << endl;
		setCurrentLocation(getCurrentLocation()->getWest());
		setXCoord(getXCoord() - 1);
		spaceType = getPreviousLocation()->getSpaceTypeWest();
		break;
	}
	}

	//make a new space and shift current loaction pointer to it if current location pointer is nullptr
	//use info from previous space to determine type of new space
	if (getCurrentLocation() == nullptr)
	{
		Space *newLocation;
		switch (spaceType)
		{
		//1 = asphalt
		case 1:
		{
			newLocation = new Asphalt(getXCoord(), getYCoord());
			setCurrentLocation(newLocation);
			break;
		}
		//2 = grass
		case 2:
		{
			newLocation = new Grass(getXCoord(), getYCoord());
			setCurrentLocation(newLocation);
			break;
		}
		//3 = puddle
		case 3:
		{
			newLocation = new Puddle(getXCoord(), getYCoord());
			setCurrentLocation(newLocation);
			break;
		}
		}
		connect();
		addToMemory(getCurrentLocation());
		determineAdjacentSpaceTypes(getCurrentLocation());
		getCurrentLocation()->displayIntro();
		determineEventHere();
		eventSwitch();
	}
	else
	{
		getCurrentLocation()->displayIntro();
	}
}

/******************************************************************************
*	Ant::blown
*	Ant is blown to a new Grass type location with the given coordinates.
******************************************************************************/
void Ant::blown(int xCoord, int yCoord)
{
	for (int i = 0; i < getLocationMemory().size(); ++i)
	{
		if (getLocationMemory().at(i)->getXCoord() == getXCoord() && getLocationMemory().at(i)->getYCoord() == getYCoord())
		{
			cout << "\nYou recognize this location. You have been here before." << endl;
			return;
		}
	}

	cout << "\nThis location is foreign to you. You have not been here before." << endl;
	Space *blownTo = new Grass(xCoord, yCoord);
	setCurrentLocation(blownTo);
	setPreviousLocation(blownTo);
	connect();
	addToMemory(blownTo);
	determineAdjacentSpaceTypes(getCurrentLocation());
}

/******************************************************************************
*	Ant::connect
*	Checks ant's current location against locations stored in ant's memory.
*	If any spaces pointed to by pointers in ant's memoryLocation vector are
*	adjacent to the space pointed to by ant's currentLocation pointer, the spaces
*	are connected via the appropriate direction pointers.
******************************************************************************/
void Ant::connect()
{
	//check ant's memory for adjacent locations, and connect as necessary
	for (int i = 0; i < locationMemory.size(); ++i)
	{
		//check for any spaces in memory with the same xCoordinate as the current location (in the same column)
		if (getCurrentLocation()->getXCoord() == locationMemory.at(i)->getXCoord())
		{
			//make sure that the space in memory with the same xCoordinate does not have the same yCoordinate (meaning they are the same space)
			if (getCurrentLocation()->getYCoord() == locationMemory.at(i)->getYCoord())
				return;

			//check if space in memory with same xCoordinate is one space north of the current location (yCoordCurrent + 1 = yCoordMemory)
			if (getCurrentLocation()->getYCoord() + 1 == locationMemory.at(i)->getYCoord())
			{
				//set the north and south pointers appropriately
				getCurrentLocation()->setNorth(locationMemory.at(i));
				locationMemory.at(i)->setSouth(getCurrentLocation());
			}

			//check if space in memory with same xCoordinate is one space south of the current location (yCoordCurrent - 1 = yCoordMemory)
			if (getCurrentLocation()->getYCoord() - 1 == locationMemory.at(i)->getYCoord())
			{
				//set the south and north pointers appropriately
				getCurrentLocation()->setSouth(locationMemory.at(i));
				locationMemory.at(i)->setNorth(getCurrentLocation());
			}
		}
		//check for any spaces with the same yCoordinate (in the same row)
		if (getCurrentLocation()->getYCoord() == locationMemory.at(i)->getYCoord())
		{
			//make sure that the space in memory with the same yCoordinate does not have the same xCoordinate (meaning they are the same space)
			if (getCurrentLocation()->getXCoord() == locationMemory.at(i)->getXCoord())
				return;

			//check if space in memory with same yCoordinate is one space east (xCoordCurrent + 1 = xCoordMemory)
			if (getCurrentLocation()->getXCoord() + 1 == locationMemory.at(i)->getXCoord())
			{
				//set the east and west pointers appropriately
				getCurrentLocation()->setEast(locationMemory.at(i));
				locationMemory.at(i)->setWest(getCurrentLocation());
			}

			//check if space in memory with same yCoordinate is one space west (xCoordCurrent - 1 = xCoordMemory)
			if (getCurrentLocation()->getXCoord() - 1 == locationMemory.at(i)->getXCoord())
			{
				//set the west and east pointers appropriately
				getCurrentLocation()->setWest(locationMemory.at(i));
				locationMemory.at(i)->setEast(getCurrentLocation());
			}
		}
	}
}

/******************************************************************************
*	Ant::addToMemory
*	Adds the ant's current location to memoryLocation vector.
******************************************************************************/
void Ant::addToMemory(Space *locationIn)
{
	locationMemory.push_back(locationIn);
}

/******************************************************************************
*	Ant::haveIBeenHere
*	Checks ant's current location against locations stored in ant's memory.
*	Returns true if ant's current location matches the location of a space in
*	ant's memory. Returns false otherwise.
******************************************************************************/
bool Ant::haveIBeenHere()
{
	for (int i = 0; i < locationMemory.size(); ++i)
	{
		if (getCurrentLocation()->getXCoord() == locationMemory.at(i)->getXCoord() &&
			getCurrentLocation()->getYCoord() == locationMemory.at(i)->getYCoord())
			return true;
	}
	return false;
}

/******************************************************************************
*	Ant::addFood
*	Adds food to the member array 'antInventory'.
*	Each food type corresponds to a certain integer (equal to the amount of points
*	it is worth when turned in at the nest).
******************************************************************************/
bool Ant::addFood(int foodIn)
{
	bool foodAdded = false;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (antInventory[i] == 0 && foodAdded == false)
		{
			antInventory[i] = foodIn;
			foodAdded = true;
			int count = 0;
			for (int j = 0; j < ARRAY_SIZE; ++j)
			{
				if (antInventory[j] != 0)
					++count;
			}
			cout << "\nCrop is now " << count << "/" << ARRAY_SIZE << " full." << endl;
		}
	}
	if (foodAdded == false)
	{
		cout << "\nOops! Looks like you're crop is too full to carry any more food." << endl;
		cout << "You need to return to the nest before you can gather more food." << endl;
	}
	return foodAdded;
}

/******************************************************************************
*	Ant::giveMeat
*	Removes meat from the ant's inventory.
*	Returns true if meat was removed from inventory, returns false otherwise.
******************************************************************************/
bool Ant::giveMeat()
{
	bool meatRemoved = false;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (antInventory[i] == 5 || antInventory[i] == 50)
		{
			antInventory[i] = 0;
			meatRemoved = true;
			int count = 0;
			for (int j = 0; j < ARRAY_SIZE; ++j)
			{
				if (antInventory[j] != 0)
					++count;
			}
			cout << "\nCrop is now " << count << "/" << ARRAY_SIZE << " full." << endl;
		}
	}
	return meatRemoved;
}

/******************************************************************************
*	Ant::smell
*	Allows ant to sense it's immediate environment.
*	Displays spaceTypes of spaces next to the space the ant is currently in.
*	Does not advance the turn or cost water to smell.
******************************************************************************/
void Ant::smell()
{
	cout << "\nYou wave your antennae and sense the chemicals in the air..." << endl;

	//smell north
	switch (getCurrentLocation()->getSpaceTypeNorth())
	{
	//0 = Home
	case 0:
	{
		cout << "\nYou smell the comforting smell of the nest to the north." << endl;
		break;
	}
	//1 = Asphalt
	case 1:
	{
		cout << "\nYou smell the dry air of rocky terrain to the north." << endl;
		break;
	}
	//2 = Grass
	case 2:
	{
		cout << "\nYou smell the crisp scent of green grass to the north." << endl;
		break;
	}
	//3 = Puddle
	case 3:
	{
		cout << "\nYou smell the fresh scent of water to the north." << endl;
		break;
	}
	}

	//smell south
	switch (getCurrentLocation()->getSpaceTypeSouth())
	{
	//0 = Home
	case 0:
	{
		cout << "You smell the comforting smell of the nest to the south." << endl;
		break;
	}
	//1 = Asphalt
	case 1:
	{
		cout << "You smell the dry air of rocky terrain to the south." << endl;
		break;
	}
	//2 = Grass
	case 2:
	{
		cout << "You smell the crisp scent of green grass to the south." << endl;
		break;
	}
	//3 = Puddle
	case 3:
	{
		cout << "You smell the fresh scent of water to the south." << endl;
		break;
	}
	}

	//smell east
	switch (getCurrentLocation()->getSpaceTypeEast())
	{
	//0 = Home
	case 0:
	{
		cout << "You smell the comforting smell of the nest to the east." << endl;
		break;
	}
	//1 = Asphalt
	case 1:
	{
		cout << "You smell the dry air of rocky terrain to the east." << endl;
		break;
	}
	//2 = Grass
	case 2:
	{
		cout << "You smell the crisp scent of green grass to the east." << endl;
		break;
	}
	//3 = Puddle
	case 3:
	{
		cout << "You smell the fresh scent of water to the east." << endl;
		break;
	}
	}

	//smell west
	switch (getCurrentLocation()->getSpaceTypeWest())
	{
	//0 = Home
	case 0:
	{
		cout << "You smell the comforting smell of the nest to the west." << endl;
		break;
	}
	//1 = Asphalt
	case 1:
	{
		cout << "You smell the dry air of rocky terrain to the west." << endl;
		break;
	}
	//2 = Grass
	case 2:
	{
		cout << "You smell the crisp scent of green grass to the west." << endl;
		break;
	}
	//3 = Puddle
	case 3:
	{
		cout << "You smell the fresh scent of water to the west." << endl;
		break;
	}
	}

	//smell general direction of nest -> if the space the player is in, and none of the adjacent spaces are the nest, tell the player the general direction of the nest
	if (getCurrentLocation()->getSpaceTypeHere() != 0 && getCurrentLocation()->getSpaceTypeNorth() != 0 && getCurrentLocation()->getSpaceTypeSouth() != 0 &&
		getCurrentLocation()->getSpaceTypeEast() != 0 && getCurrentLocation()->getSpaceTypeWest() != 0)
	{
		cout << "\nYou can smell the nest somewhere to the ";
		//check if ant is north of nest
		if (getYCoord() > 0)
		{
			//check if ant is east or west of nest
			if (getXCoord() > 0)
			{
				cout << "southwest." << endl;
				return;
			}
			else if (getXCoord() < 0)
			{
				cout << "southeast." << endl;
				return;
			}
			else
			{
				cout << "south." << endl;
				return;
			}
		}

		//check if ant is south of nest
		else if (getYCoord() < 0)
		{
			//check if ant is east or west of nest
			if (getXCoord() > 0)
			{
				cout << "northwest." << endl;
				return;
			}
			else if (getXCoord() < 0)
			{
				cout << "northeast." << endl;
				return;
			}
			else
			{
				cout << "north." << endl;
			}
		}
		
		//check if ant is directly east or west
		else if (getYCoord() == 0)
		{
			//check if ant is east or west of nest
			if (getXCoord() > 0)
			{
				cout << "west." << endl;
				return;
			}
			if (getXCoord() < 0)
			{
				cout << "east." << endl;
				return;
			}
		}
	}
}

/******************************************************************************
*	isDigits
*	Accepts a string as parameter, and returns true if the string contains
*	only digits (no letters or punctuation).
******************************************************************************/
bool Ant::isDigits(string &str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}

/******************************************************************************
*	menuChoice
*	Handles user input validation for menu navigation.
*	Accepts user input as a string, and an integer representing the total
*	number of options available for that menu. Returns as an integer
*	the user's menu choice.
******************************************************************************/
int Ant::menuChoice(string &userInput, int numberMenuOptions)
{
	while (isDigits(userInput) == false || stoi(userInput) > numberMenuOptions || stoi(userInput) < 1)
	{
		cout << "Oops! Please enter a number from 1 to " << numberMenuOptions << endl;
		cout << "Choice: ";
		cin.clear();
		cin.ignore(80, '\n');
		cin >> userInput;
	}
	return stoi(userInput);
}

/******************************************************************************
*	Ant::determineEventHere
*	Determines the random event that occurs upon ant's first visit to a new space.
*	If the time of day is 'Evening', player has a 25% chance of triggering doodlebug ambush.
*	If the time of day is 'Night', player has a 75% chance of triggering doodlebug ambush.
******************************************************************************/
void Ant::determineEventHere()
{
	srand(time(0));
	int doodleAmbush;
	if (getCurrentLocation()->getSpaceTypeHere() == 0)
	{
		getCurrentLocation()->setEventHere(0);
		return;
	}
	else if (getTimeOfDay() == "Evening (Warning: Doodlebugs Are Waking Up! Seek Shelter Soon!)")
	{
		doodleAmbush = rand() % 4;
		if (doodleAmbush == 3)
		{
			getCurrentLocation()->setEventHere(9);
			return;
		}
		else
		{
			getCurrentLocation()->setEventHere(rand() % 8 + 1);
			return;
		}
	}
	else if (getTimeOfDay() == "Night (Warning: Doodlebugs Are Active! Seek Shelter Immediately!)")
	{
		doodleAmbush = rand() % 4;
		if (doodleAmbush == 3)
		{
			getCurrentLocation()->setEventHere(rand() % 8 + 1);
			return;
		}
		else
		{
			getCurrentLocation()->setEventHere(9);
		}
	}
	else
		getCurrentLocation()->setEventHere(rand() % 8 + 1);
}

/******************************************************************************
*	Ant::eventSwitch
*	Implements the random event determined by value of member integer 'eventHere'.
******************************************************************************/
void Ant::eventSwitch()
{
	srand(time(0));
	switch (getCurrentLocation()->getEventHere())
	{
	//0 = starting at the nest
	case 0:
	{
		cout << "\nYou begin your adventure at the nest, ready and eager to do your part to strengthen the colony." << endl;
		break;
	}
	//1 = find dropped food
	case 1:
	{
		int fruitOrMeat = rand() % 4 + 1;
		string takeFood = "0";
		//25% chance to find meat (worth 5 points each)
		if (fruitOrMeat == 4)
		{
			cout << "\nAn insect seems to have died here. It's carcass lies motionless on the ground." << endl;
			cout << "What a rare treat!" << endl;
			cout << "While you yourself cannot consume this, your larval sisters can." << endl;
			cout << "Take some meat for your sisters to eat?" << endl;
			cout << "[1]: Yes" << endl;
			cout << "[2]: No" << endl;
			cout << "Choice: ";
			cin >> takeFood;
			if (menuChoice(takeFood, 2) == 1)
			{
				cout << "\nYour choose to take some meat to bring back to your sisters." << endl;
				if (addFood(5) == true)
				{
					cout << "Your sisters will be thankful for your hard work." << endl;
					cout << "Only scraps of the insect remain now." << endl;
				}
				else
					cout << "\nYou hope your sisters will find this bounty before it's all gone." << endl;
			}
			else
			{
				cout << "\nYou choose not to store some meat. You have more important matters to attend to." << endl;
				cout << "You hope your sisters will find this bounty before it's all gone." << endl;
			}
		}
		//75% chance to find fruit (worth 1 point each)
		else
		{
			cout << "\nYou find some fruit here, abandoned on the ground." << endl;
			cout << "Other insects are already here to partake in the feast." << endl;
			cout << "Take some fruit for your sisters to eat?" << endl;
			cout << "[1]: Yes" << endl;
			cout << "[2]: No" << endl;
			cout << "Choice: ";
			cin >> takeFood;
			if (menuChoice(takeFood, 2) == 1)
			{
				cout << "\nYou choose to take some fruit to bring back to your sisters." << endl;
				if (addFood(1) == true)
				{
					cout << "\nYour sisters will be thankful for your hard work." << endl;
					cout << "The other insects eat the last of the fruit." << endl;
				}
				else
					cout << "\nThe other insects eat the last of the fruit." << endl;
			}
			else
			{
				cout << "\nYou choose not to store some fruit. You have more important matters to attend to." << endl;
				cout << "The other insects eat the last of the fruit." << endl;
			}
		}
		break;
	}
	//2 = rain/sprinklers turn on (increase thirst by random integer)
	case 2:
	{
		cout << "\nAs you enter the area, water begins to fall from the sky!" << endl;
		cout << "You drink some water. It tastes funny, but you try not to think about it too hard." << endl;
		//regain a random amount of thirst in range [1 .. 5]
		int gainedThirst = rand() % 5 + 1;
		setCurrentThirst(getCurrentThirst() + gainedThirst);
		cout << "You regain " << gainedThirst << " thirst." << endl;
		if (getCurrentThirst() > getMaxThirst())
			setCurrentThirst(getMaxThirst());
		cout << "The sudden shower ends as quickly as it began." << endl;
		break;
	}
	//3 = encounter sister ants (give one random food 25% chance they give meat, 75% chance they give fruit)
	case 3:
	{
		string talk = "0";
		cout << "\nYou notice some of your sister ants are already here." << endl;
		cout << "Talk to your sisters?" << endl;
		cout << "[1]: Yes" << endl;
		cout << "[2]: No" << endl;
		cout << "Choice: ";
		cin >> talk;
		switch (menuChoice(talk, 2))
		{
			//1 = chance that sisters give you food they found
		case 1:
		{
			int giveFood = rand() % 2 + 1;
			int fruitOrMeat = rand() % 4 + 1;

			cout << "\nYou approach and greet your sisters..." << endl;
			if (giveFood = 1)
			{
				if (fruitOrMeat == 4)
				{
					string takeMeat = "0";
					cout << "\nYour sisters are excited. They've found a source of meat for the colony!" << endl;
					cout << "They don't have enough room among them to take all the meat back themselves, however, and offer some to you." << endl;
					cout << "Take some meat back to the colony for your sisters?" << endl;
					cout << "[1]: Yes" << endl;
					cout << "[2]: No" << endl;
					cout << "Choice: ";
					cin >> takeMeat;
					switch (menuChoice(takeMeat, 2))
					{
					case 1:
					{
						cout << "\nYou agree to take some of the meat back to the colony, much to the delight of your sisters." << endl;
						if (addFood(5) == true)
							cout << "Your sisters depart in the direction of the nest." << endl;
						else
							cout << "Your sisters seem disappointed as they depart in the direction of the nest." << endl;
						break;
					}
					case 2:
					{
						cout << "\nYou refuse their offer. Your sisters seem disappointed." << endl;
						cout << "Your sisters depart in the direction of the nest." << endl;
						break;
					}
					}

				}
				else
				{
					string takeFruit = "0";
					cout << "\nYour sisters are happy. They've found a source of fruit for the colony." << endl;
					cout << "They don't have enough room among them to take all the fruit back themselves, however, and offer some to you." << endl;
					cout << "Take some fruit back to the colony for your sisters?" << endl;
					cout << "[1]: Yes" << endl;
					cout << "[2]: No" << endl;
					cout << "Choice: ";
					cin >> takeFruit;
					switch (menuChoice(takeFruit, 2))
					{
					case 1:
					{
						cout << "\nYou agree to take some of the fruit back to the colony, much to the delight of your sisters." << endl;
						if (addFood(1) == true)
							cout << "Your sisters depart in the direction of the nest." << endl;
						else
							cout << "Your sisers seem disappointed as they depart in the direction of the nest." << endl;
						break;
					}
					case 2:
					{
						cout << "\nYou refuse their offer. Your sisters seem disappointed." << endl;
						cout << "Your sisters depart in the direction of the nest." << endl;
						break;
					}
					}
				}
			}
			else
			{
				cout << "\nYour sisters seem busy looking for food to feed the colony." << endl;
				cout << "They greet you and depart in the direction of the nest." << endl;
			}
			break;
		}
		//2 = don't talk to sisters
		case 2:
		{
			cout << "\nYou choose to leave your sisters to their work." << endl;
			cout << "After all, their work is important to the colony's survival." << endl;
			cout << "Your sisters depart in the direction of the nest." << endl;
			break;
		}
		}
		break;
	}
	//4 = kid with magnifying glass tries to fry the ant (kills player if they don't run away)
	case 4:
	{
		string runAway = "0";
		cout << "\nSuddenly, the light brightens in a small circle around you. The air feels suddenly warmer." << endl;
		cout << "What do you do?" << endl;
		cout << "[1]: Run away" << endl;
		cout << "[2]: Look around" << endl;
		cout << "Choice: ";
		cin >> runAway;
		switch (menuChoice(runAway, 2))
		{
			//1 = get away safely
		case 1:
		{
			cout << "\nYou choose to run away. You've heard enough rumors about ants burning on a sunny day to know you're in trouble." << endl;
			cout << "You run with all your might, and manage to escape." << endl;
			cout << "If you survive long enough to tell your sisters back at the nest about this, they probably won't believe you." << endl;
			break;
		}
		//2 = burned to death
		case 2:
		{
			cout << "\nYou choose to look around. The circle of light around you becomes a pinpoint, centered right on you." << endl;
			cout << "You realize too late that you are burning alive. Your life extinguishes in a whisp of smoke." << endl;
			setAlive(false);
			break;
		}
		}
		break;
	}
	//5 = gust of wind (moves ant to random location - either new or previously explored)
	case 5:
	{
		//select the direction that the ant will move in range [1 .. 4]
		int directionMoved = rand() % 4 + 1;
		//select the distance that the ant will move in range [2 .. 4]
		int distanceMoved = rand() % 3 + 2;

		cout << "\nAs you enter this area, a gale blows you off your feet." << endl;
		cout << "As the wind settles, you realize you've been swept to another area some distance to the ";
		switch (directionMoved)
		{
			//1 = North; y = y + distanceMoved
		case 1:
		{
			cout << "North." << endl;
			setYCoord(getYCoord() + distanceMoved);
			break;
		}
		//2 = South; y = y - distanceMoved
		case 2:
		{
			cout << "South." << endl;
			setYCoord(getYCoord() - distanceMoved);
			break;
		}
		//3 = East; x = x + distanceMoved
		case 3:
		{
			cout << "East." << endl;
			setXCoord(getXCoord() + distanceMoved);
			break;
		}
		//4 = West; x = x - distanceMoved
		case 4:
		{
			cout << "West." << endl;
			setXCoord(getXCoord() - distanceMoved);
			break;
		}
		}

		//if blown to a new location, create new space (grass), set ant's location there, add to ant's memory, and connect the new space to any adjacent spaces
		blown(getXCoord(), getYCoord());
		break;
	}
	//6 = other insects (game effects depend on specific insect)
	case 6:
	{
		int bugEncounter = rand() % 4 + 1;
		string talk = "0";
		switch (bugEncounter)
		{
			//1 = caterpillar
		case 1:
		{

			cout << "\nYou find a caterpillar chewing on the leaf of a nearby shrub." << endl;
			cout << "Talk to the caterpillar?" << endl;
			cout << "[1]: Yes" << endl;
			cout << "[2]: No" << endl;
			cout << "Choice: ";
			cin >> talk;
			switch (menuChoice(talk, 2))
			{
			case 1:
			{
				cout << "\nYou approach and greet the caterpillar..." << endl;
				cout << "\"Oh I cannot wait to become a butterfly!\" says the caterpillar. \"Then I will be beautiful and be able to fly!\"" << endl;
				if (getSpokeWithButterfly() == true)
				{
					string takeMeat = "0";
					cout << "\nYou tell the caterpillar about your conversation with the butterfly, and how it wished it could return to being a caterpillar." << endl;
					cout << "\"Oh my... perhaps I am a bit too eager to leave my caterpillar days behind me.\" says the caterpillar." << endl;
					cout << "\"After all, I do quite enjoy spending my days just eating and sleeping.\"" << endl;
					cout << "\"Thank you, kind ant, for showing me the error of my ways.\", the caterpillar continues." << endl;
					cout << "\"As a reward, why don't you take this meat I found? I don't eat meat, so it will only go to waste if I keep it.\"" << endl;
					cout << "Take meat?" << endl;
					cout << "[1]: Yes" << endl;
					cout << "[2]: No" << endl;
					cout << "Choice: " << endl;
					cin >> takeMeat;
					switch (menuChoice(takeMeat, 2))
					{
					case 1:
					{
						cout << "\nYou choose to take the meat." << endl;
						if (addFood(5) == true)
							cout << "The caterpillar seems pleased." << endl;
						else
						{
							cout << "\nThe caterpillar seems confused, but doesn't question your decision." << endl;
							cout << "He's not even sure ants eat meat anyways." << endl;
						}
						break;
					}
					case 2:
					{
						cout << "\nYou choose not to take the meat." << endl;
						cout << "The caterpillar seems confused, but doesn't question your decision." << endl;
						cout << "He's not even sure ants eat meat anyways." << endl;
						break;
					}
					}
				}
				else
				{
					cout << "\nYou feel like that sentiment is short-sighted." << endl;
					cout << "However, you've never spoken with a butterfly so you don't know what butterflies think about the matter." << endl;
					cout << "You choose to keep your thoughts to yourself, and the caterpillar crawls away." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "\nYou choose to ignore the caterpillar and continue on your search for food." << endl;
				cout << "After a little while, the caterpillar crawls away." << endl;
				break;
			}
			}
			break;
		}
		//2 = honeybee
		case 2:
		{
			string talk = "0";
			cout << "\nYou spot a honeybee, resting on a nearby flower." << endl;
			cout << "Talk to the honeybee?" << endl;
			cout << "[1]: Yes" << endl;
			cout << "[2]: No" << endl;
			cout << "Choice: ";
			cin >> talk;
			switch (menuChoice(talk, 2))
			{
			case 1:
			{
				cout << "\nYou approach and greet the honeybee..." << endl;
				cout << "\"Bzz Bzz Bzz!\" the honey bee responds. \"Can't talk, gotta work!\"" << endl;
				cout << "The honeybee flies away. That must be one busy bee." << endl;
				break;
			}
			case 2:
			{
				cout << "\nYou choose to ignore the honeybee and continue your search for food." << endl;
				cout << "After a while, the honeybee flies away." << endl;
				break;
			}
			}
			break;
		}
		//3 = butterfly
		case 3:
		{
			string talk = "0";
			cout << "\nYou notice a beautiful butterfly, drinking nectar from a nearby flower." << endl;
			cout << "Talk to the butterfly?" << endl;
			cout << "[1]: Yes" << endl;
			cout << "[2]: No" << endl;
			cout << "Choice: ";
			cin >> talk;
			switch (menuChoice(talk, 2))
			{
			case 1:
			{
				cout << "\nYou approach and greet the butterfly..." << endl;
				cout << "\"Oh, how I yearn to return to the halcyon days of my caterpillar youth.\" the butterfly exclaims." << endl;
				cout << "\"The pressures to be beautiful and find love are so great, I'm afraid my color might fade from the stress.\"" << endl;
				cout << "\"But... if my color fades... then I won't be beautiful anymore! And if I'm not beautiful anymore, then I won't ever find love! Oh, heavens NOOO!!\"" << endl;
				cout << "The butterfly begins to hyperventilate as you slowly back away." << endl;
				cout << "Perhaps you'd better advise any caterpillars you meet to enjoy their care-free days as a caterpillar for as long as they can." << endl;
				setSpokeWithButterfly(true);
				break;
			}
			case 2:
			{
				cout << "\nYou choose to ignore the butterfly, who suddenly seems to be hyperventilating for no reason." << endl;
				cout << "After a while, the butterfly seems to recover from it's nervous breakdown and flies away." << endl;
				break;
			}
			}
			break;
		}
		//4 = spider
		case 4:
		{
			string approach = "0";
			cout << "\nYou see a spider, sitting in it's web on a low-hanging branch. The spider notices your presence." << endl;
			cout << "\"Oh my... what at tasety looking moursel.\" the spider says." << endl;
			cout << "\"Why don't you come up here? I have plenty of meat to share, and I'd be glad to share some with you.\"" << endl;
			cout << "Climb up to the spider's web?" << endl;
			cout << "[1]: Yes" << endl;
			cout << "[2]: No" << endl;
			cout << "Choice: ";
			cin >> approach;
			switch (menuChoice(approach, 2))
			{
				//1 = ant is trapped/eaten
			case 1:
			{
				cout << "\nYou climb up the branch and onto the spider's web. You become trapped in the sticky silk of the spider's web." << endl;
				cout << "\"Fufufu... you've been tricked, my foolish friend. Now I'll have even more meat to eat!" << endl;
				cout << "The spider quickly bites you and encases you in a web cocoon as you succumb to the spider's venom." << endl;
				setAlive(false);
				break;
			}
			//2 = ant leaves
			case 2:
			{
				cout << "\nYou decide not to risk losing your life over some meat. The spider looks disappointed." << endl;
				cout << "After a while, the spider retreats out of sight." << endl;
				break;
			}
			}
			break;
		}
		}
		break;
	}
	//7 = ant survives being (almost) stepped on (tarumatizing, but doesn't affect gameplay)
	case 7:
	{
		string whatDo = "0";
		cout << "\nAs you navigate through the area, the sky becomes dark as a large shadow looms overhead." << endl;
		cout << "What do you do?" << endl;
		cout << "[1]: Try to find cover" << endl;
		cout << "[2]: Try to run away" << endl;
		cout << "Choice: ";
		cin >> whatDo;
		switch (menuChoice(whatDo, 2))
		{
		case 1:
		{
			cout << "\nYou quickly search for cover and discover a small crevice in a nearby stone." << endl;
			cout << "You manage to squeeze in the crevice just in time. A large object crashes into the ground on top of you with a deafening BOOM!" << endl;
			cout << "The world goes dark for only a second, and the object flies away and disappears as suddenly as it came." << endl;
			cout << "If you survive long enough to tell your sisters back at the nest about this, they probably won't believe you." << endl;
			break;
		}
		case 2:
		{
			cout << "\nYou run away as fast as your legs can carry you." << endl;
			cout << "You barely manage to escape the shadow as the object that created it crashes into the ground behind you with a deafening BOOM!" << endl;
			cout << "After only a moment, the object flies away and disappears as suddenly as it came." << endl;
			cout << "If you survive long enough to tell your sisters back at the nest about this, they probably won't believe you." << endl;
			break;
		}
		}
		break;
	}
	//8 = dead doodlebug ("Wait, doodlebugs are made out of meat???") -> unlock doodle-hunt ending if you can bring it back to the colony
	case 8:
	{
		string approach = "0";
		cout << "\nYou notice a doodlebug in this area, the sworn enemy of your colony." << endl;
		cout << "You observe it from afar. It appears to be dead." << endl;
		cout << "You're not sure though." << endl;
		cout << "After all, the doodlebug was declared the sworn enemy of the colony for a reason. It could be some kind of... DOODLE-TRAP!" << endl;
		cout << "\nApproach the doodlebug?" << endl;
		cout << "[1]: Yes" << endl;
		cout << "[2]: No" << endl;
		cout << "Choice: ";
		cin >> approach;
		switch (menuChoice(approach, 2))
		{
			//1 = approach, realize doodlebugs are made out of meat (doodlebug meat = 50 points)
		case 1:
		{
			string takeDoodleMeat = "0";
			cout << "\nYou cautiously approach the doodlebug..." << endl;
			cout << "It's definitely dead, and not a doodle-trap." << endl;
			cout << "Wait... you recognize this smell... could it be... doodlebugs are made out of meat?!" << endl;
			cout << "If we were to... eat the doodlebugs... BEFORE they could eat us... this could change EVERYTHING!" << endl;
			cout << "\nTake some doodlebug meat back to the colony?" << endl;
			cout << "[1]: Yes" << endl;
			cout << "[2]: No" << endl;
			cout << "Choice: ";
			cin >> takeDoodleMeat;
			switch (menuChoice(takeDoodleMeat, 2))
			{
			case 1:
			{
				cout << "\nYou choose to take the doodlebug meat to share with the colony. This discovery could change everything." << endl;
				if (addFood(50) == true)
				{
					cout << "\nYou cautiosly eat a little of the doodle-meat yourself. It's... delicious?!" << endl;
					cout << "Only scraps remain of the doodlebug now. Doodle-scraps." << endl;
				}
				else
					cout << "You hope your sisters will find this bounty before it's all gone." << endl;
				break;
			}
			case 2:
			{
				cout << "\nYou decide against taking a chunk of doodlebug meat." << endl;
				cout << "After all, there's no way the colony doesn't know that doodlebugs are made of meat... right?" << endl;
				cout << "You hope your sisters will find this bounty before it's all gone." << endl;
				break;
			}
			}
			break;
		}
		//2 = don't approach
		case 2:
		{
			cout << "\nYou choose to keep your distance. Doodle-traps are no joke, and you'd rather live to serve the colony another day." << endl;
			break;
		}
		}
		break;
	}
	//9 = doodlebug ambush (will take meat if the ant has any in inventory -> kills ant if no meat)
	case 9:
	{
		string giveMeatChoice = "0";
		bool hasMeat = false;
		cout << "\nYou are ambushed by a doodlebug, the sworn enemy of your colony!" << endl;
		cout << "Doodlebugs are fast and powerful. You have no chance of running or fighting." << endl;
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (antInventory[i] == 5 || antInventory[i] == 50)
			{
				hasMeat = true;
				break;
			}
		}
		if (hasMeat == true)
		{
			cout << "\nHowever, you've heard from some of your very lucky sisters that doodlebugs can be distracted if you offer them meat." << endl;
			cout << "\nOffer the doodlebug some meat?" << endl;
			cout << "[1]: Yes" << endl;
			cout << "[2]: No" << endl;
			cout << "Choice: ";
			cin >> giveMeatChoice;
			switch (menuChoice(giveMeatChoice, 2))
			{
				//1 = offer meat
			case 1:
			{
				cout << "\nYou choose to offer the doodlebug some meat from your crop." << endl;
				if (giveMeat() == true)
					cout << "You make a quick escape while the doodlebug is distracted by your offered meat." << endl;
				else
				{
					cout << "Oh no! You have no meat to offer the doodlebug!" << endl;
					cout << "The doodlebug eats you in one giant doodle-bite." << endl;
					setAlive(false);
				}
				break;
			}
			//2 = don't offer meat -> die
			case 2:
			{
				cout << "\nYou choose not to offer the doodlebug some of the meat from your crop." << endl;
				cout << "The doodlebug wastes no time eating you in one giant doodle-bite." << endl;
				setAlive(false);
				break;
			}
			}
		}
		else
		{
			cout << "The doodlebug wastes no time eating you in one giant doodle-bite." << endl;
			setAlive(false);
		}
		break;
	}
	}
}

/******************************************************************************
*	Space::determineAdjacentSpaceTypes
*	Generates random numbers (0 = home, 1 = asphalt, 2 = grass, 3 = puddle) for
*	the new space's spaceType integers (north, south, east, and west). Then checks
*	those numbers against the spaceType integers of existing, adjacent Space objects.
*	For a given Space object, all of it's adjacent Space objects should end up
*	agreeing on the spaceType of that Space object (which determines the child
*	class of the Space class used when creating a new Space object with those coordinates).
******************************************************************************/
void Ant::determineAdjacentSpaceTypes(Space* location)
{
	//give all spaceType ints at pointer 'location' a random value from range [1 ... 3]
	srand(time(0));
	location->setSpaceTypeNorth(rand() % 3 + 1);
	location->setSpaceTypeSouth(rand() % 3 + 1);
	location->setSpaceTypeEast(rand() % 3 + 1);
	location->setSpaceTypeWest(rand() % 3 + 1);

	//return here if determining the spaceType ints of the home space
	if (getCurrentLocation()->getSpaceTypeHere() == 0)
		return;

	//check spaceType ints against those of adjacent spaces
	//update as necessary to achieve consensus with other spaces adjacent to the spaces
	//referenced by space's spaceType ints

	//check spaceType of coordinates to the north
	int northXCoord = getXCoord();
	int northYCoord = getYCoord() + 1;

	//check to see if any of the spaces pointed to by pointers in ant's locationMemory vector match the coordinates north of our space
	for (int n = 0; n < getLocationMemory().size(); ++n)
	{
		if (getLocationMemory().at(n)->getXCoord() == northXCoord && getLocationMemory().at(n)->getYCoord() == northYCoord)
		{
			location->setSpaceTypeNorth(getLocationMemory().at(n)->getSpaceTypeHere());
			break;
		}
	}

	//if none found, check to see if any of the spaces pointed to by pointers in ant's locationMemory vector are also adjacent to the coordinates north of our space
	for (int i = 0; i < getLocationMemory().size(); ++i)
	{
		//check for any space objects adjacent to the coordinates in question on the north side
		if (getLocationMemory().at(i)->getXCoord() == northXCoord && getLocationMemory().at(i)->getYCoord() == northYCoord + 1)
		{
			location->setSpaceTypeNorth(getLocationMemory().at(i)->getSpaceTypeSouth());
			break;
		}
		//our space is adjacent to the coordinates to the south, so don't check that
		//check for any space objects adjacent to the coordiantes in question on the east side
		if (getLocationMemory().at(i)->getXCoord() == northXCoord + 1 && getLocationMemory().at(i)->getYCoord() == northYCoord)
		{
			location->setSpaceTypeNorth(getLocationMemory().at(i)->getSpaceTypeWest());
			break;
		}
		//check for any space objects adjacent to the coordinates in question on the west side
		if (getLocationMemory().at(i)->getXCoord() == northXCoord - 1 && getLocationMemory().at(i)->getYCoord() == northYCoord)
		{
			location->setSpaceTypeNorth(getLocationMemory().at(i)->getSpaceTypeEast());
			break;
		}
	}

	//check spaceType of coordinates to the south
	int southXCoord = getXCoord();
	int southYCoord = getYCoord() - 1;

	//check to see if any of the spaces pointed to by pointers in ant's locationMemory vector match the coordinates south of our space
	for (int s = 0; s < getLocationMemory().size(); ++s)
	{
		if (getLocationMemory().at(s)->getXCoord() == southXCoord && getLocationMemory().at(s)->getYCoord() == southYCoord)
		{
			location->setSpaceTypeSouth(getLocationMemory().at(s)->getSpaceTypeHere());
			break;
		}
	}

	//if none found, check to see if any of the spaces pointed to by pointer in ant's locationMemory vector are also adjacent to the coordinates south of our space
	for (int j = 0; j < getLocationMemory().size(); ++j)
	{
		//our space is adjacent to the corrdinates to the north, so don't check that
		//check for any space objects adjacent to the coordinates in question on the south side
		if (getLocationMemory().at(j)->getXCoord() == southXCoord && getLocationMemory().at(j)->getYCoord() == southYCoord - 1)
		{
			location->setSpaceTypeSouth(getLocationMemory().at(j)->getSpaceTypeNorth());
			break;
		}
		//check for any space objects adjacent to the coordinates in question on the east side
		if (getLocationMemory().at(j)->getXCoord() == southXCoord + 1 && getLocationMemory().at(j)->getYCoord() == southYCoord)
		{
			location->setSpaceTypeSouth(getLocationMemory().at(j)->getSpaceTypeWest());
			break;
		}
		//check for any space objects adjacent to the coordinates in question on the west side
		if (getLocationMemory().at(j)->getXCoord() == southXCoord - 1 && getLocationMemory().at(j)->getYCoord() == southYCoord)
		{
			location->setSpaceTypeSouth(getLocationMemory().at(j)->getSpaceTypeEast());
			break;
		}
	}

	//check spaceType of coordinates to the east
	int eastXCoord = getXCoord() + 1;
	int eastYCoord = getYCoord();

	//check to see if any of the spaces pointed to by pointers in ant's locationMemory vector match the coordinates east of our space
	for (int e = 0; e < getLocationMemory().size(); ++e)
	{
		if (getLocationMemory().at(e)->getXCoord() == eastXCoord && getLocationMemory().at(e)->getYCoord() == eastYCoord)
		{
			location->setSpaceTypeEast(getLocationMemory().at(e)->getSpaceTypeHere());
			break;
		}
	}

	//if none found, check to see if any of the spaces pointed to by pointer in ant's locationMemory vector are also adjacent to the coordinates east of our space
	for (int k = 0; k < getLocationMemory().size(); ++k)
	{
		//check for any space objects adjacent to the coordinates in question on the north side
		if (getLocationMemory().at(k)->getXCoord() == eastXCoord && getLocationMemory().at(k)->getYCoord() == eastYCoord + 1)
		{
			location->setSpaceTypeEast(getLocationMemory().at(k)->getSpaceTypeSouth());
			break;
		}
		//check for any space objects adjacent to the coordinates in question on the south side
		if (getLocationMemory().at(k)->getXCoord() == eastXCoord && getLocationMemory().at(k)->getYCoord() == eastYCoord - 1)
		{
			location->setSpaceTypeEast(getLocationMemory().at(k)->getSpaceTypeNorth());
			break;
		}
		//check for any space objects adjacent to the coordinates in question on the east side
		if (getLocationMemory().at(k)->getXCoord() == eastXCoord + 1 && getLocationMemory().at(k)->getYCoord() == eastYCoord)
		{
			location->setSpaceTypeEast(getLocationMemory().at(k)->getSpaceTypeWest());
			break;
		}
		//our space is adjacent to the coordinates in question to the west, so don't check that
	}

	//check spaceType of coordinates to the west
	int westXCoord = getXCoord() - 1;
	int westYCoord = getYCoord();

	//check to see if any of the spaces pointed to by pointers in ant's locationMemory vector match the coordinates west of our space
	for (int w = 0; w < getLocationMemory().size(); ++w)
	{
		if (getLocationMemory().at(w)->getXCoord() == westXCoord && getLocationMemory().at(w)->getYCoord() == westYCoord)
		{
			location->setSpaceTypeWest(getLocationMemory().at(w)->getSpaceTypeHere());
			break;
		}
	}

	//if none found, check to see if any of the spaces pointed to by pointer in ant's locaionMemory vector are also adjacent to the coordinates west of our space
	for (int m = 0; m < getLocationMemory().size(); ++m)
	{
		//check for any space objects adjacent to the coordinates in question on the north side
		if (getLocationMemory().at(m)->getXCoord() == westXCoord && getLocationMemory().at(m)->getYCoord() == westYCoord + 1)
		{
			location->setSpaceTypeWest(getLocationMemory().at(m)->getSpaceTypeSouth());
			break;
		}
		//check for any space objects adjacent to the coordinates in question on the south side
		if (getLocationMemory().at(m)->getXCoord() == westXCoord && getLocationMemory().at(m)->getYCoord() == westYCoord - 1)
		{
			location->setSpaceTypeWest(getLocationMemory().at(m)->getSpaceTypeNorth());
			break;
		}
		//our space is adjacent to the coordinates in question to the east, so don't check that
		//check for any space objects adjacent to the coordinates in question on the west side
		if (getLocationMemory().at(m)->getXCoord() == westXCoord - 1 && getLocationMemory().at(m)->getYCoord() == westYCoord)
		{
			location->setSpaceTypeWest(getLocationMemory().at(m)->getSpaceTypeEast());
		}
	}
}

/******************************************************************************
*	Ant::interpretAction
*	Interprets the result of the current space's action function.
******************************************************************************/
void Ant::interpretAction(int resultIn)
{
	//switch to determine what to do with results based on spaceType
	switch (getCurrentLocation()->getSpaceTypeHere())
	{
	//0 = Home -> drop off food
	case 0:
	{
		if (getCurrentCrop() != 0)
		{
			cout << "\nYou present the food in your crop to your sisters." << endl;
			cout << "They're proud that you're trying your best." << endl;

			//tally points
			int pointsEarned = 0;
			for (int i = 0; i < ARRAY_SIZE; ++i)
			{
				//special ending unlocked if player brings back doodle-meat

				if (antInventory[i] == 50 && getDoodleHuntEnding() == false)
				{
					cout << "\nYour sisters look cautiously at the doodle-meat." << endl;
					cout << "A few cautiosly take a bite... and find it... delicious!" << endl;
					cout << "They rush off to inform Her Royal Majesty the Queen of your discovery." << endl;
					setDoodleHuntEnding(true);
				}

				//add points to the total earned for this drop-off and set that number back to zero
				pointsEarned += antInventory[i];
				antInventory[i] = 0;
			}
			//add tallied points to player's total points
			setCurrentPoints(getCurrentPoints() + pointsEarned);
			cout << "\nYou earned " << pointsEarned << " points!" << endl;
			cout << "Total Points: " << getCurrentPoints() << endl;

			//player can choose to retire while at the home space
			string retire = "0";
			cout << "\nYou have successfully foraged for the day." << endl;
			cout << "You can either retire for the day(end the game) or continue exploring for the glory of the colony!" << endl;
			cout << "[1]: Retire (Quit Game)" << endl;
			cout << "[2]: Continue Exploring (For the Glory of the Colony!)" << endl;
			cout << "Choice: ";
			cin >> retire;
			switch (menuChoice(retire, 2))
			{
				//1 = end game
			case 1:
			{
				cout << "\nAnother long day of exploring has finally come to an end. You prepare to rest in the sanctuary of the nest" << endl;
				cout << "Whatever challenges tomorrow may bring, you're confident that the colony, in all it's unfathomable glory, will pervail." << endl;
				setAlive(false);
				break;
			}
			//2 = continue game
			case 2:
			{
				cout << "\nAn ant's work is never done. You choose to continue exploring. For the Glory of the Colony!" << endl;
				break;
			}
			}
		}
		else
		{
			cout << "You have no food to store in the nest right now." << endl;
			setCurrentThirst(getCurrentThirst() + 1);				//so the player doesn't lose thirst not doing anything
			setTurnCounter(getTurnCounter() - 1);					//so clock doesn't advance with player not doing anything
		}
		break;
	}
	//1 = Asphalt -> scavenge for meat
	case 1:
	{
		if (resultIn != 0)
			addFood(resultIn);
		break;
	}
	//2 = Grass -> scavenge for fruit
	case 2:
	{
		if (resultIn != 0)
			addFood(resultIn);
		break;
	}
	//3 = Puddle -> drink
	case 3:
	{
		setCurrentThirst(getCurrentThirst() + resultIn);
		if (getCurrentThirst() > getMaxThirst())
		{
			setCurrentThirst(getMaxThirst());
		}
		break;
	}
	}
}

/******************************************************************************
*	Ant::displayDoodleEnding
*	Displays the text that appears when the player unlocks the doodle-hunt ending.
******************************************************************************/
void Ant::displayDoodleEnding()
{
	cout << "\nFor as long as any ant can remember, doodlebugs have been the sworn enemy of your colony..." << endl;
	cout << "Their ferocious nature makes them formidable foes. Too powerful for any single colony to combat..." << endl;
	cout << "Your colony, plagued by the doodle-menace, has been forced to explor only during the day, for fear of doodle-attacks..." << endl;
	cout << "But now, thanks to your incredible discovery, your colony knows the sweet taste of doodle-meat..." << endl;
	cout << "By royal decree of Her Royal Majesty the Queen, an alliance has been formed between your colony and several other colonies in the region..." << endl;
	cout << "This super-colony will reign terror on the acursed doodle-menace, and sup on the flesh of all doodle-kind..." << endl;
	cout << "The Great Doodle-Hunt Has Begun! Oh, how the tables have turned ;)" << endl;
}