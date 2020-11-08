#include "Combat.h"
#include "Character.h"
#include "Command.h"
#include <iostream>


Combat::Combat(Character*& player, Character& virus) {
	this->player = player;
	this->virus = virus;
}


bool Combat::readCommand(string s) {
	Command commandWord(s);
	if (commandWord.getCommandWord() == "ATTACK") {
			attack();
			return false;
		}

	else if (commandWord.getCommandWord() == "DEFEND") {
	
			defend();
			return false;
		}
		
	else if (commandWord.getCommandWord() == "ITEM") 
        {
			item();
			return false;
		}
	else if (commandWord.getCommandWord() == "QUIT") {
		return true;
	}
    else if (commandWord.getCommandWord() == "USE") {
		return true;
	}
    else if (commandWord.getCommandWord() == "INVENTORY") {
		return true;
	}
	else {
		cout << "I don't know what you mean... " << endl;
		return false;
	}
}

void Combat::attack() {
	int hit = rand() % 101;
	if (hit > player->getHitRate()) {
		int temp = player->getStrength() - virus.getDefense();
		int crit = rand() % 101;
		if (crit > player->getCritChance()) {
			temp *= 2;
		}
		int dmg = temp + rand() % 3;
		virus.takeDamage(dmg);



		if (player->checkEquip("sword")) {
			cout << "SLASH" << endl;
			cout << "You Slash " << virus.getName() << "for " << dmg << "damage!" << endl;
		}
		else if (player->checkEquip("fist")) {
			cout << "BAAM" << endl;
			cout << "You punch " << virus.getName() << "for " << dmg << "damage!" << endl;
		}



	}
	else {
		cout << "WHOOSH" << endl;
		cout << "Your attack misses its mark!" << endl;
	}



	if (virus.getHP() <= 0) {
		cout << "You have defeated the " << virus.getName() << "!" << endl;
	}
}


void Combat::item() {
	cout << "What item do you want to use? " << endl;
	
}

Combat::Combat(Character*& player, Character& virus) {


	this->player = player;


	this->virus = virus;


}


bool Combat::readCommand(string s) {


	Command commandWord(s);


	if (commandWord.getCommandWord() == "ATTACK") {

			attack();
			return false;
		}

	else if (commandWord.getCommandWord() == "DEFEND") {

			defend();
			return false;

		}
		else {
			return false;

		}
	}

	else if (commandWord.getCommandWord() == "ITEM") {
		if (player->getSpeed() > virus.getSpeed()) {
			item();
			bestvirusMove();
			return false;
		}
		else {
			bestvirusMove();
			item();
			return false;
		}
	}

	else if (commandWord.getCommandWord() == "QUIT") {
		return true;
	}

	else {
		cout << "I don't know what you mean... " << endl;
		return false;
	}
}

void Combat::attack() {
	int hit = rand() % 101;

	if (hit > player->getHitRate()) {
		int temp = player->getStrength() - virus.getDefense();
		int crit = rand() % 101;

		if (crit > player->getCritChance()) {
			temp *= 2;
		}

		int dmg = temp + rand() % 3;
		virus.takeDamage(dmg);

		if (player->checkEquip("sword")) {
			cout << "SLASH" << endl;
			cout << "You Slash " << virus.getName() << "for " << dmg << "damage!" << endl;
		}
		else if (player->checkEquip("fist")) {
			cout << "BAAM" << endl;
			cout << "You punch " << virus.getName() << "for " << dmg << "damage!" << endl;
		}

	}

	else {
		cout << "WHOOSH" << endl;
		cout << "Your attack misses its mark!" << endl;
	}

	if (virus.getHP() <= 0) {
		cout << "You have defeated the " << virus.getName() << "!" << endl;
	}
}

void Combat::item() {
	cout << "What item do you want to use? " << endl;
}

void Combat::defend() {
	cout << "You reinforce your defenses-> " << endl;
	player->addDefense(player->getDefense() * 1.25);
}
	if (!player->getAlive()) {
		cout << "You have been defeated by the " << virus.getName() << endl;
	}
}

void Combat::virusmutation(){
	cout << virus.getName() << " mutates" << endl;
	virus.addDefense(virus.getDefense() * 1.25);
}
