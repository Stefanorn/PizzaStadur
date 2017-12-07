#include "SalesServices.h"

SalesServices::SalesServices()
{
    //ctor
}

void SalesServices::CommitOrder(Pontun order){
   repo.WriteOrderToFile( order );
}

void SalesServices::CommitPizza(Pizza pizza){
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
