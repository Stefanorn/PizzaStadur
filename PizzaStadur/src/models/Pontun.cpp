#include "Pontun.h"

Pontun::Pontun(int number , DeliveryPlaces place)
{
    _price = 0;
    _place = place;
    _orderNumber = number;
    _hasBeenPaid = false;
    _hasBeenDelivered = false;
    _isReady = false;
    _isDelivered = false;
}
Pontun::Pontun()
{
    _price = 0;
     _place = DeliveryPlaces();
    _orderNumber = 0;
    _hasBeenPaid = false;
    _hasBeenDelivered = false;
    _isReady = false;
    _isDelivered = false;
}

//Viðskiptavinurinn borgar fyrir pizzuna
bool Pontun::IsOrderPaid(){
    return _hasBeenPaid;
}

void Pontun::payOrder(){
    _hasBeenPaid = true;
}

void Pontun::ComputeTotalPrice(double price) {
    _price += price;
}

bool Pontun::isOrderReady(){
    return _isReady;

}

void Pontun::makeOrderReady(){
    _isReady = true;
}

void Pontun::DeliveryOrPickUp(char input){
    if(input == 'd'){
        _isDelivered = true;
    }

    else if(input == 'p'){
        _isDelivered = false;
    }
}

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
    /*if(pontun._hasBeenPaid){
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
    }*/

    if(pontun._isDelivered){
        out << "To be delivered from " << pontun._place.getName() << endl;
    }
    else{
        out << "To be picked up at/in " << pontun._place.getName() << endl;
    }

    out << "Total price: " << pontun._price << endl << endl;

    return out;
}
istream& operator >> (istream& in, Pontun& order){

    return in;
}

DeliveryPlaces Pontun::getDeliveryPlace(){
    return _place;
}
