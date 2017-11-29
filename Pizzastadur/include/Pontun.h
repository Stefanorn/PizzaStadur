#ifndef PONTUN_H
#define PONTUN_H

#include "Pizza.h"
#include <iostream>
using namespace std;
class Pontun
{
    public:
        Pontun(int pizzaNumber);
        Pontun();
        friend ostream& operator << (ostream& out, const Pontun& pontun);
        bool hasBeenPayedFor();
        void payOrder();

    protected:

    private:
        //Pizza _pizza; //Breyta þessu í array þá get ég haft margar pizzur i sömu pöntun
        bool _hasBeenPayedFor;
        bool _hasBeenBaked;
        bool _hasBeenDelevired;
        int _pizzaNumber;
        //char[100] info; //Auka upplýsingar
        //auka[??] _auka; hér mindi ég skilgreina gos franskar og auka dót

};

#endif // PONTUN_H
