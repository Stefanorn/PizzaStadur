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
            cout << "Making Order number " << orderNo + 1 << endl;
            Pontun newOrder(orderNo);
            cout << "Enter a delivery place " << endl;
            cin >> newOrder;
            while(true){
                cout << "Do you want to add pizza to order y/n" << endl;
                char input;
                cin >> input;
                if(input == 'y'){
                    Pizza pz;
                    cin >> pz;
                    pz.tagPizzaToOrder( orderNo );
                    service.CommitPizza(pz);

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
