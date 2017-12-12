#ifndef PONTUN_H
#define PONTUN_H

#include "ToppingsMenuItem.h"
#include "Pizza.h"
#include "Toppings.h"
#include "DeliveryPlaces.h"
#include <iostream>

using namespace std;
class Pontun
{
    public:
        Pontun(int number, DeliveryPlaces place);
        Pontun();
        friend ostream& operator << (ostream& out, const Pontun& pontun);
        friend istream& operator >> (istream& in, Pontun& order);
        // Viðskiptavinur borgar fyrir pizzuna
        bool IsOrderPaid();
        void payOrder();
        //Pizzan er reddy þegar hún er bokuð og búið að borga
        bool isOrderReady();
        void makeOrderReady();
        // Það er bara hægt að delevera pizzur sem eru borgaðar
        // og bakaðar
        bool IsOrderDelivered();
        void deliverOrder();
        void ComputeTotalPrice(double price);
        int GetOrderNo() const;

    private:
        char _places[32];
        DeliveryPlaces _place;
        double _price;
        bool _hasBeenPaid;
        bool _isReady;
        bool _hasBeenDelivered;
        int _orderNumber;
};

#endif // PONTUN_H
