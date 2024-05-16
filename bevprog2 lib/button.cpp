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
    gout<< move_to(_x,_y)<<color(123,123,123)<< box(_sx,_sy );
    gout << move_to(_x + 3, _y + (_sy - gout.cascent() - gout.cdescent()) / 2) << color(0, 0, 0) << text(label);

}

void Button::handle(event ev)
{

    if (ev.type == ev_key && ev.keycode == key_escape) {
        focus = !focus;
    }

    if (interact(ev.pos_x,ev.pos_y)&& ev.button == 1) {
         f();
    }


}



bool Button::is_active()
{
    return focus;
}

