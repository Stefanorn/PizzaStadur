#ifndef SALESSERVICES_H
#define SALESSERVICES_H
#include "orderRepo.h"
#include "pizzaRepo.h"
#include "OrderExeptions.h"


class SalesServices
{
    public:
        SalesServices();
        Pontun returnAOrder( int orderNo );
        void CommitOrder(Pontun order);
        void CommitPizza( Pizza pizza );
        int OrderNumber();
    protected:

    private:
        orderRepo repo;
        pizzaRepo pzRepo;
};

#endif // SALESSERVICES_H
