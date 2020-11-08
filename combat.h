#ifndef CORONAMANIA_COMBAT_H
#define CORONAMANIA_COMBAT_H

#include "command.h"
#include "Character.h"

class Combat {
private:
	Character* player;
	Character virus;
	bool readCommand(string s);

public:
	Combat(Character*&, Character&);
	void attack(); 

    //Character Actions
	void heal();


	void defend();
	void item();


    //Virus Actions
	void infection();

};

#endif //CORONAMANI_PROJECT_COMBAT_H
