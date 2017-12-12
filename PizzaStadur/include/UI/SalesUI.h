#ifndef SALESUI_H
#define SALESUI_H
#include <stdlib.h>
#include "SalesServices.h"

class SalesUI {
    public:
        SalesUI();

    protected:

    private:

        DeliveryPlaces _selectedDeliveryPlace;
        SalesServices service;
        void createOrder();
        void GetInfoAboutOrder();
        void selectDeliveryPlace();
};

#endif // SALESUI_H
