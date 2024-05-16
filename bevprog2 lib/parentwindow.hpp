#ifndef PARENTWINDOW_HPP
#define PARENTWINDOW_HPP
#include "graphics.hpp"
#include "parentwidget.hpp"
#include <vector>

class ParentWidget;
class ParentWindow
{
    public:
        void mainloop(int x,int y);
        void new_widget(ParentWidget *w) {widgettarto.push_back(w);};

    protected:
        std:: vector<ParentWidget*> widgettarto;

};

#endif // PARENTWINDOW_HPP
