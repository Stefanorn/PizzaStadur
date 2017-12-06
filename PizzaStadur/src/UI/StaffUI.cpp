#include "StaffUI.h"

StaffUI::StaffUI(){
    while(true){
        cout << "Press 1 to pay for order, " << endl;
        cout << "press 2 to deliver order " << endl;
        cout << "press 3 to quit" << endl;
        char input;
        cin >> input;

        if(input == '1'){
            PayForOrder();
            system("CLS");
        }
        else if(input == '2'){

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
    vector<Pontun> orders = service.ReturnUnPayedOrders();

    for(unsigned int i = 0; i < orders.size(); i++){
        cout << orders[i];
    }
    int input;
    cin >> input;
      if(cin.fail()){
        cin.clear();
        cin.ignore();
      }
        if(service.PayForOrder(input)){
            cout << "Order number " << input << " Payed for press anykey to continue" << endl;
            cin >> input;
        }
        else{
            cout << "Faild to pay for order press anykey to continue" << endl;
            cin >> input;
        }
}

