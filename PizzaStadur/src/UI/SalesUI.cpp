#include "SalesUI.h"

SalesUI::SalesUI()
{

    while(true){
        cout << "Press 1 to make a order " << endl;
        cout << "Press 2 to get info about your order " << endl;
        cout << "press 3 to quit" << endl;
        char input;
        cin >> input;

        if(input == '1'){

            int orderNo = service.OrderNumber();
            cout << "Making Order number " << orderNo << endl;
            Pontun newOrder(orderNo);
            cout << "Enter a delivery Place " << endl;
            cin >> newOrder;
            service.CommitOrder(newOrder);
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
