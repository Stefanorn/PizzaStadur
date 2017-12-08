#include "Toppings.h"

Toppings::Toppings()
{
    _toppingName[0] = '\0';
    _toppingPrice = 0;
}

string Toppings::getToppingName()
{
    return _toppingName;
}

/*string Toppings::getToppingType()
{
    return _toppingType;
}*/

int Toppings::getToppingPrice()
{
    return _toppingPrice;
}

istream& operator >> (istream& ins, Toppings& topping)
{
    if (ins == cin){
        cout << "Please enter what topping you would like to add, followed by its price:" << endl;
    }
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

