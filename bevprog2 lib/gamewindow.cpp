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


Game::Game() : ParentWindow() {
        // Access the stop member of the Menu class and set it to true
        StaticText *title = new StaticText(this, XX/2,YY/2,30,"Szeretlek Rozika");
        Button *quitb = new Button(this, 50, 500, 100, 20, "quit", [this]() { this->quit(); });
}

void Game:: run(){
    mainloop(XX, YY);
}
void Game::quit() {
    stop = true;
}
