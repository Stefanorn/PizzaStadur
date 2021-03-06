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

Pontun SalesServices::computeTotalPrice( Pontun order,
                                         vector<Pizza> allPizza,
                                         vector<productOnFile> allProd ){
    int orderId = order.GetOrderNo();
    for(unsigned int i = 0; i < allPizza.size(); i++){
        if( orderId == allPizza[i].getPizzaToOrderId()){
            order.ComputeTotalPrice( allPizza[i].getPrice() );
            }
        }
    for(unsigned int i = 0; i < allProd.size(); i++ ){
        if( orderId ==  allProd[i].getID()){
            order.ComputeTotalPrice( allProd[i].getProductPrice());
        }
    }

    return order;

}

void SalesServices::CommitOrder(Pontun order){

   ordRepo.WriteOrderToFile( order );
}

void SalesServices::commitProduct(productOnFile prod){
    producFileRepo.writeProdToFile( prod );
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

Pontun SalesServices::DeliveredOrPickedUp(Pontun order, char input){
    order.DeliveryOrPickUp(input);
    return order;
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

productOnFile SalesServices::selectProduct(char input){
    vector<Products> product = prodRepo.returnProducts();
    for(unsigned int i = 0; i < product.size(); i++){
        if( product[i].getKey() == input ){
            productOnFile temp( product[i].getProductName(),
                                product[i].getProductPrice() );

            return temp;
        }
    }
    throw InvalidProductHotkey();
}


vector<productOnFile> SalesServices::getProductByID(int id){
    vector<productOnFile> all = producFileRepo.ReturnAllProds();
    vector<productOnFile> selected;
    for(unsigned int i = 0; i < all.size(); i++){
        if(id == all[i].getID()){
            selected.push_back(all[i]);
        }
    }
    return selected;
}
