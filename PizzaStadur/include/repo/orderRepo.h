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
        orderRepo();
        void WriteOrderToFile( Pontun orderToWrite );
        void UpdateOrder(  vector<Pontun> orders );

        vector<Pontun> ReturnOrders(    bool hasBeenPayedFor,
                                        bool hasBeenDelivired,
                                        bool isReddy );

    protected:

    private:
        void ReadFromFile();
        vector<Pontun> _orders;
};

#endif // ORDERREPO_H
