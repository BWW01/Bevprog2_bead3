#ifndef PARENTWINDOW_HPP
#define PARENTWINDOW_HPP
#include "graphics.hpp"
#include "parentwidget.hpp"
#include <vector>

class ParentWidget;

class ParentWindow
{
public:
    void initwindow(int x, int y);
    void mainloop(int x, int y);
    void new_widget(ParentWidget *w) { widgettarto.push_back(w); }
    void quit(bool stop);

protected:
    std::vector<ParentWidget*> widgettarto;
    bool stop = false; // Initialize stop variable
};

#endif // PARENTWINDOW_HPP
