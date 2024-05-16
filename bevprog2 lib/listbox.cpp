#include "listbox.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>
using namespace genv;
using namespace std;

ListBox::ListBox(ParentWindow *p,int x, int y, int sx, int sy, vector<string> items,int _shown)
    : ParentWidget(p,x, y, sx, sy), _items(items), focus(false), _startpoint(0), _shown(_shown), _hovered_index(-1),selected(-1), _selected_index(-1)
{

}

void ListBox::draw()
{



    gout << move_to(_x, _y) << color(255, 255, 255) << box(_sx, _sy);

    gout.load_font("LiberationSans-Regular.ttf", _sy - 10, 1);
    for (int i = 0; i < _shown; i++) {
        int index = _startpoint + i;
        if (index >= 0 && index < _items.size()) {
            int item_y = _y + i * _sy;
            if (index == _hovered_index || index == _selected_index) {
                gout << move_to(_x , item_y ) << color(100, 100, 100) << box(_sx , _sy );
                gout << move_to(_x + 3, item_y + (_sy - gout.cascent() - gout.cdescent()) / 2) << color(255, 255, 255) << text(_items[index]);
            } else {

                gout << move_to(_x , item_y ) << color(255, 255, 255) << box(_sx , _sy );
                gout << move_to(_x + 3, item_y + (_sy - gout.cascent() - gout.cdescent()) / 2) << color(0, 0, 0) << text(_items[index]);
            }
        }
    }
    gout << move_to(_x + _sx * 0.9, _y) << color(128, 128, 128) << box(_sx * 0.1, _sy * _shown)
    << move_to(_x + _sx * 0.9 + 2, _y + 2) << color(255, 255, 255) << box(_sx * 0.1 - 4, _sy * _shown - 4);

// KÉRDEZD MEG A STATIC_CAST FLOATOT!!!!!!!
float scrollbar_height = _sy* (static_cast<float>(_shown) / _items.size())*_shown ;
float scrollbar_position = _startpoint * _sy * _shown / _items.size();
gout << move_to(_x + _sx * 0.9 + 4, _y + scrollbar_position + 4) << color(128, 128, 128)
    << box(_sx * 0.1 - 8, scrollbar_height - 8);
}

bool ListBox::interact(int m_x, int m_y)
{
    return
    m_x >   _x &&
    m_x <   _x+_sx &&
    m_y >   _y &&
    m_y <   _y+_shown*_sy;

    ///extended interact size overwrites the original one its fun and useful :PP
}

void ListBox::handle(event ev)
{

     if(_shown> _items.size()){
        _shown = _items.size();
    }
    ///set max size so it doesnt scroll to 0

    if (ev.type == ev_mouse) {
        if (ev.pos_x> _x && ev.pos_x< _x+_sx) {
            _hovered_index = (ev.pos_y - _y) / _sy + _startpoint;
        } else {
            _hovered_index = -1;
        }
    }

    if (ev.button == btn_wheelup) {
        if (_startpoint > 0) {
            _startpoint--;
        }
    } else if (ev.button == btn_wheeldown) {
        if (_startpoint < _items.size() - _shown) {
            _startpoint++;
        }
    }
    if(interact(ev.pos_x,ev.pos_y)&& ev.button == 1&&focus){
        _selected_index =_hovered_index;
    }

    if (ev.type == ev_key && ev.keycode == key_escape) {
        focus = !focus;
    }

    if (interact(ev.pos_x,ev.pos_y)&& ev.button == 1) {
        focus = true;
    }

}

int ListBox::getindex(){
    return _selected_index;
}

void ListBox::update(vector<string> list){
    _items = list;
}


bool ListBox::is_active()
{
    return focus;
}
