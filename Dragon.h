#ifndef DRAGON_H
#define DRAGON_H
#include "Character.h"
//commenting in cc file
class Dragon : public Character
{
  public:
    Dragon();
    ~Dragon();
    void move(int = 0);
  private:
    bool dir = false;
};

#endif
