#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include "Enums.h"
#include "PizzaExeptions.h"

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

        double getPrice() const;

        void bakePizza();
        bool isPizzaBaked();

    private:
        int _orderIdNumber;
        int _pizzaID;
        bool _isPizzaBaked;
        char _name[32];
        pizzaBase _base;
        pizzaSize _size;
};

#endif // PIZZA_H
