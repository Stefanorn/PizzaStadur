#include "orderRepo.h"

orderRepo::orderRepo(){
    ReadFromFile();
}

void orderRepo::ReadFromFile(){

    ifstream stream;
    stream.open( "Orders.bin", ios::binary );

    if(stream.is_open() ){
        stream.seekg(0,stream.end);
        int length = stream.tellg() / sizeof(Pontun);
        stream.seekg(0, stream.beg);

        cout << "Reading " << length << " orders" << endl;

        Pontun temp;
        for(int i = 0; i < length; i++){
            stream.read((char*)(&temp), sizeof(Pontun));
            _orders[i] = temp;
        }
    }
    else{
        cerr << "Could not find orders.bin" << endl;
    }

   // _pantanir = new Pontun[ _numOfOrders ];
   // Þegar ég geri new þá fæ ég nýan pointer þarf þá að afrita allt af gamla arrayinum yfir á nýa

    stream.close();
}
void orderRepo::UpdateOrder( vector<Pontun> orders ){

    ofstream stream;

    stream.open("orders.bin", ios::binary);
    if(stream.is_open()){
        stream.seekp( stream.beg );
        for(int i = 0; i < _orders.size(); i++){
            stream.write((char*)(&_orders[i]), sizeof(Pontun));
        }
    }

    stream.close();
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
void orderRepo::WriteOrderToFile( Pontun orderToWrite ){

    ofstream stream;
    stream.open("orders.bin", ios::binary|ios::app);
    stream.write((char*)(&orderToWrite), sizeof(Pontun));
    stream.close();

}

vector<Pontun> orderRepo::ReturnOrders( bool hasBeenPayedFor,
                                        bool hasBeenDelivired,
                                        bool isReddy){
        vector<Pontun> ordersToReturn;
        for(unsigned int i = 0; i < _orders.size(); i++ ){
        //    if(hasBeenPayedFor == _orders[i].)
        }



}
