#ifndef SALESSERVICES_H
#define SALESSERVICES_H
#include "orderRepo.h"
#include "pizzaRepo.h"
#include "ToppingMenuRepo.h"
#include "ToppingsRepo.h"
#include "OrderExeptions.h"


class SalesServices
{
    public:
        SalesServices();
        Pontun returnAOrder( int orderNo );
        void CommitOrder(Pontun order);
        void CommitPizza( Pizza pizza );
        int OrderNumber();
        vector<Pizza> GetPizzaByOrderID(int orderNumber);
        vector<Toppings> getToppingsByPizzaID(int pizzaOrderNumber);


        vector<ToppingsMenuItem> GetToppingsMenu();
        void addToppingToPizza( char index );
        //void AssignOrderToPlace();

    private:

        ToppingMenuRepo topMenuRepo;
        ToppingsRepo topRepo;
        orderRepo ordRepo;
        pizzaRepo pzRepo;
};

#endif // SALESSERVICES_H
