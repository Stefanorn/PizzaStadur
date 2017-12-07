#include "SalesServices.h"

SalesServices::SalesServices()
{
    //ctor
}

void SalesServices::CommitOrder(Pontun order){
   repo.WriteOrderToFile( order );
}
int SalesServices::OrderNumber(){
    return repo.getOrderNo();
}
