#include "AdminServices.h"

AdminServices::AdminServices()
{
    //ctor
}

void AdminServices::registerBaseSize()
{
    Pizza pizza;
    cin >> pizza;
    pizzaRepo repo;
    repo.WriteOrderToFile(pizza);
    vector<Pizza> pz = repo.ReturnAllPizzas();
    for(unsigned int i = 0; i < pz.size(); i++){
        cout << pz[i];
    }
}

void AdminServices::registerToppings( vector<ToppingsMenuItem> items, int size)
{
    _toppingsMenuRepo.addTopping(items, size);
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

void AdminServices::registerPlaces(int size)
{
    vector<DeliveryPlaces> places;
    _placesrepo.addPlaces(places, size);
}
