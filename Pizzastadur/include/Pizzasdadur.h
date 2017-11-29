#ifndef PIZZASDADUR_H
#define PIZZASDADUR_H

#include "Pizza.h"
#include "Pontun.h"
#include <vector>

class Pizzasdadur
{
    public:
        Pizzasdadur();
        ~Pizzasdadur();
        void createOrder();
        void printAllOrders();
        void payForOrder();

    private:
        void ReadFromFile();


        Pontun* _pantanir = new Pontun[100]; //Þarf að iplimenta kóða sem höndlar að stækka arrayið ef ég fæ fleirri enn 100 pantanir
        int _numOfOrders;

};

#endif // PIZZASDADUR_H
