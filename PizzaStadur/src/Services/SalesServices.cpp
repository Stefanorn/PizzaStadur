#include "SalesServices.h"

SalesServices::SalesServices()
{
    //ctor
}

void SalesServices::CommitOrder(Pontun order){
   repo.WriteOrderToFile( order );
}


void SalesServices::CommitPizza(Pizza pizza){
    pizza.setPizzaID( pzRepo.MakePizzaID() );
    pzRepo.WriteOrderToFile(pizza);
}
int SalesServices::OrderNumber(){
    return repo.getOrderNo();
}
Pontun SalesServices::returnAOrder( int orderNo ){
    vector<Pontun> allOrders = repo.ReturnAllOrders();
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

double SalesServices::GetOrderPrice(){
    double price;
    Pizza pizza;
   // price = pizza.getPrice();
    return price;
}

//void SalesServices::AssignOrderToPlace(){

//}
