#include "BakerServices.h"

BakerServices::BakerServices()
{
    //ctor
}

void BakerServices::bakePizza(int pizzaId){

    vector<Pizza> allPizzas = pzRepo.ReturnAllPizzas();

    Pizza pz;

    for(unsigned int i = 0; i < allPizzas.size(); i++){
        if( allPizzas[i].getPizzaID() == pizzaId && allPizzas[i]._place == _deliveryPlace ){
            allPizzas[i].bakePizza();
            pzRepo.RewriteFile(allPizzas);
            return;
        }
    }
    throw invalidPizzaSelection();

}


vector<Pizza> BakerServices::ReturnUnbakedPizzas(){

    vector<Pizza> allPizzas = pzRepo.ReturnAllPizzas();
    vector<Pizza> allBakedPizzas;
    for( unsigned int i = 0; i < allPizzas.size(); i++){
        if(!allPizzas[i].isPizzaBaked()){
            if( allPizzas[i]._place == _deliveryPlace ){
                allBakedPizzas.push_back(allPizzas[i]);
            }
        }
    }
    return allBakedPizzas;
}

DeliveryPlaces BakerServices::GetDeleveryPlace(char input){

    vector<DeliveryPlaces> allplaces = plcRepo.ReturnAllPlaces();
    for(unsigned int i = 0; i < allplaces.size(); i++){
        if(allplaces[i].GetKey() == input ){
            _deliveryPlace = allplaces[i];
            return allplaces[i];
        }

    }
    throw InvalidDeliveryPlaceInput();

}
vector<DeliveryPlaces> BakerServices::GetAllPlaces(){
    return plcRepo.ReturnAllPlaces();
}

void BakerServices::clockMessages(){
    clock_t time = clock() / CLOCKS_PER_SEC;
    while(true){
        if (clock() / CLOCKS_PER_SEC == time + 3){
            break;
        }
    }
}
