#ifndef SPINBOX_HPP
#define SPINBOX_HPP


#include "graphics.hpp"
#include "parentwidget.hpp"

class SpinBox : public ParentWidget {
 protected:
    int _value;
    int _max;
    int _min;
    bool focus;
public:
    SpinBox(ParentWindow *p,int x, int y, int sx, int sy, int value, int max, int min);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_active() ;

};



#endif // SPINBOX_HPP
