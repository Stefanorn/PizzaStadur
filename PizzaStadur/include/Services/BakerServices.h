#ifndef BAKERSERVICES_H
#define BAKERSERVICES_H

#include <iostream>
#include <vector>
#include <time.h>
#include "pizzaRepo.h"

using namespace std;

class BakerServices
{
    public:
        BakerServices();
        void bakePizza();
        bool hasBeenBaked();
        void bakeSomePizza();
        void clockMessages();

        vector<Pizza> ReturnUnbakedPizzas();

    private:
        bool _hasBeenBaked;

        pizzaRepo pzRepo;
        vector<int> _temp_vector;

};

#endif // BAKERSERVICES_H
