#include "staffServices.h"

staffServices::staffServices(){
}
vector<Pontun> staffServices::ReturnUnPaidOrders(){
    vector<Pontun> allOrders = repo.ReturnAllOrders();


    vector<Pontun> UnPaidOrders;
    for(unsigned int i = 0; i < allOrders.size(); i++){
        if(!allOrders[i].IsOrderPaid() && allOrders[i].getDeliveryPlace() == _deliveryPlace){
            UnPaidOrders.push_back(allOrders[i]);
        }
    }
    return UnPaidOrders;
}

vector<Pontun> staffServices::ReturnUnDeliveredOrder(){
    vector<Pontun> allOrders = repo.ReturnAllOrders();
    vector<Pontun> UnDeliveredOrders;
    for(unsigned int i = 0; i < allOrders.size(); i++){
        if(!allOrders[i].IsOrderDelivered()  && allOrders[i].getDeliveryPlace() == _deliveryPlace){
            UnDeliveredOrders.push_back(allOrders[i]);
        }
    }
    return UnDeliveredOrders;
}

bool staffServices::PayForOrder(int orderNo){
    vector<Pontun> orders = repo.ReturnAllOrders();
    for(unsigned int i = 0; i < orders.size(); i++){
        if( orders[i].GetOrderNo() == orderNo  && orders[i].getDeliveryPlace() == _deliveryPlace ){
            orders[i].payOrder();
            repo.RewriteFile( orders );
            return true;
        }
    }
    throw NoOrderToReturnExeption();
    return false;
}

Pontun staffServices::DeliverOrder(int orderNo){
    vector<Pontun> orders = repo.ReturnAllOrders();
    for(unsigned int i = 0; i < orders.size(); i++){
        if( orders[i].GetOrderNo() == orderNo  && orders[i].getDeliveryPlace() == _deliveryPlace ){

            repo.RewriteFile( orders );
            orders[i].deliverOrder();
            return orders[i];
        }
    }
    throw NoOrderToReturnExeption();
}


vector<DeliveryPlaces> staffServices::GetAllPlaces(){
    return placeRepo.ReturnAllPlaces();
}

DeliveryPlaces staffServices::GetDeliveryPlace(char input){

    vector<DeliveryPlaces> allplaces = placeRepo.ReturnAllPlaces();
    for(unsigned int i = 0; i < allplaces.size(); i++){
        if(allplaces[i].GetKey() == input){
            _deliveryPlace = allplaces[i];
            return allplaces[i];

        }

    }
    throw InvalidDeliveryPlaceInput();

}
