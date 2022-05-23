#include "game_mode.h"
#include "user.h"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <string>

void game_mode::choose_game_mode() {
    
    string game_mode;
    int mode = 0;

    human_player player1("Player 1", 1);
    human_player player2("Player 2", 2);
    computer computer("Computer", 2);
    
    Game game;

    // while mode is 0 requires user to select cases for different game modes
    while (mode == 0) {
        cout << "Select a game mode:" << endl;
        cout << "1. Human VS. Human:" << endl;
        cout << "2. Human VS. Computer:" << endl;
        cout << "\n";
        
        cin >> game_mode;
        mode = atoi(game_mode.c_str());         // atoi - converts string to an integer value
        
        // c_str returns a pointer to an array that contains a null-terminated sequence of characters
        // representing the current value of game_mode object

        switch (mode) {

            case 1:
                game.set_players(&player1, &player2);
                break;

            case 2:
                game.set_players(&player1, &computer);
                break;

            default:
                mode = 0;
                cout << "Incorrect option" << endl;
        }
        cout << "\n";
    }
    
    // prints out the instructions
    cout << "Player 1 pieces labeled as 1" << endl;
    cout << "Player 2 or computer pieces labeled as 2" << endl;
    cout << "\n";
    
    game.playgame();
}
