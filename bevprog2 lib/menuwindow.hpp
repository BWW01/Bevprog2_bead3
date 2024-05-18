#ifndef MENUWINDOW_HPP
#define MENUWINDOW_HPP

#include "parentwindow.hpp"
#include "tictactoe_single.hpp"
#include <thread> // Include <thread> for std::thread
#include <chrono> // Include <chrono> for time-related functions

class Menu : public ParentWindow
{
private:
    int _current_player;
    int player;
    int meret;
    int p; // Player state
    std::vector<TicTacToe_single*> tt;
    std::thread timer_thread; // Declare timer_thread as a member variable
    void timer_thread_function(); // Declaration of timer_thread_function
public:
    Menu();
    void quit();
    void start();
    void run(); // New method to run the menu window
    void setCurrentPlayer(int player);
    virtual void handle(genv::event ev);
};

#endif // MENUWINDOW_HPP
