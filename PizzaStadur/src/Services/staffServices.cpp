#include "staffServices.h"

staffServices::staffServices(){
}
vector<Pontun> staffServices::ReturnUnPayedOrders(){
    return repo.ReturnOrders(true,false,false);
}
vector<Pontun> staffServices::ReturnUnDeliverdOrder(){
        return repo.ReturnOrders(true,true,false);
}



bool staffServices::PayForOrder(int orderNo){
    vector<Pontun> orders = repo.ReturnAllOrders();
    for(unsigned int i = 0; i < orders.size(); i++){
        if( orders[i].GetOrderNo() == orderNo ){
            orders[i].payOrder();
            return true;
        }
    }
    return false;
}

bool staffServices::DeliverOrder(int orderNo){
    vector<Pontun> orders = repo.ReturnAllOrders();
    for(unsigned int i = 0; i < orders.size(); i++){
        if( orders[i].GetOrderNo() == orderNo ){
            orders[i].deliverOrder();
            return true;
        }
    }
    return false;
}

