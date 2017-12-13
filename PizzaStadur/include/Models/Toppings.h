#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Toppings
{
    public:
        Toppings();
        Toppings( string toppingName, double toppingPrice , int pizzaToToppingId);
        string getToppingName();
        int getToppingID();
        double getToppingPrice() const;
        friend istream& operator >> (istream& ins, Toppings& topping);
        friend ostream& operator << (ostream& outs, const Toppings& topping);
    private:
        char _toppingName[32];
        int _toppingID;
        double _toppingPrice;
};

#endif // TOPPINGS_H

