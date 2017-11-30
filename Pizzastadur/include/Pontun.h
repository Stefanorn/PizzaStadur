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


       // Vi�skiptavinur borgar fyrir pizzuna
        bool hasBeenPayedFor();
        void payOrder();

        //Bakarinn bakar pizzuna
        bool hasBeenBaked();
        void bakePizza();

        //Pizzan er reddy �egar h�n er boku� og b�i� a� borga
        bool isPizzaReddy();
        void makePizzaReddy();

        // �a� er bara h�gt a� delevera pizzur sem eru borga�ar
        // og baka�ar
        bool isPizzaDeleverd();
        void deleverPizza();

    protected:

    private:
        Pizza _pizza; //Breyta �essu � array �� get �g haft margar pizzur i s�mu p�ntun
        bool _hasBeenPayedFor;
        bool _hasBeenBaked;
        bool _isReddy;
        bool _hasBeenDelevired;
        int _pizzaNumber;
        //char[100] info; //Auka uppl�singar
        //auka[??] _auka; h�r mindi �g skilgreina gos franskar og auka d�t

};

#endif // PONTUN_H
