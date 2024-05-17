// tictactoe_single.hpp
#ifndef TICTACTOE_SINGLE_HPP
#define TICTACTOE_SINGLE_HPP

#include "parentwidget.hpp"

class TicTacToe_single : public ParentWidget {
protected:
    int _state;
    int _player;
    bool focus;
public:
    TicTacToe_single(ParentWindow *p, int x, int y, int sx, int sy, int _player);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual bool is_active();
};

#endif // TICTACTOE_SINGLE_HPP
