#ifndef FIREBALL_H
#define FIREBALL_H
#include "Character.h"
//commenting in cc file
class Fireball : public Character
{
  public:
    Fireball(string="DEFAULT",int=10,int=1,int = 0, char = '@', int = 0);
    ~Fireball();
    void move(int = 0);
  private:
};

#endif
