#include <iostream>
#include "Pizzasdadur.h"

using namespace std;

int main()
{
    Pizzasdadur pizzaPlace;
    cout << "Welcome to internet Pizza place" << endl;

    while(true){
        char userInput;
        cout << "Press 1 to make order, q to quit " << endl;
        cin >> userInput;

        switch (userInput){
        case '1':
            pizzaPlace.createOrder();
            break;
        case 'q':
            return 0;
            break;
        default:
            cout <<"ologlet innput" << endl;
            break;

        };

    }
}
