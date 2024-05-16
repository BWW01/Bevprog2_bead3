#include "parentwindow.hpp"
#include "graphics.hpp"
using namespace genv;

void ParentWindow::initwindow(int XX, int YY)
{
    gout.open(XX, YY);
}

void ParentWindow::mainloop(int XX, int YY)
{

    event ev;
    int focus = -1;
    while (gin >> ev && ev.keycode != key_escape && !stop) {
        gout << move_to(0, 0) << color(0, 0, 0) << box(XX, YY);
        if (ev.type == ev_mouse && ev.button == btn_left) {
            for (size_t i = 0; i < widgettarto.size(); i++) {
                if (widgettarto[i]->interact(ev.pos_x, ev.pos_y)) {
                    focus = i;
                }
            }
        }
        if (focus != -1) {
            widgettarto[focus]->handle(ev);
        }
        for (ParentWidget *w : widgettarto) {
            w->draw();
        }
        gout << refresh;
    }
}

void ParentWindow::quit(bool stop)
{
    this->stop = stop; // Stop the main loop
}
