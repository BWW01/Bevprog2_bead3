#ifndef PARENTWIDGET_HPP
#define PARENTWIDGET_HPP
#include "parentwindow.hpp"
#include "graphics.hpp"
class ParentWindow;
class ParentWidget
{
    protected:
        int _x, _y, _sx, _sy;
        ParentWindow* _window;
    public:

        ParentWidget( ParentWindow* window, int x, int y, int sx, int sy);
        virtual bool interact(int mx, int my);
        virtual void draw() = 0;
        virtual void handle(genv::event ev) = 0;

};

#endif // PARENTWIDGET_HPP
