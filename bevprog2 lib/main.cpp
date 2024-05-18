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
#include "menuwindow.hpp"
#include "gamewindow.hpp"

using namespace std;
using namespace genv;

int main()
{

    Menu menu_window;
    menu_window.initwindow();
    menu_window.run(); // Initialize and run the menu window

    return 0;
}

