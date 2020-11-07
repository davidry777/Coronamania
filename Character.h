#ifndef CORONAMANIA_CHARACTER_H
#define CORONAMANIA_CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
// #include "Item.h"

using namespace std;

class Character {
private:
	string name;
	double hp;
    double infection;
	int level;
	int xp;
	double damageTaken;
	double critChance;
	int defense;
	bool alive;
	vector<Item> inventory;
	vector<Item> equiped_items;

public:
	Character();
	Character(string name);
	Character(string name, double hp, double infection, int level, int xp, int damage, double damageTaken, double critChance, int defense, bool alive);
	const string getName() const;
	const double getHP() const;
	const double getInfection() const;
    const int getXP() const;
    const double getDamageTaken() const;
    const double getCriticalChance() const;
    const int getDefense() const;
    const bool getLife() const;   
	void increaseLeveL(int exp);
	void takeDamage(double dmg);
	void addHP(double h);
	void addDefense(int d);
	void addCriticalChance(double c);
	void status();
	void equip(string n);
	bool checkEquip(string n);
	void changeSpeed(int s);
	bool checkTied();
	void changeTied();
	const Item getEquip(string n);
	void setItem(string, Item);
	void updateStatus();
	Item getItem(string s);
	string getItemKey() const;
};

#endif