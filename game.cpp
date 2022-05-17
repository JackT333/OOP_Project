#include "user.h"
#include "game.h"
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;

Game::Game(player* pl1, player* pl2) {

    set_players(pl1, pl2);
}

// set the game's players
void Game::set_players(player* pl1, player* pl2) {

    player1 = pl1; 
    player2 = pl2;     
}

// asks for input from both players until someone wins (loop)
int Game::playgame() {

    cout << "The game begins" << endl;
    cout << '\n';

    int col = 0;
    bool logic = false;
    while (true) {

        while (!logic) {

            col = player1 -> play();

            logic = board.place(col, player1 -> get_pattern()); 
        }

        logic = false;

        if (board.checkWin(1)) {

            cout << player1 -> get_name() << " wins!" << endl;

            return 1;
        }
        
        while (!logic) {

            col = player2 -> play(); 

            logic = board.place(col, player2 -> get_pattern()); 
        }

        logic = false;

        if (board.checkWin(2)) {

            cout << player2 -> get_name() << " wins!" << endl;

            return 2;
        }
    }
}