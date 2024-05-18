#ifndef TICTACTOE_SINGLE_HPP
#define TICTACTOE_SINGLE_HPP

#include "parentwidget.hpp"

class TicTacToe_single : public ParentWidget {
public:
    TicTacToe_single(ParentWindow *p, int x, int y, int sx, int sy);
    void draw() override;
    void handle(genv::event ev) override; // Override pure virtual function
    void handle(genv::event ev, int &player);
    void statebe(int p);
    bool is_active();
    bool focus; // Declare focus variable

protected:
    int _state;
    int most;

};

#endif // TICTACTOE_SINGLE_HPP
