#include "textbox.hpp"
#include "graphics.hpp"
#include <string>
using namespace genv;

TextBox::TextBox(ParentWindow *p,int x, int y, int sx, int sy, std::string ss)
    : ParentWidget(p,x,y,sx,sy),_ss(ss)
{
    focus=false;
    caps = true;
}

void TextBox::draw()
{
    gout.load_font("LiberationSans-Regular.ttf", _sy-4,1);
    gout
    << move_to(_x,_y)
    << color(255,255,255)
    <<box(_sx,_sy)
    <<move_to(_x+1,_y+1)
    << color(0,0,0)
    <<box(_sx-2,_sy-2)
    <<move_to(_x+2,_y)
    <<color(255,255,255)
    <<text(_ss);
    if (focus) {
        gout
        <<move_to(_x+2+gout.twidth(_ss),_y+_sy*0.1)
        <<color(255,255,255)
        <<line(0,_sy*0.8);
    }
}

void TextBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_escape)) {
            focus = !focus;
    }
    if (ev.type == ev_mouse && interact(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        focus = !focus;
    }
    if(ev.type == ev_key&& focus&&(ev.keycode == key_backspace)){
            if (!_ss.empty())
            {
                _ss.pop_back();
            }
        }

    if(gout.twidth(_ss)<_sx*0.9 && focus){
        if(ev.type == ev_key){
        _ss += ev.keyutf8;
        }
    }
    /*if(ev.keycode == key_capsl){
        caps = !caps ;
    }*/



}
bool TextBox::is_active()
{
    return focus;
}

