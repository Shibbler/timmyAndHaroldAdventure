#ifndef ARROWWALL_H
#define ARROWWALL_H
#include "Character.h"
//commenting in cc file
class ArrowWall : public Character
{
  public:
    ArrowWall(string="DEFAULT",int=10,int=1,int = 0, char = 'V', int = 44);
    ~ArrowWall();
    void move(int = 0);
  private:
};

#endif
