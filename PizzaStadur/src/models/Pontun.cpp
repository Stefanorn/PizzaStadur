#include "Pontun.h"

Pontun::Pontun(int number)
{
    _orderNumber = number;
    _hasBeenPayedFor = false;
    _hasBeenDelevired = false;
    _isReddy = false;
}

//Viðskiptavinurinn borgar fyrir pizzuna
bool Pontun::hasBeenPayedFor(){
    return _hasBeenPayedFor;
}
void Pontun::payOrder(){
    _hasBeenPayedFor = true;
}



//Pizzan er reddy þegar hún er bokuð og búið að borga
bool Pontun::isOrderReddy(){
    return _isReddy;

}
void Pontun::makeOrderReddy(){
    _isReddy = true;
}

// Það er bara hægt að delevera pizzur sem eru borgaðar
// og bakaðar
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
