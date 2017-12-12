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
void AdminServices::registerProduct(int size)
{
   // vector<> toppings;
   // _toppingrepo.addTopping(toppings, size);
}

void AdminServices::editPrices()
{

}

void AdminServices::registerPlaces( DeliveryPlaces place )
{
    _placesrepo.addPlaces(place);
}

vector<ToppingsMenuItem> AdminServices::returnToppingsMenu(){
    return _toppingsMenuRepo.returnToppings();
}
