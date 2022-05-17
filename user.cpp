#include "user.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// computer constructor
computer::computer() {}


// computer pieces describes computer instance
computer::computer(string name, int computer_piece) {

    player_name = name; 
    pattern = computer_piece;  
    cout << player_name << endl;
    last_column = -1;
}


// overrides pure virtual from player class - polymorphism
int computer::play() {

    cout << "Computer " << get_name() << " plays " << endl;

    int column = 0;
    if (last_column == -1) {

        column = rand() % 6;
        return column;
    }

    return 0;
}


// human player constructor
human_player::human_player() {

    cout << "Human " << endl;
}


//human_piece describes human instance
human_player::human_player(string name, int human_piece) {

    cout << name << endl;
    player_name = name;
    pattern = human_piece;
    cout << "Human " << player_name << endl;
    cout << '\n';
}


// overrides pure virtual from player class - polymorphism
int human_player::play() {

    int column = 0;
    string input_column;
    cout << "Human " << get_name() << " plays " << endl;
    do {
        cout << "Input column number (1 - 7): ";
        cin >> input_column;
        column = atoi(input_column.c_str());
    } while (column < 1 || column > 7);
    
    return column - 1;
}