#include "DeliveryPlaces.h"

DeliveryPlaces::DeliveryPlaces()
{
    _name[0] = '\0';
}

string DeliveryPlaces::getName()
{
    return _name;
}

istream& operator >> (istream& in, DeliveryPlaces& places)
{
    //cout << "Please enter the delivery place(s) to add:" << endl;
    in >> places._name;
    return in;
}

ostream& operator << (ostream& out, const DeliveryPlaces& places)
{
    out << places._name << endl;
    return out;
}
