#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::mainMenu(){
    //while(true){
        cout << "Where would you like to bake the pizza?" << endl;
        //kalla � fall sem gerir "cin << einhver sta�ur"
        //Pizzur �urfa a� vita hvar ��r eiga a� vera
        // e�a �g get l�ti� leita a� pontunum a fundi� gefinn sta� og
        // s�tt pizzur me� �etta order number sem eru � �essum sta�.
        cout << "Press 1 to bake the pizza" << endl;
        char input;
        cin >> input;
        if (input == '1'){
            cout << "Baking pizza..." << endl;
        }
        bakerService.clockMessages();
        cout << "Pizza is ready!" << endl;
    //}
}
