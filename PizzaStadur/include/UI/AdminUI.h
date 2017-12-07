#ifndef ADMINUI_H
#define ADMINUI_H

#include <iostream>
#include <vector>
#include "Pizza.h"

using namespace std;

class AdminUI
{
    public:
        AdminUI();
        void mainMenu();
        void registerPizza();
        void registerToppings();
        void registerOffer();
        void registerProduct();
        void editPrices();
        void registerPlaces();

    private:
        vector<Pizza> pizzaList;
};

#endif // ADMINUI_H
