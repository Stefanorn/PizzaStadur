#include "Pontun.h"

Pontun::Pontun(int number)
{
    _orderNumber = number;
    _hasBeenPayedFor = false;
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



//Pizzan er reddy �egar h�n er boku� og b�i� a� borga
bool Pontun::isOrderReddy(){
    return _isReddy;

}
void Pontun::makeOrderReddy(){
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

int Pontun::GetOrderNo(){
    return _orderNumber;
}


ostream& operator << (ostream& out, const Pontun& pontun){

    out << "Order no " << pontun._orderNumber << endl;
    out << "has been payed for " << pontun._hasBeenPayedFor << endl;
    out << "has been deleveried " << pontun._hasBeenDelevired << endl;

    return out;
}
istream& operator >> (istream& in, Pontun& order){

    in >> order._places;
    return in;
}
