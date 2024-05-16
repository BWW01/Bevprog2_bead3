#include "graphics.hpp"
#include "parentwidget.hpp"
#include "parentwindow.hpp"
#include "spinbox.hpp"
#include "statictext.hpp"
#include <vector>
#include <string>
#include "textbox.hpp"
#include "listbox.hpp"
#include "button.hpp"
#include <iostream>
using namespace std;
using namespace genv;

const int MXX = 400;
const int MYY = 700;

class Game;//<---- predec hogy tudjuk hogy lesz majd

class Menu : public ParentWindow
{
public:
    Menu() {
        StaticText *title = new StaticText(this, 10, 10, 30, "Nagyon meno amoba jatek");
        StaticText *madeby = new StaticText(this, 10, 50, 15, "Keszitette: Marczi Richard Mark(BKG01U)");
        Button *quitb = new Button(this, 50, 500, 100, 20, "quit", [this]() { this->quit(); });
        Button *starb = new Button(this, 250, 500, 100, 20, "start", [this]() { this->start(); });
    }

    void quit() {
        stop = true;
    }

    void start(); //<---- kesobb defined mert itt nem tudjuk what is Game window
};

class Game : public ParentWindow
{
public:
    Game() {
    }


};

void Menu::start() {
    delete this;
    this->initwindow(800, 800);
    //this->mainloop(800, 800);//<--- kell hogy legyen ev loop

}

int main()
{
    Menu* window = new Menu;

    vector<ParentWidget*> w;

    for (ParentWidget *wg : w) {
        wg->draw();
    }
    window->initwindow(MXX, MYY);
    window->mainloop(MXX,MYY);


    gout << refresh;
    return 0;
}
