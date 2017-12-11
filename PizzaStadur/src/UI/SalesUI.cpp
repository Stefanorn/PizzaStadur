#include "SalesUI.h"

SalesUI::SalesUI()
{

    while(true){
        cout << "Press 1 to make a order " << endl;
        cout << "Press 2 to get info about your order " << endl;
        cout << "press 3 to go back to the main menu" << endl;
        char input;
        cin >> input;

        if(input == '1'){

            int orderNo = service.OrderNumber();
            cout << "Making Order number " << orderNo << endl;
            Pontun newOrder(orderNo);
            cout << "Enter a delivery place " << endl;
            cin >> newOrder;
            while(true){
                cout << "Do you want to add a pizza to your order (y/n)?" << endl;
                char input;
                cin >> input;
                if(input == 'y'){
                    //cout << "Here's the menu! Select a pizza from the menu or create your own";
                    Pizza pz;
                    cin >> pz;
                    pz.tagPizzaToOrder( orderNo );
                    service.CommitPizza( pz );
                    //cout << "Comments: " << endl;
                    //cin >> comments;
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
            vector<Pizza> pz = service.GetPizzaByOrderID(orderNo);
            for(unsigned int i = 0; i < pz.size(); i++){
                cout << pz[i];
            }
            //service.GetOrderPrice();
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
