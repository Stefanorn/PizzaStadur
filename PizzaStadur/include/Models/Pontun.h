#ifndef PONTUN_H
#define PONTUN_H

#include "ToppingsMenuItem.h"
#include "Pizza.h"
#include "Toppings.h"
#include "DeliveryPlaces.h"
#include <iostream>

using namespace std;
class Pontun
{
    public:
        Pontun(int number, DeliveryPlaces place);
        Pontun();
        friend ostream& operator << (ostream& out, const Pontun& pontun);
        friend istream& operator >> (istream& in, Pontun& order);
        bool IsOrderPaid();
        bool isOrderReady();
        bool IsOrderDelivered();
        void payOrder();
        void makeOrderReady();
        void deliverOrder();
        void ComputeTotalPrice(double price);
        int GetOrderNo() const;

        DeliveryPlaces getDeliveryPlace();

    private:
        DeliveryPlaces _place;
        double _price;
        bool _hasBeenPaid;
        bool _isReady;
        bool _hasBeenDelivered;
        int _orderNumber;
};

#endif // PONTUN_H
