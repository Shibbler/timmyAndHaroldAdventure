check:	main.o MyList.o Gameboard.o Character.o Hero.o Fighter.o Dragon.o Fireball.o Control.o View.o ArrowWall.o
	g++ -o check main.o MyList.o Gameboard.o Character.o Hero.o Fighter.o Dragon.o Fireball.o Control.o View.o ArrowWall.o

main.o:	main.cc Control.h
	g++ -c main.cc

Gameboard.o: Gameboard.cc Gameboard.h MyList.cc
	g++ -c Gameboard.cc MyList.cc

MyList.o: MyList.cc
	g++ -c MyList.cc

Control.o: Control.cc Control.h Gameboard.h Fighter.h Character.h Dragon.h Hero.h Fireball.h View.h ArrowWall.h
	g++ -c Control.cc

Character.o: Character.cc Character.h
	g++ -c Character.cc

Hero.o: Hero.cc Hero.h Character.h;
	g++ -c Hero.cc

Fighter.o: Fighter.cc Fighter.h Character.h
	g++ -c Fighter.cc

Dragon.o: Dragon.cc Dragon.h Character.h
	g++ -c Dragon.cc

Fireball.o: Fireball.cc Fireball.h Character.h
	g++ -c Fireball.cc

ArrowWall.o: ArrowWall.cc ArrowWall.h Character.h
	g++ -c ArrowWall.cc

View.o: View.cc View.h Gameboard.h
	g++ -c View.cc

clean:
	rm -f *.o check
