#include "Toppings.h"

Toppings::Toppings()
{
    _toppingName[0] = '\0';
    _toppingPrice = 200;
}

Toppings::Toppings( string toppingName, double toppingPrice , int pizzaToToppingId){

    toppingName[31] = '\0';
    strcpy (_toppingName, toppingName.c_str());
    _toppingPrice = toppingPrice;
    _toppingID = pizzaToToppingId;
}

string Toppings::getToppingName()
{
    return _toppingName;
}

int Toppings::getToppingID()
{
    return _toppingID;
}

double Toppings::getToppingPrice() const
{
    return _toppingPrice;
}

istream& operator >> (istream& ins, Toppings& topping) {
    ins >> topping._toppingName;
    ins >> topping._toppingPrice;
    return ins;
}

ostream& operator << (ostream& outs, const Toppings& topping)
{
    outs << topping._toppingName << ", ";
    outs << topping._toppingPrice << " kr." << endl;
    return outs;
}
