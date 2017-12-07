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

    private:
        char _name[30];
        int _price;
        string _base;
        int _size;
};

#endif // PIZZA_H
