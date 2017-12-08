#ifndef TOPPINGSREPO_H
#define TOPPINGSREPO_H
#include "Toppings.h"
#include <fstream>
#include <vector>
#include <iostream>

class ToppingsRepo
{
    public:
        ToppingsRepo();
        void overwriteFile(vector<Toppings> topping);
        void addTopping(vector<Toppings> topping);
        vector<Toppings> returnToppings();

    private:
        vector<Toppings> _topp;
        void readFile();
};

#endif // TOPPINGSREPO_H

