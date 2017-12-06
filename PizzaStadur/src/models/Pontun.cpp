#include "Pontun.h"

Pontun::Pontun(int orderNumber)
{
    _orderNumber = orderNumber;
    _hasBeenPayedFor = false;
    _hasBeenBaked = false;
    _hasBeenDelevired = false;
    _isReddy = false;

}
Pontun::Pontun()
{
    _orderNumber = -1;
    _hasBeenPayedFor = false;
    _hasBeenBaked = false;
    _hasBeenDelevired = false;
    _isReddy = false;
}

//Vi�skiptavinurinn borgar fyrir pizzuna
bool Pontun::hasBeenPayedFor(){
    return _hasBeenPayedFor;
}
void Pontun::payOrder(){
    _hasBeenPayedFor = true;
}

//Bakarinn bakar pizzuna
bool Pontun::hasBeenBaked(){
    return _hasBeenBaked;
}
void Pontun::bakePizza(){

    _hasBeenBaked = true;
}

//Pizzan er reddy �egar h�n er boku� og b�i� a� borga
bool Pontun::isPizzaReddy(){
    return _isReddy;

}
void Pontun::makePizzaReddy(){
    _isReddy = true;
}

// �a� er bara h�gt a� delevera pizzur sem eru borga�ar
// og baka�ar
bool Pontun::IsOrderDeliverd(){
    return _hasBeenDelevired;
}
void Pontun::deliverOrder(){
    _hasBeenDelevired = true;
}

int Pontun::GetPizzaNumber(){
    return _orderNumber;
}


ostream& operator << (ostream& out, const Pontun& pontun){

    out << "Order no " << pontun._orderNumber << endl;
    out << pontun._pizza;
    out << "has been payed for " << pontun._hasBeenPayedFor << endl;
    out << "has been baked " << pontun._hasBeenBaked << endl;
    out << "has been deleveried " << pontun._hasBeenDelevired << endl;

    return out;
}
