#ifndef ADMINSERVICES_H
#define ADMINSERVICES_H

#include "Pizza.h"
#include "DeliveryPlaces.h"
#include "Toppings.h"

#include "pizzaRepo.h"
#include "PlacesRepo.h"
#include "ToppingsRepo.h"

class AdminServices
{
    public:
        AdminServices();
        void registerPizza();
        void registerToppings(int size);
        void registerOffer();
        void registerProduct();
        void editPrices();
        void registerPlaces(int size);

    private:
};

#endif // ADMINSERVICES_H
