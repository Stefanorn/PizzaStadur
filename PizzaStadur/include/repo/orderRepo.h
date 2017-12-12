#ifndef ORDERREPO_H
#define ORDERREPO_H
#include <vector>
#include "Pontun.h"
#include <iostream>
#include <fstream>
#include "PizzaExeptions.h"


using namespace std;

class orderRepo
{
    public:
        orderRepo();
        void WriteOrderToFile( Pontun orderToWrite );
        void RewriteFile(  vector<Pontun> orders );

        vector<Pontun> ReturnOrders(    bool hasBeenPayedFor,
                                        bool hasBeenDelivired,
                                        bool isReddy );

        vector<Pontun> ReturnAllOrders();

        int getOrderNo();
    private:
        int _orderNo;
        void ReadFromFile();
        vector<Pontun> _orders;
};

#endif // ORDERREPO_H
