#include "BakerUI.h"

BakerUI::BakerUI()
{
    selectDeliveryPlace();
}

void BakerUI::mainMenu(){
    while(true){

        cout << "Press 1 to bake the pizza" << endl;
        cout << "Press 2 to list all unbaked " << endl;
        cout << "Press 3 to quit" << endl;
        char input;
        cin >> input;
        if (input == '1'){
            cout << "Enter the pizza id number of pizza you whant to bake" << endl;
            int pizzaOrder;
            cin >> pizzaOrder;
            if( !cin.fail()){

            bakerService.bakePizza( pizzaOrder );
            // bakerService.clockMessages();
            cout << "Pizza is ready!" << endl;

            }
            else{
                cout << "Invalid Input" << endl;
            }

        }
        else if (input == '2'){
            vector<Pizza> unbakedPizzas = bakerService.ReturnUnbakedPizzas();
            for(unsigned int i = 0; i < unbakedPizzas.size(); i++ ){
                cout << unbakedPizzas[i];
            }

        }
        else if (input == '3'){
            return;
        }
    }
}

void BakerUI::selectDeliveryPlace(){

    vector<DeliveryPlaces> allPlaces = bakerService.GetAllPlaces();
    for(unsigned int i = 0; i < allPlaces.size(); i++){

        cout << allPlaces[i];
    }
    cout << "Select a PizzaPlace" << endl;
    char input;
    cin >> input;

    _selectedDeliveryPlace = bakerService.GetDeleveryPlace(input);

}

