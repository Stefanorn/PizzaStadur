#ifndef PONTUN_H
#define PONTUN_H

#include "Pizza.h"
#include <iostream>
using namespace std;
class Pontun
{
    public:
        Pontun(int orderNumber);
        Pontun();
        friend ostream& operator << (ostream& out, const Pontun& pontun);


       // Viðskiptavinur borgar fyrir pizzuna
        bool hasBeenPayedFor();
        void payOrder();

        //Bakarinn bakar pizzuna
        bool hasBeenBaked(); // á frekar heima i pizzu
        void bakePizza(); // á frekar heima í pizzu

        //Pizzan er reddy þegar hún er bokuð og búið að borga
        bool isPizzaReddy();
        void makePizzaReddy();

        // Það er bara hægt að delevera pizzur sem eru borgaðar
        // og bakaðar
        bool IsOrderDeliverd();
        void deliverOrder();

        int GetPizzaNumber(); //ætti að vera get order no

    protected:

    private:
        Pizza _pizza; //má eyða þessu
        bool _hasBeenPayedFor;
        bool _hasBeenBaked;
        bool _isReddy;
        bool _hasBeenDelevired;
        int _orderNumber;
        //char[100] info; //Auka upplýsingar
        //auka[??] _auka; hér mindi ég skilgreina gos franskar og auka dót

};

#endif // PONTUN_H
