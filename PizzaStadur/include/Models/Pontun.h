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

       // Vi�skiptavinur borgar fyrir pizzuna
        bool hasBeenPayedFor();
        void payOrder();

        //Pizzan er reddy �egar h�n er boku� og b�i� a� borga
        bool isOrderReddy();
        void makeOrderReddy();

        // �a� er bara h�gt a� delevera pizzur sem eru borga�ar
        // og baka�ar
        bool IsOrderDeliverd();
        void deliverOrder();

        int GetOrderNo(); //�tti a� vera get order no

    protected:

    private:
        char _places[32];

        bool _hasBeenPayedFor;
        bool _isReddy;
        bool _hasBeenDelevired;
        int _orderNumber;
};

#endif // PONTUN_H
