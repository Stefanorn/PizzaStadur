#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <string>
#include <iostream>

using namespace std;

class Toppings
{
    public:
        Toppings();
        string getToppingName();
        int getToppingID();
        double getToppingPrice();
        friend istream& operator >> (istream& ins, Toppings& topping);
        friend ostream& operator << (ostream& outs, const Toppings& topping);
    private:
        char _toppingName[32];
        int _toppingID;
        double _toppingPrice;
};

#endif // TOPPINGS_H

