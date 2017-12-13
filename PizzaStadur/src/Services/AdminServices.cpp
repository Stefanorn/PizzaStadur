#include "AdminServices.h"

AdminServices::AdminServices()
{
    //ctor
}

void AdminServices::registerToppings( ToppingsMenuItem item)
{
    _toppingsMenuRepo.addTopping(item);
}

void AdminServices::registerPizza(PizzaMenu pizza,
                                   vector<Toppings> tp)
{
    for(unsigned int i = 0; i< tp.size(); i++){
        pizza.addTopping(tp[i]);
    }
    cout << pizza;

}

Toppings AdminServices::CharToTopping(char input){
    vector<ToppingsMenuItem> toppingsMenu = _toppingsMenuRepo.returnToppings();
    for(unsigned int i = 0; i < toppingsMenu.size();  i++){
        if(toppingsMenu[i].getHotkey() == input){
            return toppingsMenu[i].createTopping();
        }
    }
    throw invalidToppingHotkey();
}
void AdminServices::registerProduct(Products product)
{
    _productrepo.addProduct(product);
}

void AdminServices::readProduct()
{
    _productrepo.readFile();
}

void AdminServices::editMenuPrices(double price)
{

}

void AdminServices::editBasePrices(double price)
{

}

void AdminServices::editSizePrices(double price)
{

}

void AdminServices::editToppingPrices(double price)
{

}

void AdminServices::registerPlaces( DeliveryPlaces place )
{
    _placesrepo.addPlaces(place);
}

vector<ToppingsMenuItem> AdminServices::returnToppingsMenu(){
    return _toppingsMenuRepo.returnToppings();
}
