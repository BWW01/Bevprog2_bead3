#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "graphics.hpp"
#include "parentwidget.hpp"
#include "functional"

class Button : public ParentWidget
{
protected:
        bool focus;
        std::function<void()> f;
        std::string label;
public:
    Button(ParentWindow *p,int x, int y, int sx, int sy,std::string _label, std::function<void()> f);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual bool is_active();

};


#endif // BUTTON_HPP
