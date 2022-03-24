#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;
#include "Gameboard.h"
//commenting in cc file
class View
{
  public:
    void showMenuArrow(int&);
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
    void printMap(Gameboard);
};

#endif
