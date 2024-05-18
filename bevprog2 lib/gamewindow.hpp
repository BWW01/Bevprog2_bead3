#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include "parentwindow.hpp"
#include "tictactoe_single.hpp"
#include <vector>

class Game : public ParentWindow {
public:
    Game(); // Constructor
    void quit();
    void run(); // New method to run the menu window
    virtual void handle(genv::event ev);
protected:
    int player;
    int meret;
    std::vector<TicTacToe_single*> tt; // Declare tt as a vector of pointers
};


#endif // GAMEWINDOW_HPP
