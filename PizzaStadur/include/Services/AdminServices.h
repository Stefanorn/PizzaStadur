#ifndef ADMINSERVICES_H
#define ADMINSERVICES_H

#include "Pizza.h"
#include "DeliveryPlaces.h"
#include "Toppings.h"
#include "Products.h"
#include "PizzaMenu.h"

#include "pizzaRepo.h"
#include "PlacesRepo.h"
#include "ToppingMenuRepo.h"
#include "ProductRepo.h"
#include "PizzaMenuRepo.h"
#include "ProductOnFileRepo.h"



class AdminServices
{
    public:
        AdminServices();
        void registerToppings( ToppingsMenuItem item );
        void registerPizza(PizzaMenu,vector<Toppings>);
        void registerProduct(Products product);
        void readProduct();
        void editMenuPrices(double price);
        void editBasePrices(double price);
        void editSizePrices(double price);
        void editToppingPrices(double price);
        void registerPlaces( DeliveryPlaces deliveryPlace);
        Toppings CharToTopping(char input);
        vector<ToppingsMenuItem> returnToppingsMenu();

    private:

        ProductOnFileRepo _productsRepo;
        PizzaMenuRepo _pizzaMenuRepo;
        ToppingMenuRepo _toppingsMenuRepo;
        PlacesRepo _placesrepo;
        ProductRepo _productMenuRepo;
};

#endif // ADMINSERVICES_H
