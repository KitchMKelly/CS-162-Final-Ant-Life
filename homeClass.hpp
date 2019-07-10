/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: homeClass.hpp is the Home class specification file.
**	Home class inherits from Space class, and is the entry point to the Ant's colony.
******************************************************************************/
#ifndef HOME_CLASS
#define HOME_CLASS
#include "spaceClass.hpp"
class Home : public Space
{
private:
public:
	Home(int xCoordIn, int yCoordIn);
	~Home();
	int action();
	void displayIntro();
};
#endif