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
        char GetKey();
        friend istream& operator >> (istream& in, DeliveryPlaces& places);
        friend ostream& operator << (ostream& out, const DeliveryPlaces& places);

    private:
        char _name[32];
        char _hotkey;
};

#endif // DELIVERYPLACES_H
