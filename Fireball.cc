#include <iostream>
using namespace std;
#include <string>
#include "Character.h"
#include "Fireball.h"

//Fireball Class Objective
//for the fireball class, we will allow the damage to be done by the control arm, all the fireball does
//in its class is provide the item stats for the control to do the damage.

//default ctor, calls the abstract ctor.
Fireball::Fireball(string name, int h, int s, int a, char sym, int id) : Character(name,1000,s,a,sym,id){

}

Fireball::~Fireball(){

}

void Fireball::move(int l){
  //since the fireball does not move, nothing should change
}
