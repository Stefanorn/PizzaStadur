#ifndef PONTUN_H
#define PONTUN_H

#include "ToppingsMenuItem.h"
#include "Pizza.h"
<<<<<<< HEAD
#include "Toppings.h"
=======
#include "DeliveryPlaces.h"
>>>>>>> 270e4cb84879dde3b1a354da5dcf2996fa2a5053
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
<<<<<<< HEAD
        int GetOrderNo() const;
        double ComputeTotalPrice() const;

    private:
        char _places[32];
=======

        int GetOrderNo();

    private:

        DeliveryPlaces _place;
>>>>>>> 270e4cb84879dde3b1a354da5dcf2996fa2a5053
        bool _hasBeenPaid;
        bool _isReady;
        bool _hasBeenDelivered;
        int _orderNumber;
};

#endif // PONTUN_H
