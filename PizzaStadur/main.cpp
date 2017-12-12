#include "StaffUI.h"
#include "BakerUI.h"
#include "SalesUI.h"
#include "AdminUI.h"
#include "PlacesRepo.h"

int main()
{
    /*while(true){
        DeliveryPlaces places;
        cin >> places;
        int number = 0;
        PlacesRepo placesrepo;
        placesrepo.addPlaces(places, number);
        vector<DeliveryPlaces> del_pl = placesrepo.ReturnAllPlaces();
        for(unsigned int i = 0; i < del_pl.size(); i++){
            cout << del_pl[i];
        }
        AdminUI ui;
        ui.mainMenu();
    }*/
    while(true){
        system("CLS");
        cout << "Press 1 to make/view an order " << endl;
        cout << "Press 2 for baking " << endl;
        cout << "press 3 to mark order paid or delivered " << endl;
        cout << "Press 4 if you are the manager " << endl;
        cout << "Press 5 to quit " << endl;
        cout << "Press 6 to remove everything !!!!" << endl;
        char index;
        cin >> index;

        if (index == '1'){
            system("CLS");
            SalesUI run;

        }
        else if (index == '2'){
            system("CLS");
            BakerUI bakerui;
            bakerui.mainMenu();
            system("pause");

        }
        else if (index == '3'){
            system("CLS");
            StaffUI run;
        }
        else if (index == '4'){
            system("CLS");
            AdminUI adminUI;
            adminUI.mainMenu();

        }
        else if (index == '5'){
            return 0;

        }
        else if (index == '6'){
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
