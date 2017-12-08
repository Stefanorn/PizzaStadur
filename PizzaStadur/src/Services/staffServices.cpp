#include "staffServices.h"

staffServices::staffServices(){
}
vector<Pontun> staffServices::ReturnUnPayedOrders(){
    //Þarf að velja úr hvaða pantanir ég villPrenta
    return repo.ReturnAllOrders();
}
vector<Pontun> staffServices::ReturnUnDeliverdOrder(){
    //Þarf að velja úr hvaða pantanir ég villPrenta
        return repo.ReturnAllOrders();
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

