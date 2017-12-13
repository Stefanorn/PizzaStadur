#include "PizzaMenu.h"

PizzaMenu::PizzaMenu(){
    _toppingIndex = 0;

}
istream& operator >> (istream& ins, PizzaMenu& pizza){
    bool base = false, pSize = false;

    cout << "Enter name of pizza : ";
    ins >> pizza._name;
    char input;
    cout << "Enter hotkey for your pizza : ";
    ins >> pizza._hotkey;

    while (base == false)
    {
        cout << "Enter base type: " << endl;
        cout << "Press 1 for Regular \nPress 2 for thin " << endl;
        cout << "Press 3 for Pan \nPress 4 for Spelt" << endl;
        ins >> input;
        try
        {
            switch (input){
                case '1': pizza._base = REGULAR; base = true; break;
                case '2': pizza._base = THIN; base = true; break;
                case '3': pizza._base = PAN; base = true; break;
                case '4': pizza._base = SPELT; base = true; break;
            }
        }
        catch (invalidBaseIndex)
        {
            cout << "Invalid input" << endl;
            base = false;
        }
    }

    while (pSize == false)
    {
        cout << "Enter size of pizza: " << endl;
        cout << "Press 1 for small\nPress 2 for medium\nPress 3 for large" << endl;
        ins >> input;
        try
        {
            switch (input){
                case '1': pizza._size = SMALL; pSize = true; break;
                case '2': pizza._size = MEDIUM; pSize = true; break;
                case '3': pizza._size = LARGE; pSize = true; break;
            }
        }
        catch (invalidSizeIndex)
        {
            cout << "Invalid input" << endl;
            pSize = false;
        }
    }

    cout << "Enter the price of pizza ";
    ins >> pizza._price;

    while (ins.fail()){
        ins.clear();
        ins.ignore();
        cout << "Invalid input enter valid input ";
        ins >> pizza._price;
    }

    return ins;
}
ostream& operator << (ostream& outs, const PizzaMenu& pizza){

    outs << "Menu item name " << pizza._name << endl;
    outs << "Price " << pizza._price << " kr." << endl;
    outs << "Toppings : " << endl;
    for(int i = 0; i < pizza._toppingIndex; i++ ){
        outs << pizza._toppings[i];
    }
    outs << "Base : " ;
    switch (pizza._base){
        case PAN : outs << "pan"; break;
        case REGULAR : outs << "regular"; break;
        case SPELT : outs << "spelt"; break;
        case THIN : outs << "thin"; break;
        default : break;
    }

    outs << endl << "Size : ";
    switch (pizza._size){
        case LARGE : outs << "large"; break;
        case SMALL : outs << "small"; break;
        case MEDIUM : outs << "medium"; break;
        default : break;
    }
    outs << endl;
    outs << "Press '" << pizza._hotkey << "' to add this item to your order " << endl;


    return outs;
}

void PizzaMenu::addTopping( Toppings item ){
   if(_toppingIndex == 15){
        throw toManyToppingsExeptions();
   }
    _toppings[ _toppingIndex ] = item;
    _toppingIndex ++;

}

string PizzaMenu::getName(){
    return _name;
}

char PizzaMenu::getKey(){
    return _hotkey;
}

pizzaBase PizzaMenu::getBase(){
    return _base;
}

pizzaSize PizzaMenu::getSize(){
    return _size;
}

Pizza PizzaMenu::getPizza(){

    Pizza temp(_base, _size, _price);
    for(int i = 0; i < _toppingIndex; i++){
        temp.addToppings(_toppings[i]);
    }

    return temp;
}
