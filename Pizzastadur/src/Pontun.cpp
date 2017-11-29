#include "Pontun.h"

Pontun::Pontun(int pizzaNumber)
{
//    cin >> _pizza;
    _pizzaNumber = pizzaNumber;
    _hasBeenPayedFor = false;
    _hasBeenBaked = false;
    _hasBeenDelevired = false;
}
Pontun::Pontun()
{
//    cin >> _pizza;
    _pizzaNumber = -1;
    _hasBeenPayedFor = false;
    _hasBeenBaked = false;
    _hasBeenDelevired = false;
}

bool Pontun::hasBeenPayedFor(){
    return _hasBeenPayedFor;
}
void Pontun::payOrder(){
    _hasBeenPayedFor = true;
}


ostream& operator << (ostream& out, const Pontun& pontun){

    out << "pizza no " << pontun._pizzaNumber << endl;
    out << "has been payed for " << pontun._hasBeenPayedFor << endl;
    out << "has been baked " << pontun._hasBeenBaked << endl;
    out << "has been deleveried " << pontun._hasBeenDelevired << endl;


    return out;
}
