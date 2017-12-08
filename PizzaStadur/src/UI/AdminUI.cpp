#include "AdminUI.h"

AdminUI::AdminUI()
{
    //ctor
}

void AdminUI::mainMenu(){
    char input;
    while(true){
        cout << "Hello Mr. Boss" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Press 1 to register a new pizza" << endl << "Press 2 to register new toppings" << endl
            << "Press 3 to register new offers" << endl << "Press 4 to register new products" << endl
            << "Press 5 to edit prices" << endl << "Press 6 to register new places for delivery" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> input;

        if(input == '1'){
            _adminService.registerPizza();
        }
        else if(input == '2'){
            do{
                cout << "How many toppings would you like to register? " << endl;
                _adminService.registerToppings();
                cout << endl;
                cout << "Would you like to add more toppings (y/n)?" << endl;
                cin >> input;
            }
            while(input == 'y');
        }
        else if(input == '3'){
            _adminService.registerOffer();
        }
        else if(input == '4'){
            _adminService.registerProduct();
        }
        else if(input == '5'){
            _adminService.editPrices();
        }
        else if(input == '6'){
            cout << "How many places would you like to add?" << endl;
            _adminService.registerPlaces();
        }
        else{
            cout << "Invalid input" << endl;
        }
        break;
    }
}
