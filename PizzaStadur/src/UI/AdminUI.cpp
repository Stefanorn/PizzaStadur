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
        cout << "Hello Boss!" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Press 1 to register new toppings" << endl
             << "Press 2 to register new menu items" << endl
             << "Press 3 to register new products" << endl
             << "Press 4 to edit prices" << endl
             << "Press 5 to register new places for delivery" << endl
             << "Press 6 to go back to the main menu" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> input;

        if(input == '1'){
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
            for( int i = 0; i < size; i++){
                ToppingsMenuItem temp;
                cout << "Topping " << i + 1 << endl;
                cin >> temp;
                cout << endl;
                _adminService.registerToppings(temp);

            }
        }
        else if(input == '2'){
            PizzaMenu temp;
            cin >> temp;
            cout << "How many toppings would you like to register? " ;
            cin >> size;
            while(cin.fail() || size > 16){
                cin.clear();
                cin.ignore();
                cout << "Incorrect Input" << endl
                << "How many toppings would you like to register? " ;
                cin >> size;
            }
            vector<ToppingsMenuItem> toppingsMenu = _adminService.returnToppingsMenu();
            for(unsigned int i = 0; i < toppingsMenu.size(); i++){
                cout << toppingsMenu[i] << endl;
            }
            vector<Toppings> inputs;
            for(int i = 0; i < size; i++){
                cin >> input;
                Toppings temp = _adminService.CharToTopping(input);
                inputs.push_back(temp);
            }
            _adminService.registerPizza( temp,inputs );
            system("PAUSE");
            cout << temp;
        }
        else if(input == '3'){
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
        else if(input == '4'){
            system("CLS");
            cout << "What prices would you like to change?" << endl << endl;
            cout << "Press 1 for menu items" << endl;
            cout << "Press 2 for pizza bases (OUT OF ORDER)" << endl;
            cout << "Press 3 for pizza sizes (OUT OF ORDER)" << endl;
            cout << "Press 4 for toppings" << endl;
            cin >> input;
            double newPrice = 0;

            if(input == '1'){
                cout << "Please select an item from the menu" << endl;
                /// cout << menu;
                cin >> input;
                cout << "Enter the item's new price " << endl;
                cin >> newPrice;
                _adminService.editMenuPrices(newPrice);
                cout << "The item's price has been successfully changed!" << endl;
                system("PAUSE");
            }


            else if(input == '4'){
                cout << "Please select a topping from the menu" << endl;
                /// cout << toppings;
                cin >> input;
                cout << "Enter the topping's new price " << endl;
                cin >> newPrice;
                _adminService.editToppingPrices(newPrice);
                cout << "The topping's price has been successfully changed!" << endl;
                system("PAUSE");
            }

            else{
                //throw SomeException;
            }
        }
        else if(input == '5'){
            cout << "How many places would you like to add?";
            cin >> size;
            while(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Incorrect Input" << endl
                << "How many places would you like to add? " ;
                cin >> size;
            }
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
        else if(input == '6'){
            break;
        }
        else{
            cout << "Invalid input" << endl;
        }
    }
}
