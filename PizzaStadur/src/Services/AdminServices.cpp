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
        tp[i].setToppingPrice(0);
        pizza.addTopping(tp[i]);
    }
    cout << pizza;
    _pizzaMenuRepo.WriteToFile(pizza);

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
    _productMenuRepo.addProduct(product);
}

void AdminServices::readProduct()
{
    _productMenuRepo.readFile();
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
