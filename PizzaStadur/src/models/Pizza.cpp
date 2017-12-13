#include "Pizza.h"

Pizza::Pizza(){
    _toppingIndex = 0;
    _orderIdNumber = -1;
    _pizzaID = -1;
    _base = REGULAR;
    _size = SMALL;
    _basePrice = 0;
    _sizePrice = 0;
}

istream& operator >> (istream& ins, Pizza& pizza){
    bool base = false, pSize = false;

    char input;

    while (base == false)
    {
        cout << "Enter base type: " << endl;
        cout << "Press 1 for Regular" << endl;
        cout << "Press 2 for Thin" << endl;
        cout << "Press 3 for Pan" << endl;
        cout << "Press 4 for Spelt" << endl;
        ins >> input;
        try
        {
            switch (input){
                case '1': pizza._base = REGULAR; base = true; break;
                case '2': pizza._base = THIN; base = true; break;
                case '3': pizza._base = PAN; base = true; break;
                case '4': pizza._base = SPELT; base = true; break;
            }
        }
        catch (invalidBaseIndex)
        {
            cout << "Invalid input" << endl;
            base = false;
        }
    }

    while (pSize == false)
    {
        cout << "Enter size of pizza: " << endl;
        cout << "Press 1 for small" << endl;
        cout << "Press 2 for medium" << endl;
        cout << "Press 3 for large" << endl;
        ins >> input;
        try
        {
            switch (input){
                case '1': pizza._size = SMALL; pSize = true; break;
                case '2': pizza._size = MEDIUM; pSize = true; break;
                case '3': pizza._size = LARGE; pSize = true; break;
            }
        }
        catch (invalidSizeIndex)
        {
            cout << "Invalid input" << endl;
            pSize = false;
        }
    }

    return ins;
}

ostream& operator << (ostream& outs, const Pizza& pizza){
    outs << "ID   : " << pizza._pizzaID << endl;
    outs << "Base : " << pizza._base << endl;
    outs << "Size : " << pizza._size << endl;
    outs << "Price: " << pizza.getPrice() << " kr." << endl;
    outs << "Toppings \n ----------------------";
    for(int i = 0; i < pizza._toppingIndex; i++){
        outs << pizza._toppingsOnPizza[i];
    }
    outs << "--------------------------"<< endl;
    return outs;
}

void Pizza::tagPizzaToOrder(int orderNo){
    _orderIdNumber = orderNo;
}

int Pizza::getPizzaToOrderId(){
    return _orderIdNumber;
}

void Pizza::setPizzaID(int id){
     _pizzaID = id;
}

int Pizza::getPizzaID(){
    return _pizzaID;
}

void Pizza::setBasePrice(double price){
    if(_base == 1){
        _basePrice = price;
    }
}

void Pizza::setSizePrice(double price){

}

double Pizza::getPrice() const{
    double total = 0;
    //if (pizza name er valid){
        if (_base == 1){
            total += 500;
        }
        else if (_base == 2){
            total += 1000;
        }
        else if (_base == 3){
            total += 1500;
        }
        else if (_base == 4){
            total += 900;
        }
        else{
            //throw SomeException;
        }

        if (_size == 1){
            total += 200;
        }
        else if (_size == 2){
            total += 400;
        }
        else if (_size == 3){
            total += 600;
        }
        else{
            //throw SomeException;
        }


    //}

    return total;
}

void Pizza::bakePizza(){
    _isPizzaBaked = true;
}

bool Pizza::isPizzaBaked(){
    return _isPizzaBaked;
}

void Pizza::addToppings(Toppings topping){
    if(_toppingIndex > 15){
        throw toManyToppingsExeptions();
    }
    _toppingsOnPizza[_toppingIndex] = topping;
    _toppingIndex++;
}
