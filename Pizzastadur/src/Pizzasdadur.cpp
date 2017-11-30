#include "Pizzasdadur.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/// PUBLIC FÖLL
Pizzasdadur::Pizzasdadur(){

    cout << "Reading orders from file " << endl;
    ReadFromFile();
    cout << "Reddy to go" << endl;

}
Pizzasdadur::~Pizzasdadur(){

    delete[] _pantanir;
}

void Pizzasdadur::createOrder(){

    _numOfOrders ++;
    cout << "Making order no " << _numOfOrders << endl;
    Pontun newOrder( _numOfOrders );

    //Skrifa pöntunina í _pantanir array listann minn
    // Þegar ég geri new þá fæ ég nýan pointer þarf þá að afrita allt af gamla arrayinum yfir á nýa
    _pantanir[_numOfOrders - 1] = newOrder;

    //Skrifa pöntunina í skrá hér
    WriteOrderToFile( newOrder );

}
void Pizzasdadur::payForOrder(){
    for(int i = 0; i < _numOfOrders; i++ ){
            if(!_pantanir[i].hasBeenPayedFor()){
                cout << _pantanir[i];
            }
    }
    int index;
    cout << "select a order to pay for" << endl;
    cin >> index;
    _pantanir[ index - 1 ].payOrder();

    if(!UpdateOrder(index)){
        cerr << "could not update database" << endl;
    }
}
void Pizzasdadur::printAllOrders(){

    cout << "printing " << _numOfOrders << endl;

    for(int i = 0; i < _numOfOrders; i++){
        cout << _pantanir[i];
    }

}
void Pizzasdadur::bakePizza(){
    if(_numOfOrders < 1){
        cout << "No order has been made!" << endl;
        return;
    }
    for(int i = 0; i < _numOfOrders; i++){
        if(!_pantanir[i].hasBeenBaked())
            cout << _pantanir[i];
    }
    int index = 0;
    bool valid_input = false;
    while(valid_input == false){
        cout << "Select order to bake " << endl;
        cin >> index;
        /*if(cin.fail()){
            cout << "Invalid input" << endl;
        }*/
        if(index < 1 || index > _numOfOrders){
            cout << "Invalid input" << endl;
        }
        else{
            valid_input = true;
        }
    }
    cout << "Baking order no " << index << endl;
    _pantanir[index - 1].bakePizza();
    cout << "Pizza has been baked. Order no " << index << " is ready" << endl;

    UpdateOrder(index);
}


/// PRIVATE FOLL
void Pizzasdadur::ReadFromFile(){

    ifstream stream;
    stream.open( "Orders.bin", ios::binary );

    if(stream.is_open() ){
        stream.seekg(0,stream.end);
        int length = stream.tellg() / sizeof(Pontun);
        stream.seekg(0, stream.beg);

        cout << "Reading " << length << " orders" << endl;

        Pontun temp;
        for(int i = 0; i < length; i++){
            stream.read((char*)(&temp), sizeof(Pontun));
            _pantanir[i] = temp;
        }
        _numOfOrders = length;
    }
    else{
        _numOfOrders = 0;
        cerr << "Could not find orders.bin" << endl;
    }

   // _pantanir = new Pontun[ _numOfOrders ];
   // Þegar ég geri new þá fæ ég nýan pointer þarf þá að afrita allt af gamla arrayinum yfir á nýa

    stream.close();
}
bool Pizzasdadur::UpdateOrder(int orderNo){
    return false;
}
void Pizzasdadur::WriteOrderToFile( Pontun orderToWrite ){

    ofstream stream;
    stream.open("orders.bin", ios::binary|ios::app);
    stream.write((char*)(&orderToWrite), sizeof(Pontun));
    stream.close();
}

