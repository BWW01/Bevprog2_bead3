#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP


#include "parentwindow.hpp"

class Game : public ParentWindow
{
public:
    Game(); // Constructor
    void quit();
    void start();
    void run(); // New method to run the menu window
};

#endif // GAMEWINDOW_HPP
