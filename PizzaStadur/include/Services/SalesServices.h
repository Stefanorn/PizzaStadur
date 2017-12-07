#ifndef SALESSERVICES_H
#define SALESSERVICES_H
#include "orderRepo.h"


class SalesServices
{
    public:
        SalesServices();
        void CommitOrder(Pontun order);
        int OrderNumber();
    protected:

    private:
        orderRepo repo;
};

#endif // SALESSERVICES_H
