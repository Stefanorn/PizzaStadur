#include "AdminUI.h"

AdminUI::AdminUI()
{
    //ctor
}

void AdminUI::mainMenu(){
    while(true){
        cout << "Hello Mr. Boss" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Press 1 to register a new pizza, 2 to register new toppings," << endl
            << "3 to register new offers, 4 to register new products," << endl
            << "5 to edit prices or 6 to register new places for deilvery" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        char input;
        cin >> input;

        if(input == '1'){
            //registerPizza();
        }
        else if(input == '2'){
            //registerToppings();
        }
        else if(input == '3'){
            //registerOffer();
        }
        else if(input == '4'){
            //registerProduct();
        }
        else if(input == '5'){
            //editPrices();
        }
        else if(input == '6'){
            //registerPlaces();
        }
        else{
            cout << "Invalid input" << endl;
        }
        break;
    }
}

void AdminUI::registerPizza(){

}
