#include "AdminServices.h"

AdminServices::AdminServices()
{
    //ctor
}

void AdminServices::registerPizza()
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

void AdminServices::registerToppings()
{
    Toppings topping;
    cin >> topping;
    ToppingsRepo toppingrepo;
    toppingrepo.addTopping(topping);
    vector<Toppings> tp = toppingrepo.returnToppings();
    for(unsigned int i = 0; i < tp.size(); i++){
        cout << tp[i];
    }
}

void AdminServices::registerOffer()
{

}

void AdminServices::registerProduct()
{

}

void AdminServices::editPrices()
{

}

void AdminServices::registerPlaces()
{
    /*int size;
    cin >> size;
    DeliveryPlaces places[size];
    for(int i = 0; i < size; i++){
        cin >> places[i];
    }
    PlacesRepo repo;
    repo.addPlaces(places, size);*/
}
