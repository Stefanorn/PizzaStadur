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

        if (input == '1'){
            SalesUI run;

        }

        else if (input == '2'){
            BakerUI bakerui;
            bakerui.mainMenu();
        }

        else if (input == '3'){
            StaffUI run;
        }

        else if (input == '4'){
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

        else {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}
