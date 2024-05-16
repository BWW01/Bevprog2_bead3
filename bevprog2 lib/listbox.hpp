#ifndef LISTBOX_HPP
#define LISTBOX_HPP

#include <vector>
#include <string>
#include "graphics.hpp"
#include "parentwidget.hpp"

class ListBox : public ParentWidget {
private:
    int _hovered_index;
    int _selected_index;
    int selected;
protected:
    std::vector<std::string> _items;
    bool focus;
    int _startpoint;
    int _shown;

public:
    ListBox(ParentWindow *p,int x, int y, int sx, int sy, std::vector<std::string> items,int _shown);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual bool is_active();
    virtual bool interact(int m_x, int m_y);
    int getindex();
    void update(std::vector<std::string>list);
};

#endif // LISTBOX_HPP
