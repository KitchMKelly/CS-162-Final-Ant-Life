/******************************************************************************
** Name:	Kitch Kelly
** Date:	3/18/2019
** Description: menuClass.cpp is the Menu class function implementation
**	file. Implements menu functionality, input validation, and gameflow logic.
******************************************************************************/
#include "menuClass.hpp"

/******************************************************************************
*	Menu::Menu()
*	Default constructor for the Menu class.
*	Creates Player class objects from infromation in "playerScore.txt" and adds
*	the Player objects to the leaderboard vector.
******************************************************************************/
Menu::Menu()
{
	string playerName;
	string playerPoints;

	//create file object for reading from playerScore.txt
	ifstream playerFile;
	playerFile.open("playerScore.txt");

	//print error if file is unable to be opened, and exit function
	if (!playerFile)
	{
		cout << "Oops! Something went wrong opening the player info file." << endl;
		return;
	}

	//check if end of file has been reached
	//if not, use inputs to make player object
	int peek = playerFile.peek();
	while (peek != EOF)
	{
		//get and store player name
		getline(playerFile, playerName);

		//get and store player score
		getline(playerFile, playerPoints);

		//create Player class object from file info and add to Player vector
		getLeaderboard().push_back(Player(playerName, stoi(playerPoints)));

		//check if eof reached
		peek = playerFile.peek();
	}

	//close file
	playerFile.close();

	setLeaderboardChanged(false);
}

/******************************************************************************
*	Menu::~Menu()
*	Default destructor for the Menu class.
*	Overwrites contents of "playerScore.txt" with updated player information from 
*	leaderboard vector. Contents of the leaderboard vector deleted when leaderboard is deleted.
******************************************************************************/
Menu::~Menu()
{
	//create file object for writing to playerScore.txt; erase current contents

	ofstream playerFile;
	playerFile.open("playerScore.txt", ios::trunc);

	//print error if file is unable to be opened, and exit function
	if (!playerFile)
	{
		cout << "Oops! Something went wrong writing to the player info file." << endl;
		return;
	}

	//write contents of leaderboard vector to playerScore.txt if leaderboardChanged is false
	if (getLeaderboardChanged() == false)
	{
		for (int i = 0; i < getLeaderboard().size(); ++i)
		{
			playerFile << getLeaderboard()[i].getName() << endl;
			playerFile << getLeaderboard()[i].getPoints() << endl;
		}
	}

	//write contents of newLeaderboard vector to playerScore.txt if leaderboardChanged is true
	else
	{
		for (int i = 0; i < getNewLeaderboard().size(); ++i)
		{
			playerFile << getNewLeaderboard()[i].getName() << endl;
			playerFile << getNewLeaderboard()[i].getPoints() << endl;
		}
	}

	//close file
	playerFile.close();

	//delete all elements in leaderboard and newLeaderboard vectors
	for (int i = 0; i < getLeaderboard().size(); ++i)
		getLeaderboard().pop_back();
	for (int i = 0; i < getNewLeaderboard().size(); ++i)
		getNewLeaderboard().pop_back();
}

/******************************************************************************
*	Menu::getLeaderboard
*	Returns the leaderboard vector.
******************************************************************************/
vector <Player>& Menu::getLeaderboard()
{
	return leaderboard;
}

/******************************************************************************
*	Menu::getNewLeaderboard
*	Returns the newLeaderboard vector.
******************************************************************************/
vector <Player>& Menu::getNewLeaderboard()
{
	return newLeaderboard;
}

/******************************************************************************
*	Menu::getLeaderboardChanged
*	Returns the member bool 'leaderboardChanged'.
******************************************************************************/
bool Menu::getLeaderboardChanged()
{
	return leaderboardChanged;
}

/******************************************************************************
*	Menu::setLeaderboardChanged
*	Sets the member bool 'leaderboardChanged' to input.
******************************************************************************/
void Menu::setLeaderboardChanged(bool changeIn)
{
	leaderboardChanged = changeIn;
}

/******************************************************************************
*	Menu::modifyLeaderboard
*	If player's point total is greater than at least the 10th place score, the
*	user will be prompted to input a name, and a new Player class object with
*	that name and that score will be created. The new top 10 scores will be
*	copied over to 'newLeaderboard', which will be used to update 'playerScore.txt'
*	The last place Player object is then deleted (to keep total at 10).
*	In the case of a tie, the new score ranks lower.
******************************************************************************/
void Menu::modifyLeaderboard(int playerScore)
{
	int position = 0;						//position in vector where new score will be inserted -> position + 1 = nth place
	string playerNameIn;

	//check if player's score is high enough to be added to the leaderboard vector
	if (playerScore > getLeaderboard().at(getLeaderboard().size() -1).getPoints())
	{	
		//determine the position where the new Player object will be added
		for (int i = getLeaderboard().size() - 1; i >= 0; --i)
		{
			if (playerScore <= getLeaderboard().at(i).getPoints())
			{
				position = i + 1;
				break;
			}
		}

		//prompt player to enter name for new score
		cout << "\nNew " << position + 1;
		switch (position + 1)
		{
		case 1:
		{
			cout << "st";
			break;
		}
		case 2:
		{
			cout << "nd";
			break;
		}
		case 3:
		{
			cout << "rd";
			break;
		}
		default:
			cout << "th";
		}
		cout << " Place Score! Congratulations!" << endl;
		cout << "Enter Name: ";
		cin.ignore(80, '\n');
		getline(cin, playerNameIn);
		
		//create new Player object
		Player newScore = Player(playerNameIn, playerScore);

		//Transfer all player objects over to newLeaderboard vector, with new Player object in correct position 
		for (int i = 0; i < getLeaderboard().size(); ++i)
		{
			if (i == position)
			{
				//add to newLeaderboard, invalidate position, and reset i
				getNewLeaderboard().push_back(newScore);
				position = -1;
				--i;
			}
			else
				getNewLeaderboard().push_back(getLeaderboard().at(i));
		}

		//pop off last Player object -> get newLeaderboard down to 10 elements
		getNewLeaderboard().pop_back();

		//set flag to use newLeaderboard in destructor
		setLeaderboardChanged(true);

		//display new leaderboard
		displayLeaderboard(getNewLeaderboard());
	}
	else
	{
		//display old leaderboard if no changes made
		displayLeaderboard(getLeaderboard());
	}
}

/******************************************************************************
*	Menu::displayLeaderboard
*	Displays the contents of the given leaderboard.
******************************************************************************/
void Menu::displayLeaderboard(vector <Player> vectorIn)
{
	cout << "\nHigh Scores:" << endl;
	cout << endl;
	for (int i = 0; i < vectorIn.size(); ++i)
	{
		cout << i + 1;
		switch (i + 1)
		{
		case 1:
		{
			cout << "st: ";
			break;
		}
		case 2:
		{
			cout << "nd: ";
			break;
		}
		case 3:
		{
			cout << "rd: ";
			break;
		}
		default:
			cout << "th: ";
		}
		cout << vectorIn.at(i).getName() << " - " << vectorIn.at(i).getPoints() << " Points" << endl;
	}
}

/******************************************************************************
*	Menu::clearScreen
*	Clears the console screen and retrns cursor to home position (top left)
******************************************************************************/
void Menu::clearScreen()
{
	cout << string(100, '\n');
}

/******************************************************************************
*	Menu::pause
*	Pauses program until user enters a key.
******************************************************************************/
void Menu::pause()
{
	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.ignore(80, '\n');
	cin.get();
}

/******************************************************************************
*	Menu::displayStatus
*	Displays the status of the game.
******************************************************************************/
void Menu::displayStatus(Ant &ant)
{
	cout << "\nAnt Status:" << endl;
	cout << "\nCurrent Points: " << ant.getCurrentPoints() << endl;
	cout << "Current Thirst: " << ant.getCurrentThirst() << "/" << ant.getMaxThirst() << endl;
	cout << "Crop Status: " << ant.getCurrentCrop() << "/" << ant.getMaxCrop() << " Filled" << endl;
	cout << "Current Time: " << ant.getTimeOfDay() << endl;
	cout << "\nWhat would you like to do?" << endl;
	cout << "[1]: Smell the Environment" << endl;
	cout << "[2]: Move North" << endl;
	cout << "[3]: Move South" << endl;
	cout << "[4]: Move East" << endl;
	cout << "[5]: Move West" << endl;
	cout << "[6]: ";
	switch (ant.getCurrentLocation()->getSpaceTypeHere())
	{
	case 0:
	{
		cout << "Deposit Food at Nest" << endl;
		break;
	}
	case 1:
	{
		cout << "Forage the Rocky Terrain for Meat" << endl;
		break;
	}
	case 2:
	{
		cout << "Forage for Grassland for Fruit" << endl;
		break;
	}
	case 3:
	{
		cout << "Drink from the Puddle" << endl;
		break;
	}
	}
	cout << "[7]: Wait" << endl;
	cout << "Choice: ";
}

/******************************************************************************
*	Menu::isDigits
*	Accepts a string as parameter, and returns true if the string contains
*	only digits (no letters or punctuation).
******************************************************************************/
bool Menu::isDigits(string &str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}

/******************************************************************************
*	Menu::displayMainMenu
*	Displays the main menu to the user.
******************************************************************************/
void Menu::displayMainMenu()
{
	cout << "\nMain Menu:" << endl;
	cout << "[1]: Play" << endl;
	cout << "[2]: About" << endl;
	cout << "[3]: Exit" << endl;
	cout << "Choice ";
}

/******************************************************************************
*	Menu::menuChoice
*	Handles user input validation for menu navigation.
*	Accepts user input as a string, and an integer representing the total
*	number of options available for that menu. Returns as an integer
*	the user's menu choice.
******************************************************************************/
int Menu::menuChoice(string &userInput, int numberMenuOptions)
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
*	Menu::mainMenu
*	Implements mainMenu navigation.
******************************************************************************/
void Menu::mainMenu()
{
	cout << "Welcome to Srsly_Chicken's Ant's Life Simulator" << endl;
	string mainMenuChoice = "0";
	while (stoi(mainMenuChoice) != 3)
	{
		displayMainMenu();
		cin >> mainMenuChoice;
		switch (menuChoice(mainMenuChoice, 3))
		{
		case 1:
		{
			play();
			break;
		}
		case 2:
		{
			displayAbout();
			break;
		}
		case 3:
		{
			cout << "\nExiting Srsly_Chicken's Ant's Life Simulator" << endl;
			cout << "Thanks for playing!" << endl;
			pause();
			break;
		}
		}
	}
}

/******************************************************************************
*	Menu::play
*	Implements gameplay.
******************************************************************************/
void Menu::play()
{
	clearScreen();
	Ant ant;
	string playerChoice = "0";
	while (ant.getAlive() == true)
	{
		displayStatus(ant);
		cin >> playerChoice;
		switch (menuChoice(playerChoice, 7))
		{
			//1 = smell
		case 1:
		{
			ant.smell();
			break;
		}
		//2 = move north
		case 2:
		{
			ant.move(1);
			break;
		}
		//3 = move south
		case 3:
		{
			ant.move(2);
			break;
		}
		//4 = move east
		case 4:
		{
			ant.move(3);
			break;
		}
		//5 = move west
		case 5:
		{
			ant.move(4);
			break;
		}
		//6 = Space type action
		case 6:
		{
			//only update thirst and counter if the action in this space hasn't been done yet
			if (ant.getCurrentLocation()->getActionCompleted() == false)
			{
				if (ant.getCurrentLocation()->getSpaceTypeHere() == 1)		//subtract 2 thirst if on asphalt (rocky terrain)
				{
					if (ant.setCurrentThirst(ant.getCurrentThirst() - 2) == false)
					{
						cout << "\nOh no! You've run out of water!" << endl;
						cout << "\"Man, I need to manage my resources better.\" you think to yourself as you slip into unconciousness." << endl;
						ant.setAlive(false);
						break;
					}
				}
				else if (ant.getCurrentLocation()->getSpaceTypeHere() == 2 
					|| ant.getCurrentLocation()->getSpaceTypeHere() == 0)		//subtract 1 if on grass or on nest
				{
					if (ant.setCurrentThirst(ant.getCurrentThirst() - 1) == false)
					{
						cout << "\nOh no! You've run out of water!" << endl;
						cout << "\"Man, I need to manage my resources better.\" you think to yourself as you slip into unconciousness." << endl;
						ant.setAlive(false);
						break;
					}
				}
				ant.setTurnCounter(ant.getTurnCounter() + 1);
			}
			ant.interpretAction(ant.getCurrentLocation()->action());
			break;
		}
		//7 = Wait until next turn
		case 7:
		{
			cout << "You stand still as time advances..." << endl;
			if (ant.getCurrentLocation()->getSpaceTypeHere() == 1)
			{
				if (ant.setCurrentThirst(ant.getCurrentThirst() - 2) == false)
				{
					cout << "Oh no! You've run out of water!" << endl;
					cout << "\"Man, I need to manage my resources better.\" you think to yourself as you slip into unconciousness." << endl;
					ant.setAlive(false);
					break;
				}
			}
			else
			{
				if (ant.setCurrentThirst(ant.getCurrentThirst() - 1) == false)
				{
					cout << "Oh no! You've run out of water!" << endl;
					cout << "\"Man, I need to manage my resources better.\" you think to yourself as you slip into unconciousness." << endl;
					ant.setAlive(false);
					break;
				}
			}
			ant.setTurnCounter(ant.getTurnCounter() + 1);
			break;
		}
		}
	}
	if (ant.getDoodleHuntEnding() == true)
		ant.displayDoodleEnding();
	cout << "\nGame Over! Final Score: " << ant.getCurrentPoints() << endl;
	modifyLeaderboard(ant.getCurrentPoints());
}

/******************************************************************************
*	Menu::displayAbout
*	Displays information about the game to the user.
******************************************************************************/
void Menu::displayAbout()
{
	cout << "\nPlay as the ant you've always wished you could be!" << endl;
	cout << "Explore the world around your nest to find food and bring it back to the colony to earn points." << endl;
	cout << "Different foods are worth different amounts of points, so make sure you explore as much as you can!" << endl;
	cout << "\nBut Beware! The world is full of dangerous challenges, just waiting for an unwary ant to eat, bake, or squish." << endl;
	cout << "The most dangerous of all is the dreaded Doodlebug! Feared above all else and the sworn enemy of your colony!" << endl;
	cout << "Luckily, Doodlebugs only hunt in the evening and at night. So as long as you're in the nest before dark, you should be safe... hopefully." << endl;
	cout << "\nGood luck and have fun playing Srsly_Chicken's Ant's Life!" << endl;
	cout << "\nPress any key to return to main menu..." << endl;
	cin.clear();
	cin.ignore(80, '\n');
	cin.get();
}