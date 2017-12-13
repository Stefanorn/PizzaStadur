#include "SalesServices.h"

SalesServices::SalesServices(){
    //ctor
}

void SalesServices::CommitOrder(Pontun order){
    vector<Pizza> allPizza = pzRepo.ReturnAllPizzas();
    vector<Toppings> allToppings = topRepo.returnToppings();
    for(unsigned int i = 0; i < allPizza.size(); i++){
        if( order.GetOrderNo() == allPizza[i].getPizzaToOrderId()){
            order.ComputeTotalPrice( allPizza[i].getPrice() );

            for( unsigned int j = 0; j < allToppings.size(); j++){
                if( allPizza[i].getPizzaID() == allToppings[j].getToppingID() ){
                    order.ComputeTotalPrice( allToppings[j].getToppingPrice() );

                }

            }
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


void SalesServices::addToppingToPizza( char index ){
    vector<ToppingsMenuItem> allToppingsMenu = topMenuRepo.returnToppings();

    for(unsigned int i = 0; i < allToppingsMenu.size(); i++){
        if( index == allToppingsMenu[i].getHotkey() ){
            Toppings item(allToppingsMenu[i].getName(), allToppingsMenu[i].getPrice(), pzRepo.MakePizzaID()-1 );
                                                                            /// slæm harðkóðun -1 til að fá seinustu pizzu sem var bættvið
                                                                            /// ef ég kalla á þetta fall áður enn ég bý til pizzuna þá fer
                                                                            /// allt í fokk, kettir verða hundar og það fer að rigna upp

            topRepo.addTopping( item );
            return;
        }
    }
    throw invalidToppingHotkey();
}

vector<ToppingsMenuItem> SalesServices::GetToppingsMenu(){
    return topMenuRepo.returnToppings();
}

vector<Toppings> SalesServices::getToppingsByPizzaID(int id){
    vector<Toppings> allTopping = topRepo.returnToppings();
    vector<Toppings> selectedToppings;
    for(unsigned int i = 0; i < allTopping.size(); i++){
        if(allTopping[i].getToppingID() == id){
            selectedToppings.push_back(allTopping[i]);
        }
    }
    return selectedToppings;
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

Products SalesServices::selectProduct(char input){
    vector<Products> product = prodRepo.returnProducts();
    for(unsigned int i = 0; i < product.size(); i++){
        //product[i].getProductID;
    }
}
