#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

// abstract player class 
class player {

    public:
        virtual int play() = 0;                         // pure virtual function - abstraction used
        int get_pattern() { return pattern; }
        string get_name() { return player_name; } 
                    
    protected:
        int pattern;                                    // displaying the board or grid
        int last_column;
        string player_name; 
};


// human player class
class human_player:public player {
    
    public:
        human_player(string name, int human_piece); 
        human_player(); 
        int play();                                     // play function - polymorhism used
};


// computer class
class computer:public player {     

     public:
        computer(string name, int computer_piece); 
        computer(); 
        int play();                                     // play function - polymorhism used
};

#endif
