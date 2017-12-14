#include "SalesUI.h"

SalesUI::SalesUI(){
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
             << "press 'q' to continue" << endl;
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
                try{
                cin >> input;
                Pizza pz = service.selectPizzaFromMenu( input );
                pz.tagPizzaToOrder( orderNo );
                service.CommitPizza(pz);
                }
                catch (invalidPizzaSelection){
                    cout << "Invalid pizza hotkey pleace enter correct pizza hotkey!!!";
                    system("PAUSE");
                }
                system("CLS");
        }
        else if(input == '2'){
            Pizza pz;
            cin >> pz;
            pz.tagPizzaToOrder( orderNo );
            system("CLS");
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
                    try{
                        Toppings tp = service.CharToTopping(input);
                        pz.addToppings( tp );
                    }
                    catch ( invalidToppingHotkey ){
                        system("CLS");
                        cout << "Pease enter a valid toppings hot-key !!!" << endl;
                    }
                    catch(toManyToppingsExeptions){
                        cout << "to many toppings on youre pizza system overload, cant handle pizza with so many toppings !!!! " << endl;
                        for(int i = 0; i < 40; i++){
                            cout << "ERROR !! ";
                        }
                        system("PAUSE");
                    }


            }
            service.CommitPizza( pz );
            system("CLS");
        }
        else if(input == '3'){

            vector<Products> products = service.ReturnAllProducts();
            for(unsigned int i = 0; i < products.size(); i++){
                cout << products[i] << endl;
            }
            cout << "Please select a product from the list above: ";
            char input;
            cin >> input;
            try{
                productOnFile prod = service.selectProduct(input);
                prod.tagProductToOrder( orderNo );
                service.commitProduct( prod );
            }
            catch(InvalidProductHotkey){
                cout << "InvalidProduct hotkey pleace enter a valid product";
                system("PAUSE");
            }
            system("CLS");
        }
        else {
            system("CLS");
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
    system("CLS");
    newOrder = service.computeTotalPrice(newOrder);
    PrintOrder(newOrder);

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
        cout << "Input the orderNumber " << endl;
        int orderNo;
        cin >> orderNo;
        system("CLS");
        PrintOrder( service.returnAOrder(orderNo));
    }
    catch (NoOrderToReturnExeption)
    {
        cout << "Order does not exist" << endl;
    }
}

void SalesUI::PrintOrder(Pontun order){
        cout << "--------------------------------------------" << endl;
        cout << order << endl;
        cout << "--------------------------------------------" << endl;
        vector<Pizza> pz = service.GetPizzaByOrderID(order.GetOrderNo());
        //ATH þetta virkar bara því ég er buin að commita pizzurnar og productinn
        for(unsigned int i = 0; i < pz.size(); i++){
            cout << pz[i] << endl;
            cout << "____" << endl;
        }
        cout << "--------------------------------------------" << endl;
        vector<productOnFile> prod = service.getProductByID(order.GetOrderNo());
        for(unsigned int i = 0; i < prod.size(); i++){
            cout << prod[i] << endl;
            cout << "____" << endl;
        }
        cout << endl << "--------------------------------------------" << endl;
}

void SalesUI::selectDeliveryPlace(){

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
        catch (InvalidDeliveryPlaceInput){
            cout << "Oops, that delivery place does not exist! Try again" << endl;
            return;
        }
    }
    else if (allPlaces.size() == 0){
       throw nothingInFile();
    }
}

