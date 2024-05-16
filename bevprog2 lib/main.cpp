#include "graphics.hpp"
#include "parentwidget.hpp"
#include "parentwindow.hpp"
#include "spinbox.hpp"
#include "statictext.hpp"
#include <vector>
#include <string>
#include "textbox.hpp"
#include "listbox.hpp"
#include "button.hpp"
using namespace std;
using namespace genv;
const int XX = 500;
const int YY = 800;

class NewWindow  : public ParentWindow
{

    public:
    vector <string> v1 = {"eyes", "deeply", "panicky", "makeshift", "warlike", "nippy",
        "groovy", "dock", "eatable", "engine", "toe", "afterthought",
        "vast", "jealous", "shiny", "whirl", "race", "finger", "polish",
        "previous", "wink", "cold", "knife", "back", "nebulous", "sticks",
        "flimsy", "sail", "amusement", "sore", "animal", "milky",
        "exuberant", "jobless", "cruel", "tawdry", "face", "scarf",
        "nifty", "geese"};
    vector <string> v2 =  {"wohoo","Wohooo"};
    StaticText * st1 = new StaticText(this,100,100,11,"WOHOOOOOOOOOOOOOOOOOOOOO");
    TextBox * tb1 = new TextBox(this,10,10,300,20,"");
    TextBox * tb2 = new TextBox(this,10,110,300,20,"");
    SpinBox * sb1 = new SpinBox(this,10,210,100,20,10,20,0);
    Button * b1 = new Button(this, 10, 510, 100,20,"Atrak", [this](){atrak(); update(); });
    Button * b2 = new Button(this, 210, 510, 100,20,"Torol", [this](){torol(); update(); });
    Button * b3 = new Button(this, 310, 510, 100,20,"Torol2", [this](){torol2(); update(); });
    ListBox * lb1 = new ListBox(this,10,310,100,20,
                      v1
        ,7);
    ListBox * lb2 = new ListBox(this,210,310,100,20,
                        v2
        ,7);
    void atrak(){
    int cInd = lb1 -> getindex();
    if(cInd != -1){
        v2.push_back(v1[cInd]);
        v1.erase(v1.begin()+cInd);
    }
    }
    void torol(){
        int cInd = lb1 -> getindex();
        if(cInd != -1){
            v1.erase(v1.begin()+cInd);
        }
    }
    void torol2(){
        int cInd = lb1 -> getindex();
        if(cInd != -1){
            v2.erase(v2.begin()+cInd);
        }
    }

    void update(){
    lb1->update(v1);
    lb2->update(v2);
    }
};




int main()
{
    NewWindow* window = new NewWindow;
    gout.open(XX,YY);

    vector<ParentWidget*> w;

    for (ParentWidget * wg : w) {
        wg->draw();
    }

    window->mainloop(XX,YY);
    gout << refresh;
    return 0;
}
