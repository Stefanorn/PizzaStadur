#ifndef PLACESREPO_H
#define PLACESREPO_H

#include "DeliveryPlaces.h"

class PlacesRepo
{
    public:
        PlacesRepo();
        void addPlaces(DeliveryPlaces place);
        void overWriteFile(vector<DeliveryPlaces> places);
        vector<DeliveryPlaces> ReturnAllPlaces();

    private:
        void _readFile();
        vector<DeliveryPlaces> _places;
};

#endif // PLACESREPO_H
