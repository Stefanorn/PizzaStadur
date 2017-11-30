#include "Pontun.h"

Pontun::Pontun(int pizzaNumber)
{
//    cin >> _pizza;
    _pizzaNumber = pizzaNumber;
    _hasBeenPayedFor = false;
    _hasBeenBaked = false;
    _hasBeenDelevired = false;
    _isReddy = false;

}
Pontun::Pontun()
{
//    cin >> _pizza;
    _pizzaNumber = -1;
    _hasBeenPayedFor = false;
    _hasBeenBaked = false;
    _hasBeenDelevired = false;
    _isReddy = false;
}

//Viðskiptavinurinn borgar fyrir pizzuna
bool Pontun::hasBeenPayedFor(){
    return _hasBeenPayedFor;
}
void Pontun::payOrder(){
    _hasBeenPayedFor = true;
}

//Bakarinn bakar pizzuna
bool Pontun::hasBeenBaked(){
    return _hasBeenBaked;
}
void Pontun::bakePizza(){

    _hasBeenBaked = true;
}

//Pizzan er reddy þegar hún er bokuð og búið að borga
bool Pontun::isPizzaReddy(){
    return _isReddy;

}
void Pontun::makePizzaReddy(){
    _isReddy = true;
}

// Það er bara hægt að delevera pizzur sem eru borgaðar
// og bakaðar
bool Pontun::isPizzaDeleverd(){
    return _hasBeenDelevired;
}
void Pontun::deleverPizza(){
    _hasBeenDelevired = true;
}



ostream& operator << (ostream& out, const Pontun& pontun){

    out << "pizza no " << pontun._pizzaNumber << endl;
    //out << pontun._pizza;
    out << "has been payed for " << pontun._hasBeenPayedFor << endl;
    out << "has been baked " << pontun._hasBeenBaked << endl;
    out << "has been deleveried " << pontun._hasBeenDelevired << endl;

    return out;
}
