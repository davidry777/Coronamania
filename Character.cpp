#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

Character::Character() {
	name = "none";
	hp = 0;
    infection = 1.2;
	level = 0;
	xp = 0;
	damageTaken = 0;
	critChance = 0;
	defense = 0;
	life = true;
}

Character::Character(string n) {
	name = n;
	hp = 100;
    infection = 1.2;
	level = 0;
	xp = 0;
	damageTaken = 0;
	critChance = 10;
	defense = 8;
	life = true;
}

Character::Character(string name, double hp, double infection, int level, int xp, double damageTaken, double critChance, int defense, bool alive) {
	this->name = name;
	this->hp = hp;
    this->infection = infection;
	this->level = level;
	this->xp = xp;
	this->damageTaken = damageTaken;
	this->critChance = critChance;
	this->defense = defense;
	this->life = true;
}

void Character::incLeveL(int xp) {
	this->xp += xp;
	if (level == 1) {
		if (xp > 15)
			level++;
		xp -= 15;
	}
	else if (level == 2) {
		if (xp > 30) {
			level++;
			xp -= 30;
		}
	}
	else if (level == 3) {
		if (xp >= 45) {
			level++;
			xp -= 45;

		}
	}
	else if (level == 4) {
		if (xp >= 70) {
			level++;
			xp -= 70;
		}
	}
	else if (level == 5) {
		if (xp >= 100) {
			return;
		}
	}
}

void Character::takeDamage(double dmg) {
	hp -= dmg;
    if ((rand() % 2) == 0)
        hp -= infection;
}

void Character::addHP(double h) {
	hp += h;
}

void Character::addDefense(int d) {
	defense += d;
}

void Character::setInfection(int i) {
    infection = i;
}


const double Character::getHP() const {
	return hp;
}


void Character::status() {
	int h = getHP();
	cout << "HP: " << h << "Left" << endl;
	cout << "Level: " << level << endl;
}
void Character::equip(string item) {
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        if (inventory.at(i) == item) {
          inventory.at(i) = inventory.back();
          inventory.pop_back();
          return;
      }
    }
}

const string Character::getName() const {
	return name;
}

const int Character::getLevel() const {
	return level;
}

const int Character::getXP() const {
	return xp;
}

const double Character::getDamageTaken() const {
	return damageTaken;
}

const int Character::getDefense() const {
	return defense;
}

const bool Character::getLife() const {
	if (hp == 0) {
		return false;
	}
	return true;
}

const int Character::getInfection() const {
    return infection;
}

const Item Character::getEquip(string item) {
	for (unsigned int i = 0; i < inventory.size(); ++i) {
        if (inventory.at(i) == item)    // FIXME: have it check for strings
            return inventory.at(i);
}