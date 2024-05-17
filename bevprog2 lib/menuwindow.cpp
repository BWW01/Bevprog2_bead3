// menuwindow.cpp
#include "menuwindow.hpp"
#include "tictactoe_single.hpp"
#include "graphics.hpp"
#include "statictext.hpp"
#include "button.hpp"
#include "gamewindow.hpp"

using namespace genv;

Menu::Menu() {
    StaticText *title = new StaticText(this, 10, 10, 50, "Nagyon meno amoba jatek");
    StaticText *madeby = new StaticText(this, 510, 680, 30, "Keszitette: Marczi Richard Mark(BKG01U)");
    Button *quitb = new Button(this, 255, 500, 200, 40, "quit", [this]() { this->quit(); });
    Button *starb = new Button(this, 625, 500, 200, 40, "start", [this]() { this->start(); });

    int rows = 3;
    int cols = 3;
    TicTacToe_single *tt[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tt[i][j] = new TicTacToe_single(this, 390 + j * 100, 100 + i * 100, 100, 100, _current_player);
        }
    }
}

void Menu::quit() {
    stop = true;
}

void Menu::start() {
    Game game_window;
    game_window.run();
}

void Menu::run() {
    initwindow(XX, YY);
    mainloop(XX, YY);
}
