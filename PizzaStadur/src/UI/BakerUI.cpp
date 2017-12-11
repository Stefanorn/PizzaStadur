#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::mainMenu(){
    //while(true){
        cout << "Where would you like to bake the pizza?" << endl;
        //kalla á fall sem gerir "cin << einhver staður"
        //Pizzur þurfa að vita hvar þær eiga að vera
        // eða ég get látið leita að pontunum a fundið gefinn stað og
        // sótt pizzur með þetta order number sem eru á þessum stað.
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
