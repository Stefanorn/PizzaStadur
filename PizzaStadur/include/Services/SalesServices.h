#ifndef SALESSERVICES_H
#define SALESSERVICES_H
#include "orderRepo.h"
#include "pizzaRepo.h"
#include "ToppingMenuRepo.h"
#include "ToppingsRepo.h"
#include "PizzaExeptions.h"
#include "PlacesRepo.h"
#include "pizzaRepo.h"
#include "PizzaMenuRepo.h"


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
        vector <PizzaMenu> ReturnPizzaMenu();

        vector<DeliveryPlaces> GetAllPlaces();
        DeliveryPlaces GetDeleveryPlace(char index);

        vector<ToppingsMenuItem> GetToppingsMenu();
        void addToppingToPizza( char index );
        //void AssignOrderToPlace();

    private:

        DeliveryPlaces _deliveryPlace;
        PlacesRepo plcRepo;
        ToppingMenuRepo topMenuRepo;
        ToppingsRepo topRepo;
        orderRepo ordRepo;
        pizzaRepo pzRepo;
        PizzaMenuRepo pizzaMenuRepo;
};

#endif // SALESSERVICES_H
