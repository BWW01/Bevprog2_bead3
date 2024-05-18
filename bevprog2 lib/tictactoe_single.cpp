#include "tictactoe_single.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;
using namespace std;

TicTacToe_single::TicTacToe_single(ParentWindow *p, int x, int y, int sx, int sy)
    : ParentWidget(p, x, y, sx, sy), _state(0){}

void TicTacToe_single::draw() {
    switch (_state) {
    default:
        gout << move_to(_x, _y)
             << color(255, 255, 255)
             << box(_sx, _sy)
             << move_to(_x + _sx * 0.05, _y + _sy * 0.05)
             << color(0, 0, 0)
             << box(_sx - _sx * 0.1, _sy - _sy * 0.1);
        break;
    case 1:
        gout.load_font("LiberationSans-Regular.ttf", _sy*1.3,1);
        gout << move_to(_x, _y)
             << color(255, 255, 255)
             << box(_sx, _sy)
             << move_to(_x + _sx * 0.05, _y + _sy * 0.05)
             << color(0, 0, 0)
             << box(_sx - _sx * 0.1, _sy - _sy * 0.1)
             << move_to(_x+_sx*0.05, _y-_sy*0.23)
             << color(0,255,0)
             << text("X");
        break;
    case 2:
        gout.load_font("LiberationSans-Regular.ttf", _sy*1.3,1);
       gout << move_to(_x, _y)
             << color(255, 255, 255)
             << box(_sx, _sy)
             << move_to(_x + _sx * 0.05, _y + _sy * 0.05)
             << color(0, 0, 0)
             << box(_sx - _sx * 0.1, _sy - _sy * 0.1)
             << move_to(_x, _y-_sy*0.23)
             << color(255,0,0)
             << text("O");
        break;
    }
}

void TicTacToe_single::handle(genv::event ev) {
    if (ev.button == btn_left && ev.type == ev_mouse && interact(ev.pos_x, ev.pos_y) && _state == 0) {
        // Toggle between players
        _state = most; // Update the state according to the current player
        // Optionally, you can also notify the parent window or perform any additional actions here
    }
}


void TicTacToe_single::statebe(int p) {
    most = p;
    if(most == 0){_state = 1;}
    if(most == 1){_state = 2;}
    if(most == 2){_state = 0;}
}

bool TicTacToe_single::is_active() {
    return focus;
}
