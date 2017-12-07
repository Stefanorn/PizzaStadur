#ifndef PIZZASDADUR_H
#define PIZZASDADUR_H

#include "Pizza.h"
#include "Pontun.h"
#include "BakerServices.h"
#include <vector>

class Pizzasdadur
{
    public:
        Pizzasdadur();
        void createOrder();
        void printAllOrders();
        void payForOrder();
        void bakePizza();
        void addItemToDataBase();

    private:
        void ReadFromFile();
        void WriteOrderToFile( Pontun orderToWrite );
        int inputCheck(int input , int* inputList);
        int _numOfOrders;
        bool UpdateOrder();
        vector<Pontun> _pantanir;

};

#endif // PIZZASDADUR_H
