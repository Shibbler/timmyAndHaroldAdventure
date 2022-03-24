#include <iostream>
using namespace std;
#include <string>
#include "Character.h"
#include "Fighter.h"
//default ctor, calls the abstract ctor.

//Fighter Class
//Objective: This is an implementation of the abstract Character class, that gives a concrete definition to move.
//the fighter has their personalized move function, but otherwise, attacking and death are handled in control
//the fighter class will be used to represent the borcs, porcs, and dorcs.

Fighter::Fighter(string name, int h, int s, int a, char sym, int id) :Character(name,5,s,a,sym,id){
  //health will always begin with health five.
}

Fighter::~Fighter(){

}

//calls the fighter to move
void Fighter::move(int dir){
  //moves left
  setXPos(getXPos() -1);
  //up
  if (dir == 1){
    setYPos(getYPos() + 1);
  }
  //down
  else if (dir == 2){
    setYPos(getYPos() - 1);
  }
  //if it was 0, we do not move y.
}
