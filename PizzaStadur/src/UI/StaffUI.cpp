#include "StaffUI.h"

StaffUI::StaffUI(){
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
        cout << "Well Done! All orders have been delivered!" << endl;
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

