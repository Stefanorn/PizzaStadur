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
        //Pizza _pizza; //Breyta �essu � array �� get �g haft margar pizzur i s�mu p�ntun
        bool _hasBeenPayedFor;
        bool _hasBeenBaked;
        bool _hasBeenDelevired;
        int _pizzaNumber;
        //char[100] info; //Auka uppl�singar
        //auka[??] _auka; h�r mindi �g skilgreina gos franskar og auka d�t

};

#endif // PONTUN_H
