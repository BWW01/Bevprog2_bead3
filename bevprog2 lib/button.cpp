#include "button.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>
using namespace genv;
using namespace std;

Button::Button(ParentWindow *p,int x, int y, int sx, int sy,std::string _label, std::function<void()> _f)
    : ParentWidget(p,x,y, sx, sy),focus(false),f(_f),label(_label)
{

}

void Button::draw()
{
    if (focus) {
        gout << move_to(_x, _y) << color(123, 123, 123) << box(_sx, _sy);
    } else {
        gout << move_to(_x, _y) << color(222, 222, 222) << box(_sx, _sy);
    }
    gout << move_to(_x + (_sx - gout.twidth(label)) / 2, _y + (_sy - gout.cascent() - gout.cdescent()) / 2) << color(0, 0, 0) << text(label);
}


void Button::handle(event ev)
{
    if (ev.type == ev_mouse) {
        if (interact(ev.pos_x, ev.pos_y)) {
            if (ev.button == 1) { // Left mouse button pressed
                focus = true;
            } else if (ev.button == -1) { // Left mouse button released
                focus = false;
                if (interact(ev.pos_x, ev.pos_y)) {
                    f();
                }
            }
        } else if (ev.button == -1) { // Left mouse button released outside the button
            focus = false;
        }
    }
}





bool Button::is_active()
{
    return focus;
}

