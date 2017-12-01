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
        void bakePizza();

    private:
        void ReadFromFile();
        bool UpdateOrder();
        void WriteOrderToFile( Pontun orderToWrite );
        int inputCheck(int input , int* inputList);

        Pontun* _pantanir = new Pontun[100]; //�arf a� iplimenta k��a sem h�ndlar a� st�kka arrayi� ef �g f� fleirri enn 100 pantanir
        int _numOfOrders;

};

#endif // PIZZASDADUR_H
