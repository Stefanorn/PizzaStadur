#ifndef DELIVERYPLACES_H
#define DELIVERYPLACES_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class DeliveryPlaces
{
    public:
        DeliveryPlaces();
        string getName() const;
        char GetKey() const;
        friend istream& operator >> (istream& in, DeliveryPlaces& places);
        friend ostream& operator << (ostream& out, const DeliveryPlaces& places);
        friend bool operator == ( const DeliveryPlaces& leftSide, const DeliveryPlaces& rightSide );

    private:
        char _name[32];
        char _hotkey;
};

#endif // DELIVERYPLACES_H
