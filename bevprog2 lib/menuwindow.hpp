// menuwindow.hpp
#ifndef MENUWINDOW_HPP
#define MENUWINDOW_HPP

#include "parentwindow.hpp"

class Menu : public ParentWindow
{
    private:
    int _current_player;
public:
    Menu(); //
    void quit();
    void start();
    void run(); // New method to run the menu window
    void setCurrentPlayer(int player);
};

#endif // MENUWINDOW_HPP
