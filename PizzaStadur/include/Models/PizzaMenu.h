#ifndef PIZZAMENU_H
#define PIZZAMENU_H
#include "ToppingsMenuItem.h"
#include "PizzaExeptions.h"
#include "Enums.h"
#include <iostream>

class PizzaMenu
{
    public:
        PizzaMenu();
        friend istream& operator >> (istream& ins, PizzaMenu& pizza);
        friend ostream& operator << (ostream& outs, const PizzaMenu& pizza);

        string getName();
        char getKey();
        pizzaBase getBase();
        pizzaSize getSize();

    private:
        char _name[32];
        char _hotkey;

        ToppingsMenuItem _topping[10];
        double _price;

        pizzaBase _base;
        pizzaSize _size;

};

#endif // PIZZAMENU_H
