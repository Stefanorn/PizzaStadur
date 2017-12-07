#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <string>
#include <iostream>
#include "ToppingsRepo.h"

using namespace std;

class Toppings
{
    public:
        Toppings(string name, string type, int price);
        string getToppingName();
        string getToppingType();
        int getToppingPrice();
        friend istream& operator >> (istream& ins, Toppings& topping);
        friend ostream& operator << (ostream& outs, const Toppings& topping);
    private:
        string _toppingName;
        string _toppingType;
        int _toppingPrice;
};

#endif // TOPPINGS_H

