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
        // Vi�skiptavinur borgar fyrir pizzuna
        bool IsOrderPaid();
        void payOrder();
        //Pizzan er reddy �egar h�n er boku� og b�i� a� borga
        bool isOrderReady();
        void makeOrderReady();
        // �a� er bara h�gt a� delevera pizzur sem eru borga�ar
        // og baka�ar
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
