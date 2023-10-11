#include <stdio.h>
#include <iostream>
#include <string>

#include "Game.h"

using namespace std;

// list constructor: create pointers for the player objects, and store them in the pointer array data member/attribute
Game::Game(Player *player1_Ptr, Player *player2_Ptr): players_Ptr {player1_Ptr, player2_Ptr}
{
}

Game::~Game() // deconstructor
{
}

// this is the function that conduct the bulk of the operation.
const int Game::run_game(void)
{
    int play_game = 1;    // variable instructor while loop below to continue running games
    
    while (play_game == 1) // while loop continues running tic tac toe games until users instructs otherwise
    {
        rounds = 1; // re-start rounds to 1
        
        // initialize grid each game cycle
        grid[0][0] = '1';
        grid[0][1] = '2';
        grid[0][2] = '3';
        grid[1][0] = '4';
        grid[1][1] = '5';
        grid[1][2] = '6';
        grid[2][0] = '7';
        grid[2][1] = '8';
        grid[2][2] = '9';
        
        char cell = 'a'; // cell will hold the user's intruction on which cell to place a mark. It is initiated with placeholder 'a'
        
        // Output players 1 and 2 usernames. This is done by using access operator for the pointer
        cout << "NEW MATCH: " << players_Ptr[0]->get_username() << " VS " << players_Ptr[1]->get_username() << endl;
        
        // we automatically assing player1 X as game symbol, and O for player2
        players_Ptr[0]->set_game_symbol('X');
        players_Ptr[1]->set_game_symbol('O');
        cout <<  players_Ptr[0]->get_username() << " has been assined X" << endl;
        cout << players_Ptr[1]->get_username() << " has been assined O" << endl;
        
        cout << endl << "--Let's begin--------------" << endl;
        print_grid(); // print board
        
        for (int i = 1; i < 6; i++) // loop while the number of round is less than 6. Since tictactoe's grid is has 9 square, and player alternate marks, a user has a maximum of 5 marks, thus, we exit loop and end current game if the number of turns reaches 5
        {
        
            cout << "--Round number: " << rounds << "------------" << endl; // outputs the current round number
            
            for (int j = 0; j <= 1; j++) // loop alternate game functions between player1 and player2 in each round
            {
                
                // output player's username with the access operator for the pointer, also reminding the user what symbol (X or O) they were assigned
                cout << "Player " <<  players_Ptr[j]->get_username() << " (" << players_Ptr[j]->get_game_symbol() << ")"<< ", select cell number: ";
                cin >> cell; // input cell choosing from the grid
                tick_grid(cell, *players_Ptr[j]); // scratch grid
                print_grid(); // print grid
                
                if (check_win(*players_Ptr[j]) == 1) // check if check_win() returns 1, implying there is a winner
                {
                    // output the winner's username to screen
                    cout << " ** " << players_Ptr[j]->get_username() << " IS THE WINNER !!! **" << endl << endl;
                    players_Ptr[j]->assing_win(); // assign winner a victory to their object
                    
                    // ask if user want to play another game
                    if (restart_game() == 'Y') // if restart_game is 'Y', we run another game
                    {
                        i += 6; // we must exit the current game's loop, so we add 6 to i to negate the condition and exit
                        j += 2; // we must exit the loop that alternates between the two player within a round, so we add 2 to j to negate the condition and exit
                    }
                    else // if player doesn't want to play another game, exit
                        return 0;
                } // end of check_win()
            
            } // end of loop that alternate game functions between player1 and player2 in each round
            
            rounds++; // increase round count by 1
            
            // check for no winner / tie
            if (rounds == 6) // Max number of rounds is 6. Since tictactoe's grid is has 9 square, and player alternate marks, a user has a maximum of 6 marks, thus, we exit loop and end current game if the number of turns reaches 6
            {
                cout << "____! Nobody Won !____" << endl << endl;
                
                if (restart_game() == 'Y') // ask user to play another game?
                    play_game = 1;
                else
                    return 0;
            } // end of for no winner / tie
            
        } // end of entire game loop
        
    } // end of while loop running tic tac toe games until users instructs otherwise
    return 0;
}

// function prints tictactoe's grid, it is defined as a constant function
void Game::print_grid(void) const
{
    cout << "\t" << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << endl;
    cout << "\t" << "---------" << endl;
    cout << "\t" << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << endl;
    cout << "\t" << "---------" << endl;
    cout << "\t" << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << endl;
    cout << endl;
}

// function marks/tick an X or O in the grid. Function receives constant address of cell(user instruction of what cell to mark), and constant pointer object address
void Game::tick_grid(const char &cell, const Player &current_player_Ptr)
{
    switch (cell) {
        case '1':
            grid[0][0] = current_player_Ptr.get_game_symbol(); // assing cell current player's symbol (X or O)
            break;
        case '2':
            grid[0][1] = current_player_Ptr.get_game_symbol();
            break;
        case '3':
            grid[0][2] = current_player_Ptr.get_game_symbol();
            break;
        case '4':
            grid[1][0] = current_player_Ptr.get_game_symbol();
            break;
        case '5':
            grid[1][1] = current_player_Ptr.get_game_symbol();
            break;
        case '6':
            grid[1][2] = current_player_Ptr.get_game_symbol();
            break;
        case '7':
            grid[2][0] = current_player_Ptr.get_game_symbol();
            break;
        case '8':
            grid[2][1] = current_player_Ptr.get_game_symbol();
            break;
        case '9':
            grid[2][2] = current_player_Ptr.get_game_symbol();
            break;
        default:
            break;
    }
}

// function check for a win, it returns a constant int, it receives a constant object pointer address, and it is defined as a constant function
const int Game::check_win(const Player &current_player_Ptr) const
{
    char c = current_player_Ptr.get_game_symbol(); // initiate current player's symbol (X or O)
    // check horizontal win
    if (grid[0][0] == c && grid[0][1] == c && grid[0][2] == c) return 1; // return 1 to indicate a win
    if (grid[1][0] == c && grid[1][1] == c && grid[1][2] == c) return 1;
    if (grid[2][0] == c && grid[2][1] == c && grid[2][2] == c) return 1;
    // vertical
    if (grid[0][0] == c && grid[1][0] == c && grid[2][0] == c) return 1;
    if (grid[0][1] == c && grid[1][1] == c && grid[2][1] == c) return 1;
    if (grid[0][2] == c && grid[1][2] == c && grid[2][2] == c) return 1;
    // diagonal
    if (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) return 1;
    if (grid[0][2] == c && grid[1][1] == c && grid[2][0] == c) return 1;

    
    return 0;
}


// function restarts/begins another game. It returns a constant character, and it is defined as a constant function
const char Game::restart_game(void) const
{
    // output the number of wins the players have with the pointer's access operators
    cout << players_Ptr[0]->get_username() << " has " << players_Ptr[0]->get_wins() << " number of wins" << endl;
    cout << players_Ptr[1]->get_username() << " has " << players_Ptr[1]->get_wins() << " number of wins" << endl;
    
    char answer = 'a'; // initialized with placeholder 'a';
    cout << "Do you want to play another game? (Y/N): " << endl;
    cin >> answer;
    
    return answer;
}
