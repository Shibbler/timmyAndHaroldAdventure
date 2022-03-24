#ifndef CHARACTER_H
#define CHARACTER_H

//parent class for all questplayers
//main commenting in cc file
class Character
{
  public:
    string charName;
    Character(string="DEFAULT",int=10,int=1,int = 0, char = '#',int = 0);
    //~Character();
    int getHealth();
    int getArmor();
    int getStrength();
    char getSymbol();
    int getXPos();
    int getYPos();
    string getName();
    int getId();
    bool hasBeenChecked();
    bool hasMoved();
    void setChecked();
    void setMoved();
    void resetMoved();
    void resetChecked();
    void setHealth(int h);
    void setSymbol(char s);
    void setYPos(int y);
    void setXPos(int x);
    void print();
    //Abstract
    virtual void move(int) = 0;

  private:
    bool checked = false;
    bool motion = false;
    int ID;
    int xPos;
    int yPos;
    char symbol;
    int health;
    int strength;
    int armor;
};

#endif
