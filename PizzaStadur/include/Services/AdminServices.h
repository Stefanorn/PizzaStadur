#ifndef ADMINSERVICES_H
#define ADMINSERVICES_H

#include "Pizza.h"
#include "DeliveryPlaces.h"
#include "Toppings.h"
#include "Products.h"

#include "pizzaRepo.h"
#include "PlacesRepo.h"
#include "ToppingMenuRepo.h"
#include "ProductRepo.h"


class AdminServices
{
    public:
        AdminServices();
        void registerBaseSize();
        void registerToppings( ToppingsMenuItem item );
        void registerPizza();
        void registerProduct(int size);
        void editPrices();
        void registerPlaces( DeliveryPlaces deliveryPlace);

    private:
        ToppingMenuRepo _toppingsMenuRepo;
        PlacesRepo _placesrepo;
        ProductRepo _productrepo;
};

#endif // ADMINSERVICES_H
