
#ifndef Game_h
#define Game_h

#include "Player.hpp"

class Game
{
public:
    Game(Player *, Player *);  // see cpp file for explanation
    ~Game();
    const int run_game(void);

private:
    const char valid_cell(void) const; // check that input is a valid cell
    const bool is_not_equal(char &element, char &input) const;
    void print_grid(void) const;  // see cpp file for explanation
    void tick_grid(char &, const Player &);
    const int check_win(const Player &) const;
    const char restart_game(void) const;
    
    
    char grid[3][3] = {0};      // 2d array, which will be the tic tac toe's grid
    int rounds = 1;             // variables stores and counts number of rounds. 1 round is defined as when both players make a single mark on the board, in other words, one X and one O is marked
    Player * players_Ptr[2];    // Array will store two pointers, which points to the 2 players playing the game
    vector<char> cells_occupied; // records the occupied board cells from the current game
};


#endif /* Game_h */
