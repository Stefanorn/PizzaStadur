#include "Pizza.h"

Pizza::Pizza(){

}

istream& operator >> (istream& ins, Pizza& pizza){
    cout << "Enter name of pizza: ";
    ins >> pizza._name;
    cout << "Enter base type: ";
    ins >> pizza._base;
    cout << "Enter size of pizza: ";
    ins >> pizza._size;

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
