#ifndef FIGHTER_H
#define FIGHTER_H
#include "Character.h"
//commenting in cc file
class Fighter : public Character
{
  public:
    Fighter(string="DEFAULT",int=10,int=1,int = 0, char = 'F', int = 0);
    ~Fighter();
    void move(int = 0);
  private:
};

#endif
