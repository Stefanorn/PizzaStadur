#include "Pizza.h"

Pizza::Pizza(){
    _orderIdNumber = -1;
    _pizzaID = -1;
    _name[0] = '\0';
    _price = 0;
    _base = REGULAR;
    _size = SMALL;
}

istream& operator >> (istream& ins, Pizza& pizza){
    cout << "Enter name of pizza: ";
    ins >> pizza._name;
    cout << "Enter base type: " << endl;
    cout << "Press 1 for Regular \nPress 2 for thin " << endl;
    cout << "Press 3 for Pan \nPress 4 for Spelt" << endl;
    char input;
    ins >> input;
    switch (input){
        case '1': pizza._base = REGULAR; break;
        case '2': pizza._base = THIN; break;
        case '3': pizza._base = PAN; break;
        case '4': pizza._base = SPELT; break;
    default: throw invalidBaseIndex(); break;
    }
    cout << "Enter size of pizza: " << endl;
    cout << "Press 1 for small\nPress 2 for medium\nPress 3 for large";
    switch (input){
        case '1': pizza._size = SMALL; break;
        case '2': pizza._size = MEDIUM; break;
        case '3': pizza._size = LARGE; break;
    default: throw invalidSizeIndex(); break;
    }

    return ins;
}

ostream& operator << (ostream& outs, const Pizza& pizza){
    outs << "Name: " << pizza._name << endl;
    outs << "Base: " << pizza._base << endl;
    outs << "Size: " << pizza._size << endl;
    return outs;
}

void Pizza::tagPizzaToOrder(int orderNo){
    _orderIdNumber = orderNo;
}
int Pizza::getPizzaToOrderId(){
    return _orderIdNumber;
}
void Pizza::setPizzaID(int id){
     _pizzaID = id;
}
int Pizza::getPizzaID(){
    return _pizzaID;
}
double Pizza::getPize(){
    return _price;
}
