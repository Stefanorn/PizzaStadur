#include "BakerServices.h"

BakerServices::BakerServices()
{
    //ctor
}

bool BakerServices::hasBeenBaked(){
    return _hasBeenBaked;
}

void BakerServices::bakeSomePizza(){

    _hasBeenBaked = true;
}


//Bakarinn bakar pizzuna
void BakerServices::bakePizza(){
    if(_temp_vector[0] < 1){
        cout << "No order has been made!" << endl;
        return;
    }
    for(int i = 0; i < _temp_vector[0]; i++){
        if(!hasBeenBaked())
            cout << "Hér eiga allar virkar pantanir fyrir þennan stað að birtast" << endl;
    }
    int index = 0;
    bool valid_input = false;
    while(valid_input == false){
        cout << "Select order to bake " << endl;
        cin >> index;
        /*if(cin.fail()){
            cout << "Invalid input" << endl;
        }*/
        if(index < 1 || index > _temp_vector[0]){
            cout << "Invalid input" << endl;
        }
        else{
            valid_input = true;
        }
    }
    cout << "Baking order no " << index << endl;
    cout << "Hér þarf að koma kóði sem bakar pizzuna ";
    cout << "(Setur true flagga)." << endl;
    cout << "Pizza has been baked. Order no " << index << " is ready" << endl;

    cout << "Að lokum þarf að uppfæra orders lista hér." << endl;
}
