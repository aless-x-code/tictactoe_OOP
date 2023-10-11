#include <iostream>

#include "Game.h"
#include "Player.hpp"

using namespace std;


int main() {
    
    // create 2 player objects, constructed with the player's username
    Player player8374("Angel-2003");
    Player player1374("77_tic_gamer");
    
    // create game object in the heap
    Game *game1 = new Game (&player8374, &player1374);     // we the addresses of player as parameters
    game1->run_game();                                    // run game for object
    delete game1;                                         // prevent memory leak
 
    
    return 0;
}
