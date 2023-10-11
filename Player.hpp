
#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "string"

using namespace std;

class Player
{
public:
    Player(const string &);                  // see cpp file for explanation
    ~Player();
    const string get_username(void) const;
    void set_game_symbol(const char &);
    const char get_game_symbol(void) const;
    void assing_win(void);
    const int get_wins(void) const;
    
private:
    string username_private = "";    // holds player's username
    int numbers_of_wins = 0;        // holds number of games won by player
    char game_symbol = 'a';         // this will hold X or O, depending on the game's assignment. It is initialized with placeholder 'a';
};


#endif /* Player_hpp */
