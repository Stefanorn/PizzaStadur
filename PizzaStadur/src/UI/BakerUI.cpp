#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::mainMenu(){
    while(true){
        cout << "Where would you like to bake the pizza?" << endl;
        //kalla � fall sem gerir "cin << einhver sta�ur"
        //Pizzur �urfa a� vita hvar ��r eiga a� vera
        // e�a �g get l�ti� leita a� pontunum a fundi� gefinn sta� og
        // s�tt pizzur me� �etta order number sem eru � �essum sta�.
        cout << "Press 1 to bake the pizza" << endl;
        cout << "Press 2 to list all unbaked " << endl;
        cout << "Press 3 to quit" << endl;
        char input;
        cin >> input;
        if (input == '1'){
            cout << "Enter the pizza id number of pizza you whant to bake" << endl;
            int pizzaOrder;
            cin >> pizzaOrder;
            bakerService.bakePizza( pizzaOrder );
            // bakerService.clockMessages();
            cout << "Pizza is ready!" << endl;
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
