#include "Pizzasdadur.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Pizzasdadur::Pizzasdadur(){

    ifstream stream;
    stream.open( "Orders.bin", ios::binary );


    if(stream.is_open() ){

        stream.seekg(0,stream.end);
        int length = stream.tellg() / sizeof(Pontun);
        stream.seekg(0, stream.beg);
        _numOfOrders = length;
    }
    else{
        _numOfOrders = 0;
        cerr << "Could not find orders.bin" << endl;
    }

    _pantanir = new Pontun[ _numOfOrders ];

    stream.read((char*)(&_pantanir), sizeof(Pontun) * _numOfOrders);

}
Pizzasdadur::~Pizzasdadur(){

    delete[] _pantanir;
}
void Pizzasdadur::createOrder(){

    _numOfOrders ++;
    cout << "Making order no " << _numOfOrders << endl;
    Pontun newOrder;

    //Skrifa pöntunina í _pantanir array listann minn
    _pantanir = new Pontun[ _numOfOrders ];
    _pantanir[_numOfOrders - 1] = newOrder;

    //Skrifa pöntunina í skrá hér
    ofstream stream;
    stream.open("orders.bin", ios::binary|ios::app);
    stream.write((char*)(&newOrder), sizeof(Pontun));

}
