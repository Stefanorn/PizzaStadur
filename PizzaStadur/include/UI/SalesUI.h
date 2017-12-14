#ifndef SALESUI_H
#define SALESUI_H
#include <stdlib.h>
#include "SalesServices.h"

class SalesUI {
    public:
        SalesUI();

    private:
        DeliveryPlaces _selectedDeliveryPlace;
        SalesServices service;
        void createOrder();
        void GetInfoAboutOrder();
        void selectDeliveryPlace();
        void PrintOrder(Pontun order);
};

#endif // SALESUI_H
