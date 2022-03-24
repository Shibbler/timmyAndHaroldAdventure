#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "MyList.cc"
//commenting in cc file
class Gameboard
{
  public:
    MyList<char> board;
    Gameboard();
    ~Gameboard();
    void print();

  private:
};
#endif
