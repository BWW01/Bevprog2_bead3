#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include "parentwindow.hpp"
#include "tictactoe_single.hpp"
#include <vector>

class Game : public ParentWindow {
public:
    Game(int meret); // Constructor
    void quit();
    int p; // Player state
    void run(); // New method to run the menu window
    int meret;
    virtual void handle(genv::event ev);
protected:

    std::vector<TicTacToe_single*> tt; // Declare tt as a vector of pointers
};


#endif // GAMEWINDOW_HPP
