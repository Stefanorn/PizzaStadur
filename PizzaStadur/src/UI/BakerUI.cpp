#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::mainMenu(){
    //while(true){
        cout << "Where would you like to bake the pizza?" << endl;
        //kalla � fall sem gerir "cin << einhver sta�ur"
        cout << "Press 1 to bake the pizza" << endl;
        char input;
        cin >> input;
        if (input == '1'){
            cout << "Baking pizza..." << endl;
        }
        bakerService._clockMessages();
    //}
}
