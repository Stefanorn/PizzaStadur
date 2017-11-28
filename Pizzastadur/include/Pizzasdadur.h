#ifndef PIZZASDADUR_H
#define PIZZASDADUR_H

#include "Pizza.h"
#include "Pontun.h"
class Pizzasdadur
{
    public:
        Pizzasdadur();
        ~Pizzasdadur();
        void createOrder();

    private:
        void ReadFromFile();

        Pontun* _pantanir = new Pontun[0];
        int _numOfOrders;

};

#endif // PIZZASDADUR_H
