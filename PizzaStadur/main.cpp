#include "StaffUI.h"
#include "BakerUI.h"
#include "SalesUI.h"
#include "AdminUI.h"
#include "PlacesRepo.h"

int main()
{
    while(true){
        system("CLS");
        cout << "Welcome to N3rdy pizza! How can we be of service to you?" << endl << endl;
        cout << "Press 1 to make/view an order" << endl;
        cout << "Press 2 for baking" << endl;
        cout << "press 3 to pay or deliver orders" << endl;
        cout << "Press 4 if you are the manager" << endl;
        cout << "Press 5 to quit" << endl;
        cout << "Press 6 to remove everything !!!!" << endl;
        char input;
        cin >> input;

        if (input == '1') {
            try {
                SalesUI run;
            }
            catch (InvalidDeliveryPlaceInput){
                cout << "Oops, that delivery place does not exist! Try again" << endl;
                system("PAUSE");
            }
            catch (nothingInFile) {
                cout << "No delivery places found, returning to main menu" << endl;
                system("PAUSE");
            }
        }

        else if (input == '2'){
            try {
                BakerUI bakerui;
                bakerui.mainMenu();
            }
            catch (InvalidDeliveryPlaceInput){
                cout << "Oops, that delivery place does not exist! Try again" << endl;
                system("PAUSE");
            }
            catch (nothingInFile) {
                cout << "No delivery places found, returning to main menu" << endl;
                system("PAUSE");
            }
        }

        else if (input == '3'){
            try {
                StaffUI run;
            }
            catch (InvalidDeliveryPlaceInput){
                cout << "Oops, that delivery place does not exist! Try again" << endl;
                system("PAUSE");
            }
            catch (nothingInFile) {
                cout << "No delivery places found, returning to main menu" << endl;
                system("PAUSE");
            }
        }

        else if (input == '4'){
            AdminUI adminUI;
            adminUI.mainMenu();
        }

        else if (input == '5'){
            return 0;
        }

        else if (input == '6'){
            cout << "Are you sure you want to proceed? (y/n)" << endl;
            cout << "This will delete all data from the system." << endl;
            cin >> input;
            if(input == 'y'){
                if(!remove("orders.bin")) cout << "Removing all orders from file..." << endl;
                if(!remove("pizza.bin")) cout << "Removing all pizzas from file..." << endl;
                if(!remove("toppings.bin")) cout << "Removing all toppings from file..." << endl;
                if(!remove("toppingsMenu.bin")) cout << "Removing all menus from file..." << endl;
                if(!remove("places.bin")) cout << "Removing all places from file..." << endl;
                if(!remove("products.bin")) cout << "Removing all products from file..." << endl;
                if(!remove("PizzMenuItems.bin"));
                cout << "Resetting program..." << endl;
            }
            else if(input == 'n'){
                cout << "Action aborted" << endl;
            }
            else{
                cout << "Invalid input. Action aborted." << endl;
            }
            system("PAUSE");
        }

        else {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}
