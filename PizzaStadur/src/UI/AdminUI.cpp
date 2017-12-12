#include "AdminUI.h"

AdminUI::AdminUI()
{
    //ctor
}

void AdminUI::mainMenu(){
    char input;
    int size;
    while(true){
        system("CLS");
        cout << "Hello Mr. Boss" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Press 1 to register new pizza sizes or bases" << endl << "Press 2 to register new toppings" << endl
             << "Press 3 to register new menu items" << endl << "Press 4 to register new products" << endl
             << "Press 5 to edit prices" << endl << "Press 6 to register new places for delivery" << endl
             << "Press 7 to go back to the main menu" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> input;

        if(input == '1'){
            _adminService.registerBaseSize();
        }
        else if(input == '2'){
            do{
                cout << "How many toppings would you like to register? " ;
                cin >> size;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Incorrect Input" << endl
                    << "How many toppings would you like to register? " ;
                    cin >> size;
                }
                system("CLS");
                cout << "Please enter the topping you would like to add, followed by its price:" << endl;
                for( int i = 0; i < size; i++){
                    ToppingsMenuItem temp;
                    cout << "Topping " << i + 1 << endl;
                    cin >> temp;
                    cout << endl;
                    _adminService.registerToppings(temp);

                }
                cout << "Would you like to add more toppings (y/n)?" << endl;
                cin >> input;
            }
            while(input == 'y');
        }
        else if(input == '3'){
            _adminService.registerPizza();
        }
        else if(input == '4'){
            do{
            cout << "How many products would you like to register? " << endl;
            cin >> size;
            cout << "Please enter the product you would like to add, followed by its price:" << endl;
            vector<Products> product(size);
            for(unsigned int i = 0; i < product.size(); i++){
                cout << "Product " << i + 1 << endl;
                cin >> product[i];
                cout << endl;
            }

            _adminService.registerProduct(size);
            cout << "Would you like to add other products (y/n)?" << endl;
            cin >> input;
            }
            while(input == 'y');
        }
        else if(input == '5'){
            _adminService.editPrices();
        }
        else if(input == '6'){
            do{
                cout << "How many places would you like to add?" << endl;
                cin >> size;
                cout << "Where would you like to open your new place(s)?" << endl;
                vector<DeliveryPlaces> places(size);
                for(unsigned int i = 0; i < places.size(); i++){
                    cout << "Place " << i + 1 << endl;
                    cin >> places[i];
                    cout << endl;
                    _adminService.registerPlaces( places[i] );
                }
                cout << "Would you like to add more places (y/n)?" << endl;
                cin >> input;
            }
            while(input == 'y');
        }
        else if(input == '7'){
            break;
        }
        else{
            cout << "Invalid input" << endl;
        }
    }
}
