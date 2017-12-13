#ifndef PIZZAMENU_H
#define PIZZAMENU_H
#include "Toppings.h"
#include "PizzaExeptions.h"
#include "Enums.h"
#include <iostream>
#include "PizzaExeptions.h"

class PizzaMenu
{
    public:
        PizzaMenu();
        friend istream& operator >> (istream& ins, PizzaMenu& pizza);
        friend ostream& operator << (ostream& outs, const PizzaMenu& pizza);
        void addTopping( Toppings );
        string getName();
        char getKey();
        pizzaBase getBase();
        pizzaSize getSize();

    private:
        char _name[32];
        char _hotkey;
        Toppings _toppings[16];
        int _toppingIndex;
        double _price;
        pizzaBase _base;
        pizzaSize _size;

};

#endif // PIZZAMENU_H
