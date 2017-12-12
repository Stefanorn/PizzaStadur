#include "ToppingsMenuItem.h"


istream& operator >> (istream& ins, ToppingsMenuItem& toppingsMenuItem){
    string name;
    cout << "enter topping name : ";
    ins >> toppingsMenuItem._name;
    //std::getline(ins, name);
    //strcpy(toppingsMenuItem._name ,name.c_str());
    //toppingsMenuItem._name[31] = '\0';
    //ins.ignore();
    cout << "Enter hotkey for item : ";
    ins >> toppingsMenuItem._hotkey;
    while( !isalpha(toppingsMenuItem._hotkey) ){
        cout << "Invalid hotkey enter a valid hotkey : ";
        ins >> toppingsMenuItem._hotkey;
    }
    cout << "Enter Price for item : ";
    ins >> toppingsMenuItem._price;
    while(ins.fail()){
        ins.clear();
        ins.ignore();
        cout << "Incorrect Input enter a valid input for price : ";
        ins >> toppingsMenuItem._price;
    }
    return ins;

}
ostream& operator << (ostream& outs, const ToppingsMenuItem& toppingsMenuItem){
    outs << toppingsMenuItem._name << endl;
    outs << "press '" << toppingsMenuItem._hotkey << "' to add this to your pizza" << endl;
    outs << "This item cost " << toppingsMenuItem._price << endl;
    return outs;
}

Toppings ToppingsMenuItem::createTopping(){
    return Toppings( _name, _price, 0 );
}

char ToppingsMenuItem::getHotkey(){
    return _hotkey;
}
double ToppingsMenuItem::getPrice(){
    return _price;
}
string ToppingsMenuItem::getName(){
    return _name;
}
