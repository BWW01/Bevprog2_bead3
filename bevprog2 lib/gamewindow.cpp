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
Game::Game() : ParentWindow(), player(1), meret(25) {
    // Initialize the vector of TicTacToe_single pointers
    for (int i = 0; i < meret; ++i) {
        for (int j = 0; j < meret; ++j) {
            tt.push_back(new TicTacToe_single(this, 0 + j * 50, 0 + i * 50, 50, 50));
        }
    }
    Button *quitb = new Button(this, 255, 500, 200, 40, "quit", [this]() { this->quit(); });
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

}
