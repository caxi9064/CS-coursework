#include <iostream>
#include <string>
#include "Player.h"
#include "Inventory.h"
#include "Milestones.h"
#include "Date.h"
#include <vector>
#include "Game.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Landmark.h"
using namespace std;
int main()
{
// Game class: where all our functions are gonna be
// Declared ojects from other classes as private variables in the Game.h implementation file so we can directly access them
// The run() function contains all the function calls for this game

    Game game;
    game.run();
}


    