Program Author: Lucas Colwell (#101102212) 
	(and Christine Larendeau (Some View functions and the random function))

Purpose: Create a simulation of Dragon's Hollow to allow Lady Gwendolyn to save Timmy and Harold!
	(In reality, to create a game played by the computer, where the objective is for the Hero 		entities to reach the emerald (located at the end of the board) without dying)

List of files: Dragon.cc Dragon.h Character.cc Character.h main.cc MyList.cc Hero.h Hero.cc Fighter.h Fighter.cc Fireball.h Fireball.cc ArrowWall.cc ArrowWall.h Gameboard.h Gameboard.cc View.cc View.h Control.h Control.cc Makefile README.txt

Compilation and launching instructions:
1. Ensure proper directory
2. enter "make" into proper directory
3. enter "./check" to run the program
4. You will be prompted to place environmental hazards in dragons hollow.

INNOVATIVE FEATURE: ENVIRONMENTAL HAZARDS

My idea for the innovative feature was to allow the game-runner to place hazards on the map, such as a Fireball or an ArrowWall, which would damage players on the board. The Fireball would radiate 2 "pure" damage (not affected by armor) to all squares around it, and would deal 4 damage if a player was standing on top of it. The ArrowWall deals 1 pure damage to all players on the same Y-Axis as it (like the arrows that shoot out in the Indiana Jones temple from ROTLA). At first, I simply put them in the game at random spots, but I decided to allow the user to place them themselves.

NEW CLASSES USED: ArrowWall and Fireball.

The ArrowWall and Fireball classes are both concrete implementations of the Character Class, and are stored in the same STL list as the quest players. As such, they have a move function, but since I never actually want the fireball or arrow-wall to walk around, I decided to have the move function do nothing, so when movement is checked, it will remain in place. Since Control handles collision, spawning, death and damage, I decided to keep the functionality for the env-hazards in Control.

CLASSES WITH NEW FUNCTIONALITY: Control

Control now has two private env-hazards, one called arrow of type ArrowWall and one called fire of type Fireball.

In addition to handling gameplay, control now also handles the placement and processing of the environmental hazards. The user is prompted immediately upon opening the program if they would like to place the Fireball. They can choose yes or no. If they choose no, a turn is processed and they are asked again. If they choose yes, they are prompted for the X and Y locations for the Fireball. Assuming they enter valid inputs, the Fireball that already exists in control is added to the player list and placed on the board. Now, on the next turn, the player is prompted as to whether or not they would like to place the ArrowWall, and a similar process repeats, except the player is only ever prompted for the X co-ordinate.

Inside of the processTurn() function, there is a for loop that loops over every player, and deals environmental damage if they are within the range of the hazards (0 or 1 square from Fireball, or same Y as ArrowWall). The program also runs another for loop to ensure that at the end of the turn we can see where the Fireball and ArrowWall are. I didn't put anything for collision, as I don't want the players to be able to destroy the env-hazards. I initially had behaviour for this, but removed it because the env-hazards were only lasting a few turns. I imagine the fireball as being in the air and doing damage, and of course the ArrowWall is in the wall, and the 'V' symbol is merely indicating that a specific y range will be dealt 1 damage every turn.

At the end of the game, if the player hasn't placed the Fireball or the ArrowWall, there is a special case to delete them as they were made as part of the class. All functionality that requires an arrowwall or fireball has been hidden behind a boolean of placedFireball and placedArrowWall, to ensure there is no code that relies on un-initialized values, as this would cause a valgrind error.

(Side note: I initially had the Fireball rolling, by updating its XPos by -1 every turn, but it made the game too difficult for Timmy and Harold so I removed it)

I think that by allowing the game-runner to influence the game, it may add an interesting angle to the game, as the Fireball and ArrowWall used together can introduce a light tactical element to the game.



