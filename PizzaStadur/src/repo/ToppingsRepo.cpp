#include "ToppingsRepo.h"

ToppingsRepo::ToppingsRepo()
{
    //ctor
}

void ToppingsRepo::addTopping(Toppings topping)
{
    ofstream fout;
    fout.open("toppings.bin", ios::app);
    if (fout.is_open())
    {
        fout << topping;
        fout.close();
    }
    else
    {

    }
}

