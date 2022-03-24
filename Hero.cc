#include <iostream>
using namespace std;
#include <string>
#include "Character.h"
#include "Hero.h"

//Hero Class
//Objective: This is an implementation of the abstract Character class, that gives a concrete definition to move.
//the Hero has their personalized move function, but otherwise, attacking, death and victory are all handled in control
//The hero class will be used to represent timmy and harold.

//default ctor, calls the abstract ctor.
Hero::Hero(string name, int h, int s, int a, char sym, int id) :Character(name,h,s,a,sym,id){
}

Hero::~Hero(){

}

//calls the Hero to move
void Hero::move(int dir){
  //moves right
  setXPos(getXPos() + 1);
  //up
  if (dir == 1){
    setYPos(getYPos() + 1);
  }
  //down
  else if (dir == 2){
    setYPos(getYPos() - 1);
  }
  //if it was 0, we do not move y.

  //the hero object doesn't care if it is out of bounds, only the game does, so the functionality
  //for checking will be within control
}
