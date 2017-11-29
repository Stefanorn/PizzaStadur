#include <iostream>
#include "Pizzasdadur.h"

using namespace std;

int main()
{
    Pizzasdadur pizzaPlace;
    cout << "Welcome to n33rdy Pizza place" << endl;

    while(true){
        char userInput;
        cout << "Press 1 to make order, 2 to print all orders, 3 to pay for order, q to quit " << endl;
        cin >> userInput;

        switch (userInput){
        case '1':
            pizzaPlace.createOrder();
            break;
        case '2':
            pizzaPlace.printAllOrders();
            break;
        case '3':
            pizzaPlace.payForOrder();
            break;
        case 'q':
            return 0;
            break;
        default:
            cout <<"Invalid innput" << endl;
            break;
        }

    }
}
