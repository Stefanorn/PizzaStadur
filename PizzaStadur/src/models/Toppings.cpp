#include "Toppings.h"

Toppings::Toppings(string name, string type, int price)
{
    _toppingName = name;
    _toppingType = type;
    _toppingPrice = price;
}

string Toppings::getToppingName()
{
    return _toppingName;
}

string Toppings::getToppingType()
{
    return _toppingType;
}

int Toppings::getToppingPrice()
{
    return _toppingPrice;
}

istream& operator >> (istream& ins, Toppings& topping)
{
    ins >> topping._toppingName;
    ins >> topping._toppingType;
    ins >> topping._toppingPrice;
    return ins;
}

ostream& operator << (ostream& outs, const Toppings& topping)
{
    outs << topping._toppingName << ", ";
    outs << topping._toppingType << ", ";
    outs << topping._toppingPrice << endl;
    return outs;
}

