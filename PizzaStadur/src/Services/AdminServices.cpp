#include "AdminServices.h"

AdminServices::AdminServices()
{
    //ctor
}

void AdminServices::registerToppings( ToppingsMenuItem item)
{
    _toppingsMenuRepo.addTopping(item);
}

void AdminServices::registerPizza()
{

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
