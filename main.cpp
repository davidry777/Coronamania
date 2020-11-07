#include <string>
#include <iostream>
#include "Command.h"
#include "Character.h"

using namespace std;
using namespace Print;

Game::Game() {
	flu = new Character("Mummy", 30, 20, 1, 0, 35, 0, 0, 2, 1, 0, 5, true);
	ebola = new Character("Slime", 50, 30, 2, 0, 55, 0, 10, 4, 2, 0, 8, true);
	corona = new Character("Minotaur", 1000, 40, 3, 0, 70, 0, 10, 5, 6, 0, 12, true);
	
	key = new Item("key", 0, 0, 0, 0);
	cellKey = new Item("cellKey", 0, 0, 0, 0);
	sword = new Item("sword", 15, 0, 0, 0);
	shield = new Item("shield", 0, 15, 0, 0);
	healthPotion = new Item("health potion", 0, 0, 30, 0);
	manaPotion = new Item("meana potion", 0, 0, 0, 30);
	createRooms();
}

void Game::createCountries() {
	Room* country1 = new Country("Croatia");
	Room* country2 = new Country("Africa");
    Room* country3 = new Country("USA");

	// create the rooms;
	flucountry = new Country("are in Croatia, where influenza activiy is an all-time high. Ostati siguran"); //room 1
    ebolacountry = new Country("are in Africa, where ebola activiy is an all-time high. Kaa salama");
    covidcountry = new Country("are in the United States of America, where the coronavirus has taken over our country. God Save America.");
	
	exit = new Country(""); // finish the game

	// initialise room exits   
	// entrance & mummy -> room1, slime -> room 2, puzzle door lead to room 3, minotaur -> room 4, puzzle key -> big boss);

	//dungeon.setExit("north", dungeon);

	country1->setExit("north", country2);
	country1->setExit("south", country3);

	country2->setExit("north", country1);
	country2->setExit("south", country3);

    country3->setExit("north", country1);
	country3->setExit("south", country2);
}

void Game::printWelcome()
{
	cout << ("Welcome!");
	cout << ("Type 'help' if you need help.");
	/*cout << Long(" ");
	cout << Long(" ");
	cout << Long("...");
	cout << Long(" ");
	cout << Long(" ");
	cout << Long("...");
	cout << Long(" ");
	cout << Long(" ");*/
	cout << ("You wake up laying down in a dark place.") << endl;
	/*cout << Long(" ");
	cout << Long(" ");
	cout << Long("...");
	cout << Long(" ");
	cout << Long(" ");*/
	cout << ("After you realize you're conscious, you feel around. You seem to be confined in a rectangular shape. You push on the top of this 'box'.") << endl;
	//cout << Long(" ");
	cout << ("You are very weak but you manage to push the top off. You are greeted with a dull light. After you push the top off, you sit up.") << endl;
	//cout << Long(" ");
	cout << ("Sitting up, you realize that you are in a tomb. You don't know what to make of this.") << endl ;
	//cout << Long(" ");
	cout << ("You are very hungry right now.") << endl;
	//cout << Long(" ");
	//cout << Long(" ");
	//cout << (currentRoom.getLongDescription());
	cout << "fuck the current room description" << endl;
	cout << endl;
}

void Game::printHelp() {
	std::cout << "You are lost. You are alone. You wander" << endl;
	std::cout << "in this seemingly hopeless dungeon." << endl;
	cout << endl;
	cout << "Your command words are:" << endl;
	Command().showAll();
}

void Game::engage(Command command) {
	if (!command.hasSecondWord()) {
		cout << "Engage who?" << endl;
		return;
	}
	string name = command.getSecondWord();
	if (currentRoom->returnNPC(name)) {
		Character npc = currentRoom->getNPC(name);
		Combat* rpg = new Combat(p1, npc);
		rpg->engage();
	}
	else {
		cout << "You cannot engage that." << endl;
	}
}
void Game::goRoom(Command command)
{
	if (!command.hasSecondWord()) {
		// if there is no second word, we don't know where to go...
		cout << ("Go where?");
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room nextRoom = currentRoom->getExit(direction);

	if (nextRoom.getShortDescription() == "") {
		cout << ("You cannot go that way.") << endl;
	}
	else {
		if (!nextRoom.checkLock()) {
			if (currentRoom->checkNPC()) {
				*currentRoom = nextRoom;
				if (nextRoom.getShortDescription() == "guardroom") {
					cout << "There's a skeleton!" << endl;
				}
				cout << ("You walk to the " + direction + " door. ");
				//cout << Long("");
				cout << currentRoom->getLongDescription() << endl;
				cout << "Current Status\n";
				p1->updateStatus();
			}
			else if (currentRoom->returnNPC("guard")) {
				if (currentRoom->getNPC("guard").checkTied()) {
					cout << ("You cannot go that way. The guard might be alerted if you just walk there!");
					return;
                }
				else {
					*currentRoom = nextRoom;
					if (nextRoom.getShortDescription() == "guardroom") {
						cout << "There's a skeleton!" << endl;
					}
					cout << ("You walk to the " + direction + " door. ");
					//cout << Long("");
					cout << currentRoom->getLongDescription() << endl;
					cout << "Current Status\n";
					p1->updateStatus();
				}
			}
			else if (currentRoom->returnNPC("minotaur")) {
				if (currentRoom->getNPC("minotaur").getAlive()) {
					cout << ("You cannot get past the big minotaur.");
					return;
				}
				else {
					*currentRoom = nextRoom;
					if (nextRoom.getShortDescription() == "guardroom") {
						cout << "There's a skeleton!" << endl;
					}
					cout << ("You walk to the " + direction + " door. ");
					//cout << Long("");
					cout << currentRoom->getLongDescription() << endl;
					cout << "Current Status\n";
					p1->updateStatus();
				}
			}
        }
		else {
			cout << ("That door is locked.");
		}
	}
	//p1->status();
}

bool Game::quit(Command command)
{
	if (command.hasSecondWord()) {
		cout << ("Quit what?");
		return false;
	}
	else {
		return true;  // signal that we want to quit
	}
}

void Game::equip(Command command) {
	if (!command.hasSecondWord()) {
		cout << ("Equip what?");
		return;
	}
	string item = command.getSecondWord();
	if (p1->checkEquip(item)) {
		if (item._Equal("sword")) {
			p1->equip(item);
			p1->addStrength(p1->getItem(item).getStrength());
			//p1->addHR();
			cout << ("You have equipped the sword. You feel stronger with this in your hand!");
		}
		else if (item._Equal("shield")) {
			p1->equip(item);
			p1->addDefense(p1->getItem(item).getDefense());
			cout << ("You have equpped the shield. You feel you can take a hit from anything!");
		}
		else if (item._Equal("necklace")) {
			p1->equip(item);
			cout << ("You have equipped the necklacke. You feel a new sense of arcane power in you.");
			p1->addMagic(10);
			p1->addMana(50);
		}
		else {
			cout << ("You cannot equip that.");
		}
	}
	else {
		cout << ("You cannot equip something that you don't have.");
		return;
	}
}

bool Game::processCommand(Command command)
{
	bool wantToQuit = false;
	string commandWord = command.getCommandWord();
	if (commandWord == "HELP") {
		printHelp();
		wantToQuit = true;
	}
	else if (commandWord == "GO") {
		goRoom(command);
		wantToQuit = true;
	}
	else if (commandWord == "QUIT") {
		wantToQuit = quit(command);
		return true;
	}
	else if (commandWord == "GRAB") {
		grab(command);
		wantToQuit = true;
	}
	else if (commandWord == "ENGAGE") {
		engage(command);
		wantToQuit = true;
	}
	else if (commandWord == "LOOK") {
		cout << (currentRoom->getLongDescription()) << endl;
		wantToQuit = true;
	}
	else if (commandWord == "SNEAK") {
		//sneak(command);
		return true;
	}
	else if (commandWord == "USE") {
		//use(command);
		wantToQuit = true;
	}
	else if (commandWord == "INVENTORY") {
		cout << (p1->getItemKey()) << endl;
		wantToQuit = true;
	}
	else if (commandWord == "EQUIP") {
		equip(command);
		wantToQuit = true;
	}
    else {
		cout << "I don't know what you mean..." << endl;
		wantToQuit = true;
	}
	return wantToQuit;
}

void Game::play() {
	string name;
	std::cout << "Please enter hero name: " << endl;
	cin >> name;
	p1 = new Character(name);
	//p1->startStamina();
	printWelcome();
	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the game is over.
	bool running = true;
	bool firstRun = true;
	while (running && p1->getAlive()) {
		if (firstRun) {
			cin.ignore();
			firstRun = false;
		}
		cout << "What do you want to do? " << endl;
		Command command = this->parser->getCommand();
		if (running = processCommand(command) || currentRoom->checkExits()) {
		
		}
		if (p1->getHP() < 1) {
			std::cout << "You have fallen in battle." << endl;
			running = false;
		}
	}
	
	std::cout << "Thank you for playing.  Good bye." << endl;
}

int main() {
	Game* g1 = new Game();
	g1->play();
}