#ifndef TOPPINGMENUREPO_H
#define TOPPINGMENUREPO_H
#include "ToppingsMenuItem.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class ToppingMenuRepo
{
    public:
        ToppingMenuRepo();
        void overwriteFile(vector<ToppingsMenuItem> topping);
        void addTopping( ToppingsMenuItem item);
        vector<ToppingsMenuItem> returnToppings();

    private:
        vector<ToppingsMenuItem> _menItem;
        void readFile();
};
#endif // TOPPINGMENUREPO_H
