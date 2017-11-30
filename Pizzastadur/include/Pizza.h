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
        string _name;
        char _topping[100];  // Breyta � klassa
        string _base;    //Breyta �essu i enum e�a eitthva
        string _size;  //Breyta �essu i enum e�a eitthvad
        int _price;         //
};

#endif // PIZZA_H
