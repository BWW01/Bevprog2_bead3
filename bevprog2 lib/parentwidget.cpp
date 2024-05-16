#include "parentwidget.hpp"
#include "graphics.hpp"
#include "parentwindow.hpp"
using namespace genv;
ParentWidget::ParentWidget(ParentWindow* window, int x, int y, int sx, int sy):
    _window(window), _x(x), _y(y), _sx(sx), _sy(sy)
{
    _window->new_widget(this);

}

bool ParentWidget::interact(int mx, int my)
{
    return  mx>_x&&
            mx<_sx+_x&&
            my>_y&&
            my<_sy+_y;

}
