#include "parentwidget.hpp"
#include "parentwindow.hpp"
#include "spinbox.hpp"
#include "statictext.hpp"
#include <vector>
#include <string>
#include "textbox.hpp"
#include "listbox.hpp"
#include "button.hpp"
#include "gamewindow.hpp"
#include "tictactoe_single.hpp"
#include <iostream>
#include "menuwindow.hpp"

using namespace genv;
using namespace std;
// Constructor implementation
Game::Game(int meret) : ParentWindow(), meret(meret) {
    // Initialize the vector of TicTacToe_single pointers
    for (int i = 0; i < meret; ++i) {
        for (int j = 0; j < meret; ++j) {
            tt.push_back(new TicTacToe_single(this, 0 + j * 720/meret, 0 + i * 720/meret, 720/meret, 720/meret));
        }
    }
    Button *quitb = new Button(this, 1000, 700, 80, 20, "quit", [this]() { this->quit(); });
}

void Game::run() {
    Menu menu;
    menu.quit();
    mainloop();
}

void Game::quit() {
    Menu menu_window;
    menu_window.run(); // Initialize and run the menu window
}

void Game::handle(genv::event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
         for (auto& a : tt) {
                if(a->interact(ev.pos_x,ev.pos_y)){
                    a->statebe(p % 2);
                }

        }
        p++; // Increment player after handling the event
    }
}
