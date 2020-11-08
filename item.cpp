#include "item.h"
#include <string>
using namespace std;

Item::Item(string n, int healthPoints, int di) {
	name = n;
	hp = healthPoints;
	decreasedInfection = di;
}

string Item::getName() {
	return name;
}

int Item::getHP() {
	return hp;
}

int Item::getDecreasedInfection() {
	return di;
}