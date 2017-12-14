#include "SalesUI.h"

SalesUI::SalesUI()
{
    system("CLS");
    selectDeliveryPlace();
    system("CLS");

    while(true)
    {
        cout << "Press 1 to make a order " << endl;
        cout << "Press 2 to get info about your order " << endl;
        cout << "press 3 to go back to the main menu" << endl;
        char input;
        cin >> input;
        if(input == '1'){
            system("CLS");
            createOrder();
            system("PAUSE");
            system("CLS");
        }
        else if(input == '2') {
            system("CLS");
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
    system("CLS");
    int orderNo = service.OrderNumber();
    cout << "Making Order number " << orderNo << endl;
    Pontun newOrder(orderNo, _selectedDeliveryPlace);
    while(true)
        {
             cout << "Press '1' to select pizza from menu" << endl
             << "Press '2' to make new pizza" << endl
             << "Press '3' to add something else " << endl
             << "press 'q' to quit" << endl;
        char input;
        cin >> input;
        system("CLS");
        if(input == 'q'){
            break;
        }
        else if (input == '1'){
                vector<PizzaMenu> pzMenu = service.ReturnPizzaMenu();
                for(unsigned int i = 0; i < pzMenu.size(); i++){
                    cout << pzMenu[i] << endl << "-------------------------------" << endl;
                }
                cout << "Enter hot-key to select pizza from menu : ";
                char input;
                cin >> input;
                Pizza pz = service.selectPizzaFromMenu( input );
                pz.tagPizzaToOrder( orderNo );
                service.CommitPizza(pz);
                system("CLS");
        }
        else if(input == '2'){
            Pizza pz;
            cin >> pz;
            pz.tagPizzaToOrder( orderNo );
            cout << "Adding Toppings to your pizza " << endl;
            vector <ToppingsMenuItem> allToppings = service.GetToppingsMenu();
            while(true){
                    for(unsigned int i = 0; i < allToppings.size(); i++){
                        cout << allToppings[i];
                    }
                    cout << "Select Topping or press 'q' to quit: " << endl;
                    cin >> input;
                    if(input == 'q'){
                        break;
                    }
                    cout << "Adding topping to pizza" << endl;
                    Toppings tp = service.CharToTopping(input);
                    pz.addToppings( tp );

            }
            service.CommitPizza( pz );
        }
        else if(input == '3'){


            vector<Products> products = service.ReturnAllProducts();
            for(unsigned int i = 0; i < products.size(); i++){
                cout << products[i] << endl;
            }
            cout << "Please select a product from the list above: ";
            char input;
            cin >> input;
            productOnFile prod = service.selectProduct(input);
            prod.tagProductToOrder( orderNo );
            service.commitProduct( prod );

        }
        else {
            cout << "Invalid Input " << endl;
        }
    }
    cout << "Delivery or pick-up (d/p)? ";
    char input;
    cin >> input;
    while(true){
        if(input == 'd' || input == 'p'){
            newOrder = service.DeliveredOrPickedUp(newOrder, input);
            break;
        }
        else{
            cout << "Just press 'd' or 'p', PLEASE!" << endl; ;
            cin >> input;
        }
    }
    cout << "Press y to confirm your order: ";
    cin >> input;
    if(input == 'y'){
        service.CommitOrder(newOrder);
        cout << "Your order is being processed" << endl;
    }
    else{
        cout << "Order was aborted!" << endl;
    }
}

void SalesUI::GetInfoAboutOrder(){
    system("CLS");
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
    cout << "Select a PizzaPlace " << endl;
    char input;
    cin >> input;

    _selectedDeliveryPlace = service.GetDeliveryPlace(input);

}

