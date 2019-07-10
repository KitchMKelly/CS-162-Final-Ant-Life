/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: puddleClass.hpp is the Puddle class specification file.
**	Puddle class inherits from Space class.
******************************************************************************/
#ifndef PUDDLE_CLASS
#define PUDDLE_CLASS
#include "spaceClass.hpp"
class Puddle : public Space
{
private:
public:
	Puddle(int xCoordIn, int yCoordIn);
	~Puddle();
	int action();
	void displayIntro();
};
#endif
