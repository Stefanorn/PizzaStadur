#ifndef SALESSERVICES_H
#define SALESSERVICES_H
#include "orderRepo.h"
#include "pizzaRepo.h"
#include "ToppingMenuRepo.h"
#include "PizzaExeptions.h"
#include "PlacesRepo.h"
#include "pizzaRepo.h"
#include "PizzaMenuRepo.h"
#include "ProductRepo.h"
#include "productOnFile.h"
#include "ProductOnFileRepo.h"

class SalesServices
{
    public:
        SalesServices();

        void DeliveredOrPickedUp(Pontun order, char input) const;
        Toppings CharToTopping(char input);
        Pontun returnAOrder( int orderNo );

        Pontun computeTotalPrice( Pontun order);
        void commitProduct(productOnFile prod);
        void CommitOrder(Pontun order);
        void CommitPizza( Pizza pizza );
        int OrderNumber();
        vector<Pizza> GetPizzaByOrderID(int orderNumber);
        vector<Toppings> getToppingsByPizzaID(int pizzaOrderNumber);
        vector<productOnFile> getProductByID(int id);

        vector <PizzaMenu> ReturnPizzaMenu();
        vector<Products> ReturnAllProducts();
        vector<DeliveryPlaces> GetAllPlaces();
        DeliveryPlaces GetDeliveryPlace(char index);

        vector<ToppingsMenuItem> GetToppingsMenu();
        void addToppingToPizza( char index );

        Pizza selectPizzaFromMenu( char input );
        productOnFile selectProduct(char input);
        //void AssignOrderToPlace();

    private:
        DeliveryPlaces _deliveryPlace;
        PlacesRepo plcRepo;
        ToppingMenuRepo topMenuRepo;
        orderRepo ordRepo;
        pizzaRepo pzRepo;
        PizzaMenuRepo pizzaMenuRepo;
        ProductRepo prodRepo;
        ProductOnFileRepo producFileRepo;
};

#endif // SALESSERVICES_H
