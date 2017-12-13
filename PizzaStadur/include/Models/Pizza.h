#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include "Enums.h"
#include "PizzaExeptions.h"
#include "DeliveryPlaces.h"
#include "Toppings.h"

using namespace std;


class Pizza
{
    public:
        Pizza();
        friend istream& operator >> (istream& ins, Pizza& pizza);
        friend ostream& operator << (ostream& outs, const Pizza& pizza);
        void tagPizzaToOrder(int orderNo);
        int getPizzaToOrderId();
        void setPizzaID(int id);
        int getPizzaID();
        double getPrice() const;
        void bakePizza();
        bool isPizzaBaked();
        void setBasePrice(double price);
        void setSizePrice(double price);

        void addToppings(Toppings topping);

        DeliveryPlaces _place;
        /// TODO: Gera þetta að private breytu og búa til get fall.

    private:
        Toppings _toppingsOnPizza[16];
        int _toppingIndex;
        int _orderIdNumber;
        int _pizzaID;
        bool _isPizzaBaked;
        pizzaBase _base;
        pizzaSize _size;
        double _basePrice;
        double _sizePrice;
};

#endif // PIZZA_H
