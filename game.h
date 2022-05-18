#ifndef GAME_H
#define GAME_H
#include "grid.h"
#include "user.h"
#include <memory>

class Game {
    
    public:

        Game() {};
        Game(player* player1, player* player2);
        void set_players(player *player1, player *player2);
        int playgame();

    private:

        Board board;
        player* player1; // pointer that points to player1 
        player* player2; // pointer that points to player2
};

#endif
