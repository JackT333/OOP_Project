#include "grid.h"
#include <iostream>

using namespace std;

// updates the board and displays your move
void Board::display() {

    cout << endl;
    cout << "   -------------" << endl;

    for (int row = 0; row < 6; row++) {

        cout << "   ";

        for (int col = 0; col < 7; col++) {

            cout << board[row][col] << " ";
        }
        
        cout << endl;
    }

    cout << "   -------------" << endl;
    cout << endl;
}

// check if there are 4 pieces in a row 
bool Board::checkWin(int piece) {

     for (int row = 0; row < 6; row++) {

        for (int col = 0; col < 7; col++) {

            if (board[row][col] == piece) {
                
                // checks horizontally
                int continuous = 1;
                int horizontal_position = col;
                while (++horizontal_position < 7 && board[row][horizontal_position] == piece) {
                    
                    continuous++;
                    cout << continuous << " in a row" << endl;
                    if (continuous == 4) return true;
                }
                
                // checks vertically
                continuous = 1;
                int vertical_position = row;
                while (++vertical_position < 6 && board[vertical_position][col] == piece) {

                    continuous++;
                    cout << continuous << " in a row" << endl;
                    if (continuous == 4) return true;
                }

                // checks diagonally from right to left
                continuous = 1;
                horizontal_position = col;
                vertical_position = row;
                while (++horizontal_position < 7 && ++vertical_position < 6 && board[vertical_position][horizontal_position] == piece) {

                    continuous++;
                    cout << continuous << " in a row" << endl;
                    if (continuous == 4) return true;
                }
                
                // checks diagonally from left to right
                continuous = 1;
                horizontal_position = col;
                vertical_position = row;
                while (++horizontal_position < 7 && --vertical_position >= 0 && board[vertical_position][horizontal_position] == piece) {

                    continuous++;
                    cout << continuous << " in a row" << endl;
                    if (continuous == 4) return true;
                }
            }
        }
     }
     return false;
}

Board::Board() {

    for (int row = 0; row < 6; row++) {

        for (int col = 0; col < 7; col++) {

            board[row][col] = 0;
        }
    }

    display();
}

// place pieces on the board
bool Board::place(int col, int piece) {

    int row = 0;

    for (; row < 6; row++) {

        if (board[row][col] != 0) {

            break;
        }
    }

    if (row <= 0) {

        cout << "Invalid move" << endl;
        return false;
    }

    else {

        row --;
        board[row][col] = piece;
        display();
    }

    return true;
}
