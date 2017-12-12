#include "PizzaMenu.h"

PizzaMenu::PizzaMenu(){
    //ctor
}

istream& operator >> (istream& ins, PizzaMenu& pizza){
    bool base = false, pSize = false;

    cout << "enter Name of pizza";
    ins >> pizza._name;
    char input;

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
        cout << "Invalid input enter valid input ";
        ins >> pizza._price;
    }

    return ins;
}
ostream& operator << (ostream& outs, const PizzaMenu& pizza){
    return outs;
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
