#include "staffServices.h"

staffServices::staffServices(){
}
vector<Pontun> staffServices::ReturnUnPayedOrders(){
    vector<Pontun> orders;

    orders = repo.ReturnOrders(true,false,false);
    return orders;
}
bool staffServices::PayForOrder(int orderNo){
    vector<Pontun> orders = repo.ReturnAllOrders();
    for(unsigned int i = 0; i < orders.size(); i++){
        if( orders[i].GetPizzaNumber() == orderNo ){
            orders[i].payOrder();
            return true;
        }
    }
    return false;
}
void staffServices::deliverOrder( int orderID ){

}
