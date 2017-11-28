#include "Pizzasdadur.h"

Pizzasdadur::Pizzasdadur(){
    // Lesa úr skrá í pantanir fylkið
    _numOfOrders = 0;
    _pantanir = new Pontun[ _numOfOrders ];
    //þarf að vita hversumargar pantanir ég er að lesa úr
    //skránni þegar.
}
Pizzasdadur::~Pizzasdadur(){

    delete[] _pantanir;
}
void Pizzasdadur::createOrder(){
    _numOfOrders ++;
    cout << "By til pontun numer " << _numOfOrders << endl;
    Pontun newOrder;
    /// hér mindi ég svo skrifa pöntunina nyðrí skrá
    /// og á sama tima er ég að bæta henni aftast á arrayið mitt
    _pantanir = new Pontun[ _numOfOrders ];

    _pantanir[_numOfOrders - 1] = newOrder;
}
