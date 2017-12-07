#ifndef ORDERREPO_H
#define ORDERREPO_H
#include <vector>
#include "Pontun.h"
#include <iostream>
#include <fstream>


using namespace std;

class orderRepo
{
    public:
        orderRepo( int number);
        void WriteOrderToFile( Pontun orderToWrite );
        void AddOrders(  vector<Pontun> orders );
        void PayForOrder(int orderNo);

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
