#include "Pizzasdadur.h"
#include "StaffUI.h"
#include "BakerUI.h"
#include "SalesUI.h"
#include "AdminUI.h"
#include "PlacesRepo.h"

int main()
{
    while(true){
        system("CLS");
        cout << "Welcome to N3rdy pizza! How can we be of service?" << endl << endl;
        cout << "Press 1 to make/view an order" << endl;
        cout << "Press 2 for baking" << endl;
        cout << "press 3 to pay or deliver orders" << endl;
        cout << "Press 4 if you are the manager" << endl;
        cout << "Press 5 to quit" << endl;
        cout << "Press 6 to remove everything !!!!" << endl;
        char input;
        cin >> input;

        if (input == '1'){
            system("CLS");
            SalesUI run;

        }
        else if (input == '2'){
            system("CLS");
            BakerUI bakerui;
            bakerui.mainMenu();
            system("pause");

        }
        else if (input == '3'){
            system("CLS");
            StaffUI run;
        }
        else if (input == '4'){
            system("CLS");
            AdminUI adminUI;
            adminUI.mainMenu();

        }
        else if (input == '5'){
            return 0;

        }
        else if (input == '6'){
            if(!remove("orders.bin")) cout << "remove all orders\n";
            if(!remove("pizza.bin")) cout << "remove all pizza\n";
            if(!remove("toppings.bin")) cout << "remove all topping\n";
            if(!remove("toppingsMenu.bin")) cout << "remove all toppingsMenu\n";
            if(!remove("places.bin")) cout << "remove all places\n";
            system("PAUSE");
        }
        else{
            cout << "Invalid input" << endl;
            system("CLS");
        }
    }

    return 0;
}
