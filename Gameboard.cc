#include <iostream>
using namespace std;
#include <string>
//#include "MyList.cc"
#include "Gameboard.h"

//Gameboard Class
//Objective: The gameboard class has a 2D MyListof chars, which it turns into the "gameboard" based on MAXROW and MAXCOL. It is used in control to serve the purpose of the visual 'map'.

//this will create the initial gameboard. It is dynamic, so a larger board can be made.
Gameboard::Gameboard(){
  //define chars
  char sidewall = '|';
  char space = ' ';
  char entrance = '=';
  char topbotwall = '-';
  //loop controlling rows
  for (int r = 0; r< MAXROW;r++){
    //loop controlling columns
    for (int c = 0; c< MAXCOL; c++){

      //side walls with entrance
      if( (c == (MAXCOL - 1)) && (r < 2 || r > 4)) {
        //cout << "I'm adding a sidewall" << endl;
        board.add(r,c,sidewall);
      }

      //sidewalls no entrance
      else if (c == 0){
        board.add(r,c,sidewall);
      }
      //cave entrance
      else if (c == (MAXCOL - 1) && (r<=4 && r >= 2)) {
        //cout << "I'm adding an entrance" << endl;
        board.add(r,c,entrance);
      }
      //bottom and top walls
      else if ( (c > 0 && c < (MAXCOL - 1)) && ( (r == 0) || (r == (MAXROW - 1)) ) ) {
        //cout << "I'm adding a topbotwall" << endl;
        board.add(r,c,topbotwall);
      }
      //empty spaces
      else{
        //cout << "I'm adding nothing" << endl;
        board.add(r,c, space);
      }
    }
  }
}

Gameboard::~Gameboard(){

}

//a function to print the gameboard, calls MyList's print method
void Gameboard::print(){
  board.print();
}
