#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
using namespace std;


class Pizza
{
    public:
        Pizza();

        friend istream& operator >> (istream& ins, Pizza& pizza);
        friend ostream& operator << (ostream& outs, const Pizza& pizza);

    private:
        char _name[30];
        char _topping[100];  // Breyta � klassa
        char _base[30];    //Breyta �essu i enum e�a eitthva
        char _size[30];  //Breyta �essu i enum e�a eitthvad
        int _price;         //
};

#endif // PIZZA_H
