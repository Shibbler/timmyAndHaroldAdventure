#ifndef CONTROL_H
#define CONTROL_H
#include "Gameboard.h"
#include "Character.h"
#include <list>
#include <iterator>
#include "View.h"
#include "Fireball.h"
#include "ArrowWall.h"
class Control
{
  public:
    void initGame();
    Gameboard game;
    View view;
    //list of BaseClass Object Pointers
    list<Character*> questPlayers;
    //iterators for concurrent use
    list<Character*>::iterator ite = questPlayers.begin();
    list<Character*>::iterator ite2 = questPlayers.begin();
    list<Character*>::iterator ite3 = questPlayers.begin();
    list<Character*>::iterator checkIt = questPlayers.begin();
    ~Control();
    void handleDeath(Character*);
    bool placeFireball();
    bool placeArrowWall();
    void handleCollision(Character*, Character*);
    bool removeFromGame(Character*);
    void spawnToSpot(Character*,int,int);
    bool isValidLocation(int,int);
    void processTurn();
    void addFighter();
    void movePlayer(Character*);
    void cleanGame();
  private:
    //these are the environmental hazards, should be pre-defined for later reference
    Fireball* fire = new Fireball("Fireball",1,0,0,'@',50);
    ArrowWall* arrow = new ArrowWall("ArrowWall",1,1,1,'V',44);

    static int nextId;
    bool placedArrow = false;
    bool placedFireball = false;
    bool checkingPlayerDied = false;
    bool noEmerald = true;
    bool timmyDead = false;
    bool haroldDead = false;
};
#endif
