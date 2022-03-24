#include <iostream>
using namespace std;
#include <string>
#include "Character.h"

//Character Class
//Objective: Character is an abstract class that is the basics of what a player in Dragons hollow should be. There should never be a Character Object made, but all players will share the Character functions.

//initialize character values
Character::Character(string name, int h, int s, int a, char sym,int id){
  charName = name;
  armor = a;
  health = h;
  strength = s;
  symbol = sym;
  ID = id;
}

//dtor
//Character::~Character(){}

//All the getters.
int Character::getArmor(){return armor;}
int Character::getHealth(){return health;}
int Character::getStrength(){return strength;}
char Character::getSymbol(){return symbol;}
int Character::getXPos(){return xPos;}
int Character::getYPos(){return yPos;}
int Character::getId(){return ID;}
string Character::getName(){return charName;}
bool Character::hasMoved(){return motion;}
bool Character::hasBeenChecked(){return checked;}

//all the setters.
void Character::setChecked(){checked = true;}
void Character::resetChecked(){checked = false;}
void Character::setMoved(){motion = true;}
void Character::resetMoved(){motion = false;}
void Character::setHealth(int h){health = h;}
void Character::setSymbol(char s){symbol = s;}
void Character::setXPos(int x){xPos = x;}
void Character::setYPos(int y){yPos = y;}

//print (FOR DEBUGGING)
void Character::print(){
  cout<< "I am: " << getName() << ", I have: " << ID << " as my ID." << endl;
}
