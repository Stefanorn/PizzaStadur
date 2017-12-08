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
            while(true){
                cout << "Do you whant to add pizza to order y/n" << endl;
                char input;
                cin >> input;
                if(input == 'y'){
                    Pizza pz;
                    cin >> pz;
                    pz.tagPizzaToOrder( orderNo );

                }
                else if (input == 'n'){
                    break;
                }
                else{
                    cout << "Invalid Input " << endl;
                }
            }
            service.CommitOrder(newOrder);
            system("CLS");
        }
        else if(input == '2'){
            cout << "input the orderNumber " << endl;
            int orderNo;
            cin >> orderNo;
            cout << "Printing order no " << orderNo << endl;
            cout << service.returnAOrder(orderNo) ;
            system("PAUSE");
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
