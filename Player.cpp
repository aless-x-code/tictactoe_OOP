#include <stdio.h>
#include <iostream>
#include <string>

#include "Player.hpp"

using namespace std;

// list constructor: parameter is a constant string, received as original variable
Player::Player(const string &username): username_private(username)
{
}

Player::~Player()  // deconstructor
{
}

// function return constant string being the player's username, and it is defined as a constant function, meaning it can't modify varibales inside class
const string Player::get_username(void) const
{
    return username_private;
}

// functions assign player either X or O, its paramter is a constant char address
void Player::set_game_symbol(const char &symbol)
{
    game_symbol = symbol;
}

// function returns a constant game symbol (either X or O), it is defined as a constant function
const char Player::get_game_symbol(void) const
{
    return game_symbol;
}

// function assing a win to the player
void Player::assing_win(void)
{
    numbers_of_wins++;
}
// function returns a constant number of games won, it is defined as a constant function
const int Player::get_wins(void) const
{
    return numbers_of_wins;
}
