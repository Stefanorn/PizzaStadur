#ifndef STAFFUI_H
#define STAFFUI_H
#include <stdlib.h>
#include "staffServices.h"

class StaffUI
{
    public:
        StaffUI();
    protected:

    private:
        void PayForOrder();
        void DeliverOrder();

        DeliveryPlaces _selectedDeliveryPlace;
        void selectDeliveryPlace();
        staffServices service;
};

#endif // STAFFUI_H
