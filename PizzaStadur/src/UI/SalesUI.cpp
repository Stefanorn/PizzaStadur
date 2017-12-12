#include "SalesUI.h"

SalesUI::SalesUI()
{

    selectDeliveryPlace();

    while(true)
    {
        cout << "Press 1 to make a order " << endl;
        cout << "Press 2 to get info about your order " << endl;
        cout << "press 3 to go back to the main menu" << endl;
        char input;
        cin >> input;
        if(input == '1'){
            createOrder();
            system("PAUSE");
            system("CLS");
        }
        else if(input == '2') {
            GetInfoAboutOrder();
            system("PAUSE");
            system("CLS");
        }
        else if (input == '3'){
            system("CLS");
            return;
        }
        else {
            cout << "Invalid input " << endl;
            system("PAUSE");
            system("CLS");
        }
    }
}

void SalesUI::createOrder(){

    int orderNo = service.OrderNumber();
    cout << "Making Order number " << orderNo << endl;
    Pontun newOrder(orderNo, _selectedDeliveryPlace);
    cout << "Enter a delivery place " << endl;
    cin >> newOrder;
    while(true)
        {
        cout << "Do you want to add pizza to order y/n" << endl;
        char input;
        cin >> input;
        if(input == 'y'){
            Pizza pz;
            cin >> pz;
            pz.tagPizzaToOrder( orderNo );
            service.CommitPizza( pz );
            cout << "Adding Toppings to your pizza " << endl;
            vector <ToppingsMenuItem> allToppings = service.GetToppingsMenu();
            while(true){
                cout << "Do you whant to add more toppings 'y' to add more topping 'n' to quit " << endl;
                cin >> input;
                if(input == 'y'){

                    for(unsigned int i = 0; i < allToppings.size(); i++){
                        cout << allToppings[i];
                    }
                    cout << "Select Toping :" << endl;
                    cin >> input;
                    service.addToppingToPizza( input );
                }
                else if( input == 'n'){
                    break;
                }
                else{
                    cout << "Invalid input " << endl;
                }
            }
        }
        else if (input == 'n') {
            break;
        }
        else {
            cout << "Invalid Input " << endl;
        }
    }
    service.CommitOrder(newOrder);
}

void SalesUI::GetInfoAboutOrder(){
    try
    {
        cout << "input the orderNumber " << endl;
        int orderNo;
        cin >> orderNo;
        cout << "Printing order no " << orderNo << endl;
        cout << service.returnAOrder(orderNo) ;
        vector<Pizza> pz = service.GetPizzaByOrderID(orderNo);
        for(unsigned int i = 0; i < pz.size(); i++){
            cout << pz[i];
            vector<Toppings> tp = service.getToppingsByPizzaID( orderNo );
            for(unsigned int j = 0; j < tp.size(); j++){
                cout << tp[j];
            }
        }
        //service.GetOrderPrice();
    }
    catch (NoOrderToReturnExeption)
    {
        cout << "Order does not exist" << endl;
    }
}

void SalesUI::selectDeliveryPlace(){

    vector<DeliveryPlaces> allPlaces = service.GetAllPlaces();
    for(unsigned int i = 0; i < allPlaces.size(); i++){

        cout << allPlaces[i];
    }
    cout << "Select a PizzaPlace" << endl;
    char input;
    cin >> input;

    _selectedDeliveryPlace = service.GetDeleveryPlace(input);

}

