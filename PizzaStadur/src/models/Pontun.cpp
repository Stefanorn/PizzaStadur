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

double Pontun::ComputeTotalPrice() const{
    ToppingsMenuItem menuItem;
    Pizza pizza;
    Toppings topping;
    return menuItem.getPrice() + pizza.getPrice() + topping.getToppingPrice();
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

int Pontun::GetOrderNo() const{
    return _orderNumber;
}

ostream& operator << (ostream& out, const Pontun& pontun){
    out << "Order no " << pontun._orderNumber << endl;
    out << "Total price: " << pontun.ComputeTotalPrice() << endl;
    if(pontun._hasBeenPaid){
        out << "has been paid" << endl;
    }
    else{
        out << "has not been paid" << endl;
    }

    if(pontun._hasBeenDelivered){
        out << "has been delivered" << endl;
    }
    else{
        out << "has not been delivered" << endl;
    }
    return out;
}
istream& operator >> (istream& in, Pontun& order){

    in >> order._places;
    return in;
}
