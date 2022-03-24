#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <time.h>
#include "Control.h"

//Main Class
//Objective: Creates the control object, and calls the initGame function.

int main()
{
  //seed random
  srand( (unsigned)time( NULL ) );
  //create a control object
  Control control;
  //call initGame(), and let control do the rest.
  control.initGame();
}
