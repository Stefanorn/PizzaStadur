#include "ToppingsMenuItem.h"


istream& operator >> (istream& ins, ToppingsMenuItem& toppingsMenuItem){
    cout << "enter topping name " << endl;
    ins >> toppingsMenuItem._name;
    cout << "Enter hotkey for item " << endl;
    ins >> toppingsMenuItem._hotkey;
    cout << "Enter Price for item " << endl;
    ins >> toppingsMenuItem._price;
    return ins;

}
ostream& operator << (ostream& outs, const ToppingsMenuItem& toppingsMenuItem){
    outs << toppingsMenuItem._name << endl;
    outs << "press " << toppingsMenuItem._name << " to add this to your pizza" << endl;
    outs << "This item cost " << toppingsMenuItem._price << endl;
    return outs;
}

char ToppingsMenuItem::getHotkey(){
    return _hotkey;
}
double ToppingsMenuItem::getPrice(){
    return _price;
}
