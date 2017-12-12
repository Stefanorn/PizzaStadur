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

    cout << "Enter name of delivery place : " ;
    in >> places._name;
    cout << "Enter hotkey for your place  : ";
    in >> places._hotkey;
    return in;
}

ostream& operator << (ostream& out, const DeliveryPlaces& places)
{
    out << "To deliver to " << places._name ;
    out << " Press '"  << places._hotkey << "'" << endl;
    return out;

}

bool operator == ( const DeliveryPlaces& leftSide, const DeliveryPlaces& rightSide ){
    if( leftSide._hotkey == rightSide._hotkey ){
        return true;
    }
    return false;
}
