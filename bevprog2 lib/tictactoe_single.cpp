// tictactoe_single.cpp
#include "tictactoe_single.hpp"
#include "menuwindow.hpp" // Include Menu class header file to resolve the error
#include "graphics.hpp"
using namespace genv;
TicTacToe_single::TicTacToe_single(ParentWindow *p, int x, int y, int sx, int sy, int _player)
    : ParentWidget(p, x, y, sx, sy), _player(_player) {
    _state = 0;
}

void TicTacToe_single::draw() {
    switch (_state) {
    case 0:
        gout << move_to(_x, _y)
             << color(255, 255, 255)
             << box(_sx, _sy)
             << move_to(_x + _sx * 0.05, _y + _sy * 0.05)
             << color(0, 0, 0)
             << box(_sx - _sx * 0.1, _sy - _sy * 0.1);
        break;
    case 1:
        gout << move_to(_x, _y)
             << color(0, 255, 0)
             << box(_sx, _sy)
             << move_to(_x + _sx * 0.05, _y + _sy * 0.05)
             << color(55, 12, 1)
             << box(_sx - _sx * 0.1, _sy - _sy * 0.1);
        break;
    case 2:
        gout << move_to(_x, _y)
             << color(255, 0, 0)
             << box(_sx, _sy)
             << move_to(_x + _sx * 0.05, _y + _sy * 0.05)
             << color(55, 12, 1)
             << box(_sx - _sx * 0.1, _sy - _sy * 0.1);
        break;
    }
}

void TicTacToe_single::handle(genv::event ev) {
    if (interact(ev.pos_x, ev.pos_y) && ev.button == 1 && _state == 0) {
        // Toggle between players
        _player = (_player == 1) ? 2 : 1;

        // Update the state
        _state = (_player == 1) ? 1 : 2;

        if (_player == 1) {
            _state = 1;
            _player = 2;
        } else if (_player == 2) {
            _state = 2;
            _player = 1;
        }


    }
}

bool TicTacToe_single::is_active() {
    return focus;
}
