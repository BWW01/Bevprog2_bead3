#include "spinbox.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>
using namespace genv;



SpinBox::SpinBox(ParentWindow *p,int x, int y, int sx, int sy, int value, int max, int min)
    : ParentWidget(p,x,y,sx,sy), _value(value), _max(max), _min(min)
{
}

void SpinBox::draw()
{
    gout.load_font("LiberationSans-Regular.ttf", _sy-4,1);
    gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
    gout << move_to(_x+1, _y+1) << color(0,0,0) << box(_sx-2, _sy-2);
    gout << move_to(_x+3, _y/*+_s_y*0.5+gout.cascent()/2*/)<<color(255,255,255)<<text(std::to_string(_value));
    gout << move_to(_x+_sx-3,_y+2)<<box(-_sy*0.5+3,_sy*0.5-3)<< move_to(_x+_sx-3,_y+_sy-3)<<box(-_sy*0.5+3,-_sy*0.5+3);
}

void SpinBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_escape)) {
            focus = !focus;
    }
    if (ev.type == ev_mouse &&
        interact(ev.pos_x, ev.pos_y) &&
         ev.button==btn_left) {
        focus = !focus;
    }
    if(_value< _max){
        if(ev.keycode== key_pgup){_value+=10;}
        if(ev.keycode== key_up){_value+=1;}
        if (ev.type == ev_mouse && ev.pos_x<_x+_sx-3&&ev.pos_x>_x+_sx-3-_sy*0.5+3  && ev.pos_y>_y+2 && ev.pos_y<_y+2+_sy*0.5-3  &&ev.button==btn_left) {
            _value+=1;
        }
    }
    if(_value> _min){
        if(ev.keycode== key_down){_value-=1;}
        if(ev.keycode== key_pgdn){_value-=10;}
        if (ev.type == ev_mouse && ev.pos_x<_x+_sx-3&&ev.pos_x>_x+_sx-3-_sy*0.5+3  && ev.pos_y<_y+_sy-3 && ev.pos_y>_y+_sy-3 -_sy*0.5+3 &&ev.button==btn_left) {
            _value-=1;
        }
    }


}
bool SpinBox::is_active()
{
    return focus;
}
