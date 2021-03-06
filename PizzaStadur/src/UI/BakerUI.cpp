#include "BakerUI.h"

BakerUI::BakerUI()
{
    selectDeliveryPlace();
}

void BakerUI::mainMenu(){
    while(true){
        system("CLS");
        cout << "Press 1 to bake a pizza" << endl;
        cout << "Press 2 to list all unbaked pizzas " << endl;
        cout << "Press 3 to quit" << endl;
        char input;
        cin >> input;
        if (input == '1')
            {system("CLS");
                try {
                    cout << "Enter the ID number of the pizza you want to bake" << endl;
                    int pizzaOrder;
                    cin >> pizzaOrder;
                    if( !cin.fail()){
                        bakerService.bakePizza( pizzaOrder );
                        // bakerService.clockMessages();
                        cout << "Pizza is ready!" << endl;
                        //id = true;
                        system("PAUSE");
                    }
                }
                catch (invalidPizzaSelection) {
                    cout << "Can't find that pizza. Are you sure it exists?" << endl;
                    system("PAUSE");
                }
        }
        else if (input == '2'){
            vector<Pizza> unbakedPizzas = bakerService.ReturnUnbakedPizzas();
            for(unsigned int i = 0; i < unbakedPizzas.size(); i++ ){
                cout << unbakedPizzas[i];
            }
            if(unbakedPizzas.size() == 0) {
                cout << "All the pizzas have been baked! Great job!" << endl;

            }
            system("PAUSE");

        }
        else if (input == '3'){
            return;
        }
        else {
            cout << "Oops, that's not the right command! " << endl;
        }
    }
}

void BakerUI::selectDeliveryPlace(){
    system("CLS");
    vector<DeliveryPlaces> allPlaces = bakerService.GetAllPlaces();
    for(unsigned int i = 0; i < allPlaces.size(); i++){

        cout << allPlaces[i];
    }
    if (allPlaces.size() > 0) {
            cout << "Select a pizza place" << endl;
            char input;
            cin >> input;
            _selectedDeliveryPlace = bakerService.GetDeleveryPlace(input);
    }
    else if (allPlaces.size() == 0){
        throw nothingInFile();
    }


}

