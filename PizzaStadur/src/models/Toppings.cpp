#include "Toppings.h"

Toppings::Toppings()
{
    _toppingName[0] = '\0';
    _toppingPrice = 200;
}

string Toppings::getToppingName()
{
    return _toppingName;
}

int Toppings::getToppingID()
{
    return _toppingID;
}

double Toppings::getToppingPrice()
{
    return _toppingPrice;
}

istream& operator >> (istream& ins, Toppings& topping) {
    ins >> topping._toppingName;
    //ins >> topping._toppingType;
    ins >> topping._toppingPrice;
    return ins;
}

ostream& operator << (ostream& outs, const Toppings& topping)
{
    outs << topping._toppingName << ", ";
    //outs << topping._toppingType << ", ";
    outs << topping._toppingPrice << " kr." << endl;
    return outs;
}

