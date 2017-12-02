#include <iostream>
#include "Pizzasdadur.h"

using namespace std;

int main()
{
    Pizzasdadur pizzaPlace;
    cout << "Welcome to n33rdy Pizza place" << endl;

    while(true){
        char userInput;
        cout << "Press 1 to make order, \n2 to print all orders, \n3 to pay for order, \n4 to bake a pizza, \n5 to add item to database \nq to quit " << endl;
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
        case '4':
            pizzaPlace.bakePizza();
            break;
        case '5':
            pizzaPlace.addItemToDataBase();
            break;
        case 'q':
            return 0;
            break;
        default:
            cout <<"Invalid input" << endl;
            break;
        }

    }
}
