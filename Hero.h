#ifndef HERO_H
#define HERO_H
//commenting in cc file
class Hero : public Character
{
  public:
    Hero(string="DEFAULT",int=10,int=1,int = 0, char = 'H',int = 0);
    ~Hero();
    void move(int = 0);
  private:
};

#endif
