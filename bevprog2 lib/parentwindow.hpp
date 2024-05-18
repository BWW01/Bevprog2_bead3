#ifndef PARENTWINDOW_HPP
#define PARENTWINDOW_HPP

#include "graphics.hpp"
#include "parentwidget.hpp"
#include <vector>

class ParentWidget;

class ParentWindow
{
public:
    const int XX = 1080;
    const int YY = 720;
    void mainloop();
    void new_widget(ParentWidget *w) { widgettarto.push_back(w); }
    virtual void handle(genv::event ev) = 0;
    void initwindow(); // Move initwindow function to ParentWindow

protected:


    std::vector<ParentWidget*> widgettarto;
    bool stop = false; // Initialize stop variable
    bool open = false;
    void quit(bool stop);
};

#endif // PARENTWINDOW_HPP
