#ifndef STAFFSERVICES_H
#define STAFFSERVICES_H
#include "orderRepo.h"
#include "PlacesRepo.h"

class staffServices
{
    public:
        staffServices();
        void registerOrder( int orderID );

        vector<Pontun> ReturnUnPaidOrders();
        vector<Pontun> ReturnUnDeliveredOrder();
        vector<DeliveryPlaces> GetAllPlaces();

        DeliveryPlaces GetDeliveryPlace(char input);

        bool PayForOrder(int orderNo);
        bool DeliverOrder(int orderNo);
    protected:

    private:
        DeliveryPlaces _deliveryPlace;

        PlacesRepo placeRepo;
        orderRepo repo;
};

#endif // STAFFSERVICES_H
