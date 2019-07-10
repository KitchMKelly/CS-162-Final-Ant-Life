/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: grassClass.hpp is the Grass class specification file.
**	Grass class inherits from Space class.
******************************************************************************/
#ifndef GRASS_CLASS
#define GRASS_CLASS
#include "spaceClass.hpp"
class Grass : public Space
{
private:
public:
	Grass(int xCoordIn, int yCoordIn);
	~Grass();
	int action();
	void displayIntro();
};
#endif
