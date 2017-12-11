#include "staffServices.h"

staffServices::staffServices(){
}
vector<Pontun> staffServices::ReturnUnPaidOrders(){
    vector<Pontun> allOrders = repo.ReturnAllOrders();
    vector<Pontun> UnPaidOrders;
    for(unsigned int i = 0; i < allOrders.size(); i++){
        if(!allOrders[i].IsOrderPaid()){
            UnPaidOrders.push_back(allOrders[i]);
        }
    }
    return UnPaidOrders;
}

vector<Pontun> staffServices::ReturnUnDeliveredOrder(){
    vector<Pontun> allOrders = repo.ReturnAllOrders();
    vector<Pontun> UnDeliveredOrders;
    for(unsigned int i = 0; i < allOrders.size(); i++){
        if(!allOrders[i].IsOrderDelivered()){
            UnDeliveredOrders.push_back(allOrders[i]);
        }
    }
    return UnDeliveredOrders;
}

bool staffServices::PayForOrder(int orderNo){
    vector<Pontun> orders = repo.ReturnAllOrders();
    for(unsigned int i = 0; i < orders.size(); i++){
        if( orders[i].GetOrderNo() == orderNo ){
            orders[i].payOrder();
            repo.RewriteFile( orders );
            return true;
        }
    }
    throw NoOrderToReturnExeption();
    return false;
}

bool staffServices::DeliverOrder(int orderNo){
    vector<Pontun> orders = repo.ReturnAllOrders();
    for(unsigned int i = 0; i < orders.size(); i++){
        if( orders[i].GetOrderNo() == orderNo ){
            orders[i].deliverOrder();
            repo.RewriteFile( orders );
            return true;
        }
    }
    throw NoOrderToReturnExeption();
    return false;
}

