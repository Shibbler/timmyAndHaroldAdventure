#include <iostream>
using namespace std;
#include <string>
#include "Control.h"
#include "Fighter.h"
#include "Hero.h"
#include "Dragon.h"

//CONTROL CLASS:
//Objective: The control class is responsible for all of the game logic. It initializes the game, moves players, calculates collisions, and removes players from the game.

//allows for static increase of ID amongst borcs, porcs, and dorcs.
int Control::nextId = 1001;

//default dtor
Control::~Control(){

}

//the random function given by Christine Larendeau
int random(int max){
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) );
	return (int)(r * max);
}

//a function to initialize the gameboard and characters, and to call processTurn.
void Control::initGame() {
  //init heroes
  Hero* timmy = new Hero("Timmy",15,3,3,'T',10);
  Hero* harold = new Hero("Harold",15,5,1,'H',11);
  //init dragon
  Dragon* dragon = new Dragon();
  //add players to gameboard, and update x,y pos
  spawnToSpot(timmy,(random(5) + 1),1);
  spawnToSpot(harold,(random(5) + 1),1);
  spawnToSpot(dragon,3,25);
	//print welcome message
	view.printStr("WELCOME TO DRAGONS HOLLOW! THE GAME COMMENCES...NOW!");
  view.printMap(game);
	//this loop will run until either both heroes are dead, or they have claimed the emerald.
  while( (noEmerald) && ((timmyDead == false) || (haroldDead == false)) )  {
		//only prompt the user for arrow placement if they have already placed the fireball.
		if(placedFireball){
			if (placedArrow == false){
			placedArrow = placeArrowWall();
		}
	}
		//if the player has not yet placed the fireball, then allow them to.
		if(placedFireball == false){
			placedFireball = placeFireball();
		}


		//calls the processTurn function, which is responsible for running game logic
    processTurn();

		//a loop to ensure we can still see where the environmental damagers are
		for (ite = questPlayers.begin(); ite != questPlayers.end(); ++ite){
			//fireball case
	      if ( (*ite)->getSymbol() == '@') {
					game.board.add( (*ite)->getYPos(),(*ite)->getXPos(),(*ite)->getSymbol() );
				}
				//arrow case
				if ( (*ite)->getSymbol() == 'V') {
					game.board.add( (*ite)->getYPos(),(*ite)->getXPos(),(*ite)->getSymbol() );
				}
			}
			//as a final step, print the game map.
    view.printMap(game);
	}
	//if the loop ends and the emerald has been retrieved, victory.
	if (noEmerald == false){
		view.printStr("Victory!");
	}
	//if the loop ends and the emerald has not been retrieved, defeat.
	else{
		view.printStr("Defeat!");
	}

	//function responsible for deallocating memory and cleaning up the game.
	cleanGame();
}

//a function to allow the user to place the fireball
bool Control::placeFireball(){
	int fireball = 10;
	//opens the menu prompting 0 or 1 for fireball placement
	view.showMenu(fireball);
	if (fireball == 1){
		int fireX;
		int fireY;
		bool invalidInputs = true;
		//this while loop will continue until and x and y position are given that is acceptable
		while (invalidInputs){
			view.printStr("Where would you like to place the fireball? Enter X first, then Y");
			view.readInt(fireX);
			view.readInt(fireY);
			invalidInputs = false;
			//if the fireball is out of bounds, tell user they made a mistake and ask again
			if (fireX >= MAXCOL || fireX <=0){
				view.printStr("Invalid X Position.");
				invalidInputs = true;
			}
			if (fireY >= MAXROW || fireY <=0){
				view.printStr("Invalid Y Position.");
				invalidInputs = true;
			}
		}

		//spawn the fireball object
		spawnToSpot(fire,fireY,fireX);
		return true;
	}
	//if the user didn't place the fireball, return false;
	return false;
}

//a function to allow the user to place the arrowwall, only after they have placed the fireball
bool Control::placeArrowWall(){
	int arrowWall = 10;
	//opens the menu prompting 0 or 1 for arrowwall placement
	view.showMenuArrow(arrowWall);
	if (arrowWall == 1){
		int arrX;
		bool invalidInputs = true;
		//this while loop will continue until and x and y position are given that is acceptable
		while (invalidInputs){
			view.printStr("Where would you like to place the Arrow Wall? Enter X Position: ");
			view.readInt(arrX);
			invalidInputs = false;
			//if the arrowall is out of bounds, tell user they made a mistake and ask again
			if (arrX >= MAXCOL || arrX <=0){
				view.printStr("Invalid X Position.");
				invalidInputs = true;
			}

		}
		//spawn the arrow object
		spawnToSpot(arrow,1,arrX);
		return true;
	}
	//if the user didn't place the arrowwall, return false;
	return false;
}

//the main code to run each turn
void Control::processTurn(){
	//call to see if a fighter will be added
  addFighter();
	//begin at front of list and start moving all players
		for (ite = questPlayers.begin(); ite != questPlayers.end(); ++ite){
	      if ((*ite)->hasMoved() == false){
					//call the move player function
					movePlayer((*ite));
					//begin a nested for loop to compare all players x,y against the current pointers.
					for (checkIt = questPlayers.begin();checkIt != questPlayers.end(); ++checkIt){
						//this case makes sure it is never the same pointer colliding with itself
						if ((*checkIt) != (*ite) && ((*checkIt)->hasBeenChecked() == false )){
							//sets the checkedBoolean, telling the program it does not need to be re-checked if we have to reset the iterator
							(*checkIt)->setChecked();
							//check to see if their positions are the same
							if (((*checkIt)->getXPos() == (*ite)->getXPos()) && ((*checkIt)->getYPos() == (*ite)->getYPos())){
								//call handle collisions with both players
								handleCollision((*checkIt),(*ite));
								//reset iterator, because if we remove from a list then try to access that area again, it will cause an error.
								//the booleans will handle being reset, as it will skip all characters that have already been checked
								ite = questPlayers.begin();
								checkIt = questPlayers.begin();

							}
						}
					}
					//once the first for loop has run, we need to resetChecked of all the players
					for (ite2 = questPlayers.begin(); ite2 != questPlayers.end(); ++ite2){
						(*ite2)->resetChecked();
		    }
			}
		}
		//collisions have now been handled

		//check if anyone is at the end
		for (ite3 = questPlayers.begin(); ite3 != questPlayers.end(); ++ite3){
			//check to ensure we are looking at hero pointer
			if(((*ite3)->getSymbol() == 'H') || ((*ite3)->getSymbol() == 'T')){
				//they are within the walls!
				if (((*ite3)->getXPos() == 26) && ( (*ite3)->getYPos() <=4) && (*ite3)->getYPos() >=2){
					noEmerald = false;
					break;
				}
			}
			//if a fighter is about to leave
			else if ((*ite3)->getXPos() == 0){

				//will remove and kill the player
				handleDeath((*ite3));
				//reset ite
				ite3 = questPlayers.begin();
				//for loop to reset walls after a fighter has left
				for (int i = 0; i< MAXROW;i++){
						game.board.add(i,0, '|');
				}
			}
		}
		//reset all characters movement identifiers, and radiate the fireball damage.
		//the fireball should do double damage if the player is ontop of it, so both if statements should be able to fire
		//also checks if a player is in range of the arrow, and if yes, damages players by 1.
		for (ite = questPlayers.begin(); ite != questPlayers.end(); ++ite){
	      (*ite)->resetMoved();

			//only want to run if the arrow has been placed
			if (placedArrow){
				//ensure the fireball and arrow do not damage themselves
				if ( ( (*ite)!= arrow) && ((*ite)!= fire) ) {
					//HANDLING ARROW
					if ((*ite)->getXPos() == arrow->getXPos()){
						(*ite)->setHealth((*ite)->getHealth() -1);
						//view.printStr("Hit a player with arrow!");
					}
				}
			}

			//only want to run if the fireball has been placed
			if (placedFireball){
				if ( (*ite) != fire ){
					//HANDLING FIREBALL
					//if their xPositions are the same
					if ((*ite)->getXPos() == fire->getXPos()){
						//if the subtraction of the YPositions is -1, 0 or 1, then the fireball is next to the player
						if ( (((*ite)->getYPos() - fire->getYPos()) >= -1) && (((*ite)->getYPos() - fire->getYPos()) <= 1)){
							(*ite)->setHealth((*ite)->getHealth() - 2);
							//view.printStr("Hit a player with fireball!");
						}
					}
					//if their yPositions are the same
					if ((*ite)->getYPos() == fire->getYPos()){
						//if the subtraction of the XPositions is -1, 0 or 1, then the fireball is next to the player
						if ( (((*ite)->getXPos() - fire->getXPos()) >= -1) && (((*ite)->getXPos() - fire->getXPos()) <= 1)){
							(*ite)->setHealth((*ite)->getHealth() - 2);
							//view.printStr("Hit a player with fireball!");
						}
					}
			}
		}
	}



}

//determines if a fighter should be added, generates them and adds accordingly
void Control::addFighter(){
  int addFight = random(10);
  int typeDecide = random(3);
  //60% chance with the numbers 0,1,2,3,4,5, 40% chance that it doesn't trigger with the numbers 6,7,8,9
  if (addFight <= 5){
    //dorc case
    if (typeDecide == 0){
      spawnToSpot(new Fighter("spawnedDorc",5,(random(3) + 6),0,'d',nextId),(random(5) + 1),25);
    }
    //borc case
    else if (typeDecide == 1){
      spawnToSpot(new Fighter("spawnedBorc",5,(random(4) + 8),0,'b',nextId),(random(5) + 1),25);
    }
    //porcs
    else if (typeDecide == 2){
      spawnToSpot(new Fighter("spawnedPorc",5,(random(2) + 4),0,'p',nextId),(random(5) + 1),25);
    }
		//increment ID no matter the type of orc
		nextId++;
  }
}

//a function to handle collisions between two given characters
void Control::handleCollision(Character* p1,Character* p2){
  //heroes are p1
  if ( (p1->getSymbol() == 'H') || (p1->getSymbol() == 'T')){
    //hero meets dragon case
    if (p2->getSymbol() == 'D'){
      p1->setHealth(0);

    }
    //hero meets orc case
    else if ((p2->getSymbol() == 'b') || (p2->getSymbol() == 'p') || (p2->getSymbol() == 'd')){
      //damaging the hero
      p1->setHealth(p1->getHealth() - (p2->getStrength() - p1->getArmor()));
      //damaging the fighter
      p2->setHealth(p2->getHealth() - (p1->getStrength()));
    }
  }

  //dragon is p1
  else if(p1->getSymbol() == 'D'){
    //heroes are p2
    if ( (p2->getSymbol() == 'H') || (p2->getSymbol() == 'T')){
      p1->setHealth(0);
    }
  }
  //p1 is a fighter
  else if ((p1->getSymbol() == 'b') || (p1->getSymbol() == 'p') || (p1->getSymbol() == 'd') ){
    //if p2 is the Hero
    if ( (p2->getSymbol() == 'H') || (p2->getSymbol() == 'T') ) {
      //damaging the fighter
      p1->setHealth(p1->getHealth() - (p2->getStrength()));
      //damaging the hero
      p2->setHealth(p2->getHealth() - (p1->getStrength() - p2->getArmor()));
    }
  }
  //at this point in the program, players have had damage calculated.

  //if p1 is dead
  if (p1->getHealth() <= 0){
    handleDeath(p1);
		checkingPlayerDied = true;
	}

	if (p2->getHealth() <= 0){
		handleDeath(p2);
	}

}

//a function to handle the death of a player. Removes from gameboard and list
void Control::handleDeath(Character* p1){

		//if p1 is the hero
	if ((p1->getSymbol() == 'H') || (p1->getSymbol() == 'T')){
		//grave symbol
		game.board.add(p1->getYPos(),p1->getXPos(), '+');
		//update loss conditions
		if (p1->getSymbol() == 'H'){
			haroldDead = true;
		}
		else if (p1->getSymbol() == 'T'){
			timmyDead = true;
		}
	}
	//if p1 is a fighter
	else{
		//fighters should die and be removed
		game.board.add(p1->getYPos(),p1->getXPos(), ' ');
	}

	//everyone should be removed from game, no matter if hero or fighter:
	removeFromGame(p1);
}

	//remove the given character from the list, given the ptr, and deallocates the memory.
bool Control::removeFromGame(Character* entity){
	questPlayers.remove(entity);
	delete entity;
}

//handles the movement of a given player
void Control::movePlayer(Character* entity){
  bool checkerVar = true;
	//set previous spots, so we can rewind movement if it goes out of bounds.
  int preX = entity->getXPos();
  int preY = entity->getYPos();
  //this ensures dead heroes don't move
  if (entity->getHealth() > 0){
		//this loop will run until the program has calculated a valid position
    while (checkerVar){
			//make a call to move.
      entity->move(random(3));
			//check to see if the new spot is acceptable, if yes, break the loop.
      if (isValidLocation(entity->getYPos(),entity->getXPos()) == true){
        checkerVar = false;
      }
			//if the position is invalid, reset movement and try again.
      else if (isValidLocation(entity->getYPos(),entity->getXPos()) == false){
        entity->setYPos(preY);
        entity->setXPos(preX);
      }

    }
		//set the moved boolean on the Character to true.
		entity->setMoved();
		//update the gameboard with their position
    game.board.add(preY,preX, ' ');
    game.board.add(entity->getYPos(),entity->getXPos(),entity->getSymbol());
  }
}

//spawns a player at the given spot
void Control::spawnToSpot(Character* entity, int row, int col){
  //collisions on spawn are okay.
  //add the player to the stl list
  questPlayers.push_front(entity);
	//place the player symbol on the board
  game.board.add(row,col,entity->getSymbol());
  entity->setXPos(col);
  entity->setYPos(row);
}

//returns true if the row and column given are within the acceptable range.
bool Control::isValidLocation(int row, int col){
  //checks if the location is within the map, returns false if not.
  if ( (row > 5 || row < 1) || (col > 26 || col < 0) ) {
    return false;
  }
  else{
		if (col == 26 && ((row < 2) || (row > 4))) {
			return false;
		}
    return true;
  }
}

//a function to clean the game board and stl list.
void Control::cleanGame(){
	//iterate through list and delete entries.
		for (ite = questPlayers.begin(); ite != questPlayers.end(); ++ite){
			delete (*ite);
		}
		//delete the 2d list;
		game.board.delList();
		//if the user never placed the fireball, we still need to delete it
		if (placedFireball == false){
			delete fire;
		}
		//if the user never placed the arrowwall, we still need to delete it
		if (placedArrow == false){
			delete arrow;
		}

}
