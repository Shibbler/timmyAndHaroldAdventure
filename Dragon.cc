#include <iostream>
using namespace std;
#include <string>
#include "Character.h"
#include "Dragon.h"

//Dragon Class
//Objective: This is an implementation of the abstract Character class, that gives a concrete definition to move.
//the dragon has a move function, but the rest of his functionality is handled inside of control (collisions, death)

//default ctor, calls the abstract ctor.
Dragon::Dragon():Character("Dragon",100,100,100,'D',0){

}
//default dtor
Dragon::~Dragon(){

}

//calls the dragon to move
void Dragon::move(int num){
  //if the dragon is at an edge, he should reverse his direction
  if (getYPos() == 1){
   dir = false;
  }
  if (getYPos() == 5){
    dir = true;
  }
  //if dir is true, he should walk 'up'
  if(dir){
    setYPos(getYPos() - 1);
  }
  //if false, moves 'down'
  else{
    setYPos(getYPos() + 1);
  }
}
