#ifndef SALESSERVICES_H
#define SALESSERVICES_H
#include "orderRepo.h"
#include "pizzaRepo.h"
#include "OrderExeptions.h"
#include "Toppings.h"


class SalesServices
{
    public:
        SalesServices();
        Pontun returnAOrder( int orderNo );
        void CommitOrder(Pontun order);
        void CommitPizza( Pizza pizza );
        int OrderNumber();
        vector<Pizza> GetPizzaByOrderID(int orderNumber);

        vector<Toppings> GetToppingsMenu();
        void addToppingToPizza();
        //void AssignOrderToPlace();

    private:
        orderRepo repo;
        pizzaRepo pzRepo;
};

#endif // SALESSERVICES_H
