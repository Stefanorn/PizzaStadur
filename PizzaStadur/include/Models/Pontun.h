#ifndef PONTUN_H
#define PONTUN_H

#include "Pizza.h"
#include <iostream>

using namespace std;
class Pontun
{
    public:
        Pontun(int number);
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

        int GetOrderNo(); //ætti að vera get order no

    protected:

    private:
        char _places[32];

        bool _hasBeenPaid;
        bool _isReady;
        bool _hasBeenDelivered;
        int _orderNumber;
};

#endif // PONTUN_H
