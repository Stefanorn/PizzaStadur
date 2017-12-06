#ifndef STAFFSERVICES_H
#define STAFFSERVICES_H
#include "orderRepo.h"

class staffServices
{
    public:
        staffServices();
        void registerOrder( int orderID );
        void deliverOrder( int orderID );
        vector<Pontun> ReturnUnPayedOrders();
        bool PayForOrder(int orderNo);
    protected:

    private:
        orderRepo repo;
};

#endif // STAFFSERVICES_H
