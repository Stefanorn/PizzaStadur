#ifndef DELIVERYPLACES_H
#define DELIVERYPLACES_H

#include <iostream>
#include <vector>
#include "Pontun.h"
#include "orderRepo.h"

using namespace std;

class DeliveryPlaces
{
    public:
        DeliveryPlaces();
        string getName();
        friend istream& operator >> (istream& in, DeliveryPlaces& places);
        friend ostream& operator << (ostream& out, const DeliveryPlaces& places);

    private:
        vector<Pontun> orders;
        char _name[32];
};

#endif // DELIVERYPLACES_H
