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
<<<<<<< HEAD
        bool UpdateOrder(int orderNo);
        void WriteOrderToFile(Pontun orderToWrite);
=======
        bool UpdateOrder(int orderNo, Pontun newOrder );
        void WriteOrderToFile( Pontun orderToWrite );
>>>>>>> add88bb020ef129f9ac3a50b38e64a5647f3bdb6

        Pontun* _pantanir = new Pontun[100]; //Þarf að iplimenta kóða sem höndlar að stækka arrayið ef ég fæ fleirri enn 100 pantanir
        int _numOfOrders;

};

#endif // PIZZASDADUR_H
