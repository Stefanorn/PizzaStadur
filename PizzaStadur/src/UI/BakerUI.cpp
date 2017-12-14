#include "BakerUI.h"

BakerUI::BakerUI()
{
    selectDeliveryPlace();
}

void BakerUI::mainMenu(){
    while(true){
        system("CLS");
        cout << "Press 1 to bake the pizza" << endl;
        cout << "Press 2 to list all unbaked " << endl;
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
            cout << "Oops, that wasn't the right command!" << endl;
        }
    }
}

void BakerUI::selectDeliveryPlace(){
    system("CLS");
    vector<DeliveryPlaces> allPlaces = bakerService.GetAllPlaces();
    for(unsigned int i = 0; i < allPlaces.size(); i++){

        cout << allPlaces[i];
    }

    bool place = false;
    if (allPlaces.size() > 0) {
        while(place == false){
            try {
                cout << "Select a PizzaPlace" << endl;
                char input;
                cin >> input;
                _selectedDeliveryPlace = bakerService.GetDeleveryPlace(input);
                place = true;
            }
            catch (InvalidDeliveryPlaceInput){
                cout << "Oops, that delivery place does not exist! Try again" << endl;
                place = false;
            }
        }
    }
    else if (allPlaces.size() == 0){
        throw nothingInFile();
    }


}

