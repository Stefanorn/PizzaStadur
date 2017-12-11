#include "Pontun.h"

Pontun::Pontun(int number)
{
    _orderNumber = number;
    _hasBeenPaid = false;
    _hasBeenDelivered = false;
    _isReady = false;
}
Pontun::Pontun()
{
    _orderNumber = 0;
    _hasBeenPaid = false;
    _hasBeenDelivered = false;
    _isReady = false;
}

//Viðskiptavinurinn borgar fyrir pizzuna
bool Pontun::IsOrderPaid(){
    return _hasBeenPaid;
}
void Pontun::payOrder(){
    _hasBeenPaid = true;
}



//Pizzan er reddy þegar hún er bokuð og búið að borga
bool Pontun::isOrderReady(){
    return _isReady;

}
void Pontun::makeOrderReady(){
    _isReady = true;
}

// Það er bara hægt að delevera pizzur sem eru borgaðar
// og bakaðar
bool Pontun::IsOrderDelivered(){
    return _hasBeenDelivered;
}
void Pontun::deliverOrder(){
    _hasBeenDelivered = true;
}

int Pontun::GetOrderNo(){
    return _orderNumber;
}


ostream& operator << (ostream& out, const Pontun& pontun){

    out << "Order no " << pontun._orderNumber << endl;
    out << "has been payed for " << pontun._hasBeenPaid << endl;
    out << "has been delivered " << pontun._hasBeenDelivered << endl;

    return out;
}
istream& operator >> (istream& in, Pontun& order){

    in >> order._places;
    return in;
}
