#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include "Enums.h"
using namespace std;


class Pizza
{
    public:
        Pizza();

        friend istream& operator >> (istream& ins, Pizza& pizza);
        friend ostream& operator << (ostream& outs, const Pizza& pizza);

        void tagPizzaToOrder(int orderNo);
        int getPizzaToOrderId();

        void setPizzaID(int id);
        int getPizzaID();

        double getPize();

    private:
        int _orderIdNumber;

        int _pizzaID;

        char _name[32];
        double _price;
        char _base[16];
        char _size[4];
};

#endif // PIZZA_H
