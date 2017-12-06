#include "staffServices.h"

/*void staffServices::registerOrder( int orderID ){
    int* inputList = new int[_numOfOrders];
    for(int i = 0; i < _numOfOrders; i++ ){
            if(!_pantanir[i].hasBeenPayedFor()){
                cout << _pantanir[i];
                inputList[i] = _pantanir[i].GetPizzaNumber();
            }
            else{
                inputList[i] = -1;
            }
    }
    int index;

    cout << "select a order to pay for" << endl;
    cin >> index;
   /* if(inputCheck(index, *inputList )){
        _pantanir[ index - 1 ].payOrder();
    }
    else{
        cout << "Invalid Input" << endl;
    }

    delete[] inputList;
    if(!UpdateOrder()){
        cerr << "could not update database" << endl;
    }
}*/
void staffServices::deliverOrder( int orderID ){

}
