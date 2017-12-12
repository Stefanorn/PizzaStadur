#ifndef BAKERSERVICES_H
#define BAKERSERVICES_H

#include <iostream>
#include <vector>
#include <time.h>
#include "pizzaRepo.h"
#include "PizzaExeptions.h"
#include "PlacesRepo.h"
#include "orderRepo.h"

using namespace std;

class BakerServices
{
    public:
        BakerServices();
        void bakePizza(int pizzaId);
        void clockMessages();

        DeliveryPlaces GetDeleveryPlace(char input);
        vector<DeliveryPlaces> GetAllPlaces();
        vector<Pizza> ReturnUnbakedPizzas();

    private:

        DeliveryPlaces _deliveryPlace;
        orderRepo OrderRepo;
        PlacesRepo plcRepo;
        pizzaRepo pzRepo;
        vector<int> _temp_vector;

};

#endif // BAKERSERVICES_H
