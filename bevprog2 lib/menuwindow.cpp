#include "menuwindow.hpp"
#include "tictactoe_single.hpp"
#include "graphics.hpp"
#include "statictext.hpp"
#include "button.hpp"
#include "gamewindow.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <set>
using namespace genv;
using namespace std;
using namespace std::chrono;

Menu::Menu() {
    StaticText *title = new StaticText(this, 10, 10, 50, "Nagyon meno amoba jatek");
    StaticText *madeby = new StaticText(this, 510, 680, 30, "Keszitette: Marczi Richard Mark(BKG01U)");
    Button *quitb = new Button(this, 255, 500, 200, 40, "quit", [this]() { this->quit(); });
    Button *starb = new Button(this, 625, 500, 200, 40, "start", [this]() { this->start(); });

    int meret = 3;

    for (int i = 0; i < meret; ++i) {
        for (int j = 0; j < meret; ++j) {
            tt.push_back(new TicTacToe_single(this, 390+ j * 100, 150 + i * 100, 100, 100));
        }
    }

    // Start the timer thread
    timer_thread = thread(&Menu::timer_thread_function, this);
}

void Menu::quit() {
    stop = true;
}

void Menu::start() {
    Game game_window;
    game_window.run();
}

void Menu::run() {
    mainloop();
}

void Menu::handle(genv::event ev) {

}

void Menu::timer_thread_function() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 8);
    while (!stop) {
        // Sleep for 1 seconds
        this_thread::sleep_for(milliseconds(500));

        // Call statebe for each TicTacToe_single instance
         int a = distribution(gen);
            tt[a]->statebe(p % 2);


        // Increment player
        p++;
}
}
