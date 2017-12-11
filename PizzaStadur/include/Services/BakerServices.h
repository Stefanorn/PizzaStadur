#ifndef BAKERSERVICES_H
#define BAKERSERVICES_H

#include <iostream>
#include <vector>
#include <time.h>
#include "pizzaRepo.h"
#include "PizzaExeptions.h"

using namespace std;

class BakerServices
{
    public:
        BakerServices();
        void bakePizza(int pizzaId);
        void clockMessages();

        vector<Pizza> ReturnUnbakedPizzas();

    private:

        pizzaRepo pzRepo;
        vector<int> _temp_vector;

};

#endif // BAKERSERVICES_H
