#include "statictext.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>
using namespace genv;

StaticText::StaticText(ParentWindow *p,int x, int y,int textsize, std::string stext):
    ParentWidget(p,x,y,1,1),_textsize(textsize),_stext(stext)
{

}

void StaticText::draw()
{
    gout.load_font("LiberationSans-Regular.ttf",_textsize,1);
    gout << move_to(_x, _y)
    << color(255,255,255)
    << genv::text(_stext);
}

void StaticText::handle(event ev)
{

}
