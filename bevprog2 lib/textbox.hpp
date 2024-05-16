#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "parentwidget.hpp"
#include <string>

class TextBox : public ParentWidget {
protected:
    bool focus;
    bool caps;
    std::string _ss;
public:
    TextBox(ParentWindow *p,int x, int y, int sx, int sy, std::string ss);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_active() ;
};


#endif //
