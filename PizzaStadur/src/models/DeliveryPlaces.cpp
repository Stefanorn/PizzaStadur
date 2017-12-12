#include "DeliveryPlaces.h"

DeliveryPlaces::DeliveryPlaces()
{
    _name[0] = '\0';
}

string DeliveryPlaces::getName()
{
    return _name;
}
char DeliveryPlaces::GetKey(){
    return _hotkey;
}

istream& operator >> (istream& in, DeliveryPlaces& places){

    //cout << "Please enter the delivery place(s) to add:" << endl;
    in >> places._name;
    in >> places._hotkey;
    return in;
}

ostream& operator << (ostream& out, const DeliveryPlaces& places)
{
    out << "To deliver to" << places._name ;
    out << " Press '"  << places._hotkey << "'" << endl;
    return out;

}
