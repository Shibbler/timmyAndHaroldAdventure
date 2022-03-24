#include <iostream>
using namespace std;
#include <string>
#include "Character.h"
#include "ArrowWall.h"

//Arrowwall Class Objective
//for the arrowwall class, we will allow the damage to be done by the control arm, all the arrowall does
//in its class is provide the item stats for the control to do the damage, as well as providing location.

//default ctor, calls the abstract ctor.
ArrowWall::ArrowWall(string name, int h, int s, int a, char sym, int id) :Character(name,1000,s,a,sym,id){

}

ArrowWall::~ArrowWall(){

}

//the arrowWall should never move, so we will leave this blank. It exists so polymorphically it can be called, and since it never changes x or y positions, its position is always valid.
void ArrowWall::move(int dir){

}
