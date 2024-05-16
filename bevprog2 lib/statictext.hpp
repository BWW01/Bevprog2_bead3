#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"
#include <string>

class StaticText : public ParentWidget {
protected:
    std::string _stext;
    int _textsize;
public:
    StaticText(ParentWindow *p, int x, int y,int textsize, std::string stext);
    virtual void draw();
    virtual void handle(genv::event ev);
};
#endif //
