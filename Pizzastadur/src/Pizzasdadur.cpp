#include "Pizzasdadur.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Pizzasdadur::Pizzasdadur(){

    ifstream stream;
    stream.open( "Orders.bin" );

    if(stream.is_open() ){

        stream.seekg(0,stream.end);
        int _numOfOrders = stream.tellg() / sizeof( Pontun );
        stream.seekg(0, stream.beg);
    }
    else{
        _numOfOrders = 0;
        cerr << "Could not find orders.bin";
    }

    _pantanir = new Pontun[ _numOfOrders ];


    //�arf a� vita hversumargar pantanir �g er a� lesa �r
    //skr�nni �egar.
}
Pizzasdadur::~Pizzasdadur(){

    delete[] _pantanir;
}
void Pizzasdadur::createOrder(){
    _numOfOrders ++;
    cout << "Making order no " << _numOfOrders << endl;
    Pontun newOrder;
    /// h�r mindi �g svo skrifa p�ntunina ny�r� skr�
    /// og � sama tima er �g a� b�ta henni aftast � arrayi� mitt
    _pantanir = new Pontun[ _numOfOrders ];

    _pantanir[_numOfOrders - 1] = newOrder;
}
