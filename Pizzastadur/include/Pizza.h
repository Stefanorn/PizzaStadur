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
        char _alegg[100];  // Breyta í klassa

        char _Botn[30];    //Breyta þessu i enum eða eitthva
        char _Staerd[10];  //Breyta þessu i enum eða eitthvad
        int verd;         //
};

#endif // PIZZA_H
