/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/18/2019
** Description: menuClass.hpp is the Menu class function specification file.
**	Implements menu functionality, input validation, and gameflow logic.
******************************************************************************/
#ifndef MENU_CLASS
#define MENU_CLASS
#include "antClass.hpp"
#include "playerClass.hpp"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;
using std::getline;
using std::stoi;

class Menu
{
private:
	vector <Player> leaderboard;
	vector <Player> newLeaderboard;
	bool leaderboardChanged;
public:
	Menu();
	~Menu();
	vector <Player>& getLeaderboard();
	vector <Player>& getNewLeaderboard();
	bool getLeaderboardChanged();
	void setLeaderboardChanged(bool changeIn);

	void modifyLeaderboard(int pointsIn);
	void displayLeaderboard(vector <Player> vectorIn);
	void clearScreen();
	void pause();
	void displayStatus(Ant &ant);
	bool isDigits(string &str);
	void displayMainMenu();
	int menuChoice(string &userInput, int numberMenuOptions);
	void mainMenu();
	void play();
	void displayAbout();
};
#endif