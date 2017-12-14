#ifndef BAKERUI_H
#define BAKERUI_H

#include <stdlib.h>
#include <iostream>
#include "BakerServices.h"

using namespace std;

class BakerUI
{
    public:
        BakerUI();
        void mainMenu();

    private:
        DeliveryPlaces _deliveryPlace;
        DeliveryPlaces _selectedDeliveryPlace;
        BakerServices bakerService;
        void selectDeliveryPlace();
};

#endif // BAKERUI_H
