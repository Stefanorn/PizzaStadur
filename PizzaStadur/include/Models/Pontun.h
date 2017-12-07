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
        bool hasBeenPayedFor();
        void payOrder();

        //Pizzan er reddy þegar hún er bokuð og búið að borga
        bool isOrderReddy();
        void makeOrderReddy();

        // Það er bara hægt að delevera pizzur sem eru borgaðar
        // og bakaðar
        bool IsOrderDeliverd();
        void deliverOrder();

        int GetOrderNo(); //ætti að vera get order no

    protected:

    private:
        char _places[32];

        bool _hasBeenPayedFor;
        bool _isReddy;
        bool _hasBeenDelevired;
        int _orderNumber;
};

#endif // PONTUN_H
