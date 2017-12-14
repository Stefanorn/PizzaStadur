#include "StaffUI.h"

StaffUI::StaffUI(){


    selectDeliveryPlace();

    while(true){
        cout << "Press 1 to pay for order, " << endl;
        cout << "press 2 to deliver order " << endl;
        cout << "press 3 to go back to the main menu " << endl;
        char input;
        cin >> input;

        if(input == '1'){
            PayForOrder();
            system("CLS");
        }
        else if(input == '2'){
            DeliverOrder();
            system("CLS");
        }
        else if (input == '3'){

            return;
        }
        else {
            cout << "Invalid input " << endl;
            system("CLS");
        }

    }
}
void StaffUI::PayForOrder(){
    vector<Pontun> orders = service.ReturnUnPaidOrders();
    if(orders.size() == 0){
        cout << "No unpaid orders!" << endl;
        system("PAUSE");
        return;
    }
    cout << "---------------------------------------------" << endl;
    for(unsigned int i = 0; i < orders.size(); i++){
        cout << orders[i];
    }
    cout << "---------------------------------------------" << endl;
    cout << "Select order to pay for" << endl;

    int input;
    cin >> input;
      if(cin.fail()){
        cin.clear();
        cin.ignore();
      }
        if(service.PayForOrder(input)){
            cout << "Order number " << input << " paid" << endl;
            system("pause");
        }
        else{
            cout << "Failed to pay for order" << endl;
            system("pause");
        }
}
void StaffUI::DeliverOrder(){
    vector<Pontun> orders = service.ReturnUnDeliveredOrder();
    if(orders.size() == 0){
        cout << "Well done! All orders have been delivered!" << endl;
        system("PAUSE");
        return;
    }
    cout << "---------------------------------------------" << endl;
    for(unsigned int i = 0; i < orders.size(); i++){
        cout << orders[i];
    }
    cout << "---------------------------------------------" << endl;
    cout << "Select order to deliver " << endl;

    int input;
    cin >> input;
      if(cin.fail()){
        cin.clear();
        cin.ignore();
      }
        if(service.DeliverOrder(input)){
            cout << "Order number " << input << " has been delivered" << endl;
            system("pause");
        }
        else{
            cout << "Failed to pay for order" << endl;
            system("pause");
        }
}


void StaffUI::selectDeliveryPlace(){

    vector<DeliveryPlaces> allPlaces = service.GetAllPlaces();
    for(unsigned int i = 0; i < allPlaces.size(); i++){

        cout << allPlaces[i];
    }
    if (allPlaces.size() > 0) {
        try {
        cout << "Select a PizzaPlace " << endl;
        char input;
        cin >> input;
        _selectedDeliveryPlace = service.GetDeliveryPlace(input);
        }
        catch (InvalidDeliveryPlaceInput) {
            cout << "Oops, that delivery place does not exist! Try again" << endl;
        }
    }
    else if (allPlaces.size() == 0){
        cout << "No delivery places found, returning to main menu" << endl;
        return;
    }

}

