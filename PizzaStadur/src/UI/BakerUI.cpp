#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::_mainMenu(){
    //while(true){
        cout << "Where would you like to bake the pizza?" << endl;
        //kalla á fall sem gerir "cin << einhver staður"
        cout << "Press 1 to bake the pizza" << endl;
        char input;
        cin >> input;
        if (input == '1'){
            cout << "Baking pizza..." << endl;
        }
        _clockMessages();
    //}
}

void BakerUI::_clockMessages(){
    clock_t time = clock() / CLOCKS_PER_SEC;
    while(true){
        if (clock() / CLOCKS_PER_SEC == time + 10){
            cout << "Pizza is ready!";
            break;
        }
    }
}
