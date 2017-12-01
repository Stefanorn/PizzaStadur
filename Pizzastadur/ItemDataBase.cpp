#include "ItemDataBase.h"
#include <fstream>
#include <iostream>
#include <string>
ItemDataBase::ItemDataBase()
{
    //ctor
}

ItemDataBase::~ItemDataBase()
{
    //dtor
}



///Private Breyutr
void ItemDataBase::ReadFromFile(){

    ifstream stream;
    stream.open( "items.bin", ios::binary );

    if(stream.is_open() ){
        stream.seekg(0,stream.end);
        int length = stream.tellg() / sizeof(Pizza);
        stream.seekg(0, stream.beg);

        cout << "Reading " << length << " Items" << endl;

        Pizza temp;
        for(int i = 0; i < length; i++){
            stream.read((char*)(&temp), sizeof(Pizza));
            _item.push_back(temp);
        }
    }
    else{
        cerr << "Could not find items.bin" << endl;
    }

   // _pantanir = new Pontun[ _numOfOrders ];
   // Þegar ég geri new þá fæ ég nýan pointer þarf þá að afrita allt af gamla arrayinum yfir á nýa

    stream.close();
}
bool ItemDataBase::UpdateOrder(){

    ofstream stream;

    stream.open("items.bin", ios::binary);
    if(stream.is_open()){
        stream.seekp( stream.beg );
        for(int i = 0; i < _item.size(); i++){
            stream.write((char*)(&_item[i]), sizeof(Pizza));
        }


        stream.close();
        return true;
    }

    stream.close();
    return false;
  /*
    Finna hvar færslan er í skránni og yfir rita hana

    þarf þá að taka inn
    int orderNo, Pontun newOrder
    ofstream stream;
    stream.open("orders.bin", ios::binary|ios::app );
    if(stream.is_open()){

        stream.seekp(stream.beg);
        stream.seekp(sizeof(Pontun) * orderNo );
        stream.write((char*)(&newOrder), sizeof(Pontun));
        stream.close();
        return true;
    }
    stream.close();
    return false;*/
}
void ItemDataBase::WriteOrderToFile( Pizza itemToWrite ){

    ofstream stream;
    stream.open("items.bin", ios::binary|ios::app);
    stream.write((char*)(&itemToWrite), sizeof(Pizza));
    stream.close();

}
