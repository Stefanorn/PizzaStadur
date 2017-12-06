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
            cout << "H�r eiga allar virkar pantanir fyrir �ennan sta� a� birtast" << endl;
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
    cout << "H�r �arf a� koma k��i sem bakar pizzuna ";
    cout << "(Setur true flagga)." << endl;
    cout << "Pizza has been baked. Order no " << index << " is ready" << endl;

    cout << "A� lokum �arf a� uppf�ra orders lista h�r." << endl;
}
