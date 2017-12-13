#include "SalesServices.h"

SalesServices::SalesServices(){
    //ctor
}

Toppings SalesServices::CharToTopping(char input){
    vector<ToppingsMenuItem> toppingsMenu = topMenuRepo.returnToppings();
    for(unsigned int i = 0; i < toppingsMenu.size();  i++){
        if(toppingsMenu[i].getHotkey() == input){
            return toppingsMenu[i].createTopping();
        }
    }
    throw invalidToppingHotkey();
}

void SalesServices::CommitOrder(Pontun order){
    vector<Pizza> allPizza = pzRepo.ReturnAllPizzas();
    for(unsigned int i = 0; i < allPizza.size(); i++){
        if( order.GetOrderNo() == allPizza[i].getPizzaToOrderId()){
            order.ComputeTotalPrice( allPizza[i].getPrice() );
            }
        }

   ordRepo.WriteOrderToFile( order );
}


void SalesServices::CommitPizza(Pizza pizza){
    pizza.setPizzaID( pzRepo.MakePizzaID() );
    pizza._place = _deliveryPlace;

    pzRepo.WriteOrderToFile(pizza);
}
int SalesServices::OrderNumber(){
    return ordRepo.getOrderNo();
}
Pontun SalesServices::returnAOrder( int orderNo ){
    vector<Pontun> allOrders = ordRepo.ReturnAllOrders();
    for(unsigned int i = 0; i < allOrders.size(); i++ ){
         cout << allOrders[i];
        if(allOrders[i].GetOrderNo() == orderNo){
            return allOrders[i];
        }
    }
    throw NoOrderToReturnExeption();
}

vector<Pizza> SalesServices::GetPizzaByOrderID(int orderNumber){
    vector<Pizza> pz = pzRepo.ReturnAllPizzas();
    vector<Pizza> allPizzas;
    for (unsigned int i = 0; i < pz.size(); i++){
        if (orderNumber == pz[i].getPizzaToOrderId()){
            allPizzas.push_back(pz[i]);
        }
    }
    return allPizzas;
    //throw SomeException;
}

vector<ToppingsMenuItem> SalesServices::GetToppingsMenu(){
    return topMenuRepo.returnToppings();
}


vector<DeliveryPlaces> SalesServices::GetAllPlaces(){
    return plcRepo.ReturnAllPlaces();
}

vector <PizzaMenu> SalesServices::ReturnPizzaMenu(){
    return pizzaMenuRepo.ReturnAllPizzaMenu();
}

vector<Products> SalesServices::ReturnAllProducts(){
    return prodRepo.returnProducts();
}


DeliveryPlaces SalesServices::GetDeliveryPlace(char index){
    vector<DeliveryPlaces> allplaces = plcRepo.ReturnAllPlaces();
    for(unsigned int i = 0; i < allplaces.size(); i++){
        if(allplaces[i].GetKey() == index){
            _deliveryPlace = allplaces[i];
            return allplaces[i];

        }

    }
    throw InvalidDeliveryPlaceInput();
}


Pizza SalesServices::selectPizzaFromMenu( char input ){
    vector<PizzaMenu> PizzaMenu = pizzaMenuRepo.ReturnAllPizzaMenu();
    for(unsigned int i = 0; i < PizzaMenu.size(); i++ ){
        if(PizzaMenu[i].getKey() == input){
            return Pizza(PizzaMenu[i].getPizza());
        }
    }
    throw invalidPizzaSelection();
}
