#ifndef GRID_H
#define GRID_H

class Board {

    public:
        Board(); 
        bool place(int col, int piece); // places a piece on to the board
        bool checkWin(int piece);       // check if there are 4 pieces in a row

    private:
        void display();                 // displays the board
        int board[6][7];                // arrays that represents the board
};

#endif
