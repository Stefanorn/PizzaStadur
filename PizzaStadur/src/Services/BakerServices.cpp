#include "BakerServices.h"

BakerServices::BakerServices()
{
    //ctor
}

void BakerServices::bakePizza(int pizzaId){
    vector<Pizza> allPizzas = pzRepo.ReturnAllPizzas();
    for(unsigned int i = 0; i < allPizzas.size(); i++){
        if( allPizzas[i].getPizzaID() == pizzaId ){
            allPizzas[i].bakePizza();
        }
    }
    pzRepo.RewriteFile(allPizzas);
}


vector<Pizza> BakerServices::ReturnUnbakedPizzas(){

    vector<Pizza> allPizzas = pzRepo.ReturnAllPizzas();
    vector<Pizza> allBakedPizzas;
    for( unsigned int i = 0; i < allPizzas.size(); i++){

        if(!allPizzas[i].isPizzaBaked()){
            allBakedPizzas.push_back(allPizzas[i]);
        }
    }
    return allBakedPizzas;
}


void BakerServices::clockMessages(){
    clock_t time = clock() / CLOCKS_PER_SEC;
    while(true){
        if (clock() / CLOCKS_PER_SEC == time + 10){
            break;
        }
    }
}
