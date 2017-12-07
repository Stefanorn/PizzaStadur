#ifndef SALESSERVICES_H
#define SALESSERVICES_H
#include "orderRepo.h"
#include "OrderExeptions.h"


class SalesServices
{
    public:
        SalesServices();
        Pontun returnAOrder( int orderNo );
        void CommitOrder(Pontun order);
        int OrderNumber();
    protected:

    private:
        orderRepo repo;
};

#endif // SALESSERVICES_H
