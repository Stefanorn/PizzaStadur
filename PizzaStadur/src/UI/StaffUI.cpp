#include "StaffUI.h"

StaffUI::StaffUI(){
    system("CLS");

    selectDeliveryPlace();

    while(true){
        cout << "Press 1 to pay for an order, " << endl;
        cout << "press 2 to deliver an order " << endl;
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
            cout << "Oops, that's not the right command! " << endl;
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
    cout << endl << "---------------------------------------------" << endl;
    cout << "Select an order to pay for" << endl;
    int input;
    cin >> input;
    try {
        if(service.PayForOrder(input)){
            cout << "Order number " << input << " paid" << endl;
            system("pause");
        }
    }
    catch (NoOrderToReturnExeption) {
        cout << "Hmm, that order doesn't exist, please try again" << endl;
        system("PAUSE");
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
    cout << endl <<"---------------------------------------------" << endl;
    cout << "Select an order to deliver " << endl;

    try {
        int input;
        cin >> input;
       Pontun order = service.DeliverOrder(input);

        if( order.returnIsDelivered() ){
            cout << "Order number " << input << " has been delivered" << endl;
            }
            else{
                cout << "Order number " << input << " has been picked up" << endl;
            }
        system("PAUSE");
    }
    catch (NoOrderToReturnExeption) {
        cout << "Hmm, that order doesn't exist, please try again" << endl;
        system("PAUSE");
    }
}


void StaffUI::selectDeliveryPlace(){

    vector<DeliveryPlaces> allPlaces = service.GetAllPlaces();
    for(unsigned int i = 0; i < allPlaces.size(); i++){

        cout << allPlaces[i];
    }
    if (allPlaces.size() > 0) {
        cout << "Select a pizza place " << endl;
        char input;
        cin >> input;
        _selectedDeliveryPlace = service.GetDeliveryPlace(input);
    }
    else if (allPlaces.size() == 0){
        throw nothingInFile();
    }

}

