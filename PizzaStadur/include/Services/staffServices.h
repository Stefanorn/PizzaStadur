#ifndef STAFFSERVICES_H
#define STAFFSERVICES_H
#include "orderRepo.h"

class staffServices
{
    public:
        staffServices();
        void registerOrder( int orderID );

        vector<Pontun> ReturnUnPayedOrders();
        vector<Pontun> ReturnUnDeliverdOrder();

        bool PayForOrder(int orderNo);
        bool DeliverOrder(int orderNo);
    protected:

    private:
        orderRepo repo;
};

#endif // STAFFSERVICES_H
