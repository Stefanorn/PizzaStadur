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

//Vi�skiptavinurinn borgar fyrir pizzuna
bool Pontun::IsOrderPaid(){
    return _hasBeenPaid;
}
void Pontun::payOrder(){
    _hasBeenPaid = true;
}



//Pizzan er reddy �egar h�n er boku� og b�i� a� borga
bool Pontun::isOrderReady(){
    return _isReady;

}
void Pontun::makeOrderReady(){
    _isReady = true;
}

// �a� er bara h�gt a� delevera pizzur sem eru borga�ar
// og baka�ar
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
