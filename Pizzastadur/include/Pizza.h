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
        char _topping[100];  // Breyta í klassa
        string _base;    //Breyta þessu i enum eða eitthva
        string _size;  //Breyta þessu i enum eða eitthvad
        int _price;         //
};

#endif // PIZZA_H
