#include "Pizzasdadur.h"

Pizzasdadur::Pizzasdadur(){
    // Lesa �r skr� � pantanir fylki�
    _numOfOrders = 0;
    _pantanir = new Pontun[ _numOfOrders ];
    //�arf a� vita hversumargar pantanir �g er a� lesa �r
    //skr�nni �egar.
}
Pizzasdadur::~Pizzasdadur(){

    delete[] _pantanir;
}
void Pizzasdadur::createOrder(){
    _numOfOrders ++;
    cout << "By til pontun numer " << _numOfOrders << endl;
    Pontun newOrder;
    /// h�r mindi �g svo skrifa p�ntunina ny�r� skr�
    /// og � sama tima er �g a� b�ta henni aftast � arrayi� mitt
    _pantanir = new Pontun[ _numOfOrders ];

    _pantanir[_numOfOrders - 1] = newOrder;
}
