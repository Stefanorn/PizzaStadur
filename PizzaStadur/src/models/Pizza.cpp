#include "Pizza.h"

Pizza::Pizza(){
    _pizzaPrice = 0;
    _toppingIndex = 0;
    _orderIdNumber = -1;
    _pizzaID = -1;
    _base = REGULAR;
    _size = SMALL;
    _basePrice = 0;
    _sizePrice = 0;
}
Pizza::Pizza( pizzaBase base, pizzaSize size, double price){
    _toppingIndex = 0;
    _orderIdNumber = -1;
    _pizzaID = -1;
    _base = base;
    _size = size;
    _pizzaPrice = price;
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
    outs << "Base : ";
    if(pizza._base == 1){
        outs << "Regular" << endl;
    }

    else if(pizza._base == 2){
        outs << " Thin" << endl;
    }

    else if(pizza._base == 3){
        outs << " Pan" << endl;
    }

    else if(pizza._base == 4){
        outs << " Spelt" << endl;
    }

    outs << "Size : ";
    if(pizza._size == 1){
        outs << "Small" << endl;
    }

    else if(pizza._size == 2){
        outs << "Medium" << endl;
    }

    else if(pizza._size == 3){
        outs << "Large" << endl;
    }

    outs << "Price: " << pizza.getPrice() << " kr." << endl;
    outs << endl << "Toppings: " << endl;
    for(int i = 0; i < pizza._toppingIndex; i++){
        outs << "\t"<< pizza._toppingsOnPizza[i];
    }
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
    _pizzaPrice = price;
}

double Pizza::getPrice() const{

    if( _pizzaPrice ){
        return _pizzaPrice;
    }

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
    for(int i = 0; i < _toppingIndex; i++){
        total += _toppingsOnPizza[i].getToppingPrice();
    }

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
