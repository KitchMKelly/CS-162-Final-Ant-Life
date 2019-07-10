/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/16/2019
** Description: asphaltClass.hpp is the Asphalt class specification file.
**	Asphalt class inherits from Space class.
******************************************************************************/
#ifndef ASPHALT_CLASS
#define ASPHALT_CLASS
#include "spaceClass.hpp"
class Asphalt : public Space
{
private:
public:
	Asphalt(int xCoordIn, int yCoordIn);
	~Asphalt();
	int action();
	void displayIntro();
};
#endif