#ifndef BAKERSERVICES_H
#define BAKERSERVICES_H

#include <iostream>
#include <vector>
#include "orderRepo.h"

using namespace std;

class BakerServices
{
    public:
        BakerServices();
        void bakePizza();
        bool hasBeenBaked();
        void bakeSomePizza();

    private:
        bool _hasBeenBaked;
        vector<int> _temp_vector;
};

#endif // BAKERSERVICES_H
