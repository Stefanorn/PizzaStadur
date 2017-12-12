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



class AdminServices
{
    public:
        AdminServices();
        void registerToppings( ToppingsMenuItem item );
        void registerPizza(PizzaMenu,vector<Toppings>);
        void registerProduct(int size);
        void editPrices();
        void registerPlaces( DeliveryPlaces deliveryPlace);
        Toppings CharToTopping(char input);
        vector<ToppingsMenuItem> returnToppingsMenu();

    private:
        ToppingMenuRepo _toppingsMenuRepo;
        PlacesRepo _placesrepo;
        ProductRepo _productrepo;
};

#endif // ADMINSERVICES_H
