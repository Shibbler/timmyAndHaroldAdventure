#include <iostream>
using namespace std;
#include <string>

#include "View.h"


//View Class
//Objective: The view class is responsible for all the functions that gather user input or display elements to terminal

//please note: this class has functions demo-ed in class by Christine Larendeau. Full credit should be given for the printstr, readInt and readStr methods.


//a function to show the menu for placing the fireball
void View::showMenu(int& choice){
  //ask user for yes or no
  cout << "Would you like to place the Fireball?\nIt will radiate 2 damage every turn to everyone around it." <<endl;
  //ensure they enter correct input
  while (choice < 0 || choice > 1) {
    cout << "Please type 0 for No, and 1 for Yes: "<<endl;
    cin >> choice;
  }

}

//a function to show the menu for placing the arrowwall
void View::showMenuArrow(int& choice){
  //ask user for yes or no
    cout << "Would you like to place the Arrow Wall?\nIt will damage anyone in front of it (y axis) by 1 every turn" <<endl;
    //ensure they enter correct input
    while (choice < 0 || choice > 1) {
      cout << "Please type 0 for No, and 1 for Yes: "<<endl;
      cin >> choice;
    }
}

//a function to print the given string
void View::printStr(string str){
  cout << str<<endl;
}

//a function to print the game board
void View::printMap(Gameboard game){
  game.print();
}

//a function to read an integer input into a given variable n.
void View::readInt(int& n){
  cin >> n;
}

//a function to read a string input into a given variable n.
void View::readStr(string& str){
  cin >> str;
}
