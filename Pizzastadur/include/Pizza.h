#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
using namespace std;


class Pizza
{
    public:
        Pizza();

    protected:

    private:
        char _name[30];
        char _alegg[100];  // Breyta � klassa

        char _Botn[30];    //Breyta �essu i enum e�a eitthva
        char _Staerd[10];  //Breyta �essu i enum e�a eitthvad
        int verd;         //
};

#endif // PIZZA_H
