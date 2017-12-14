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
            _orders.push_back(temp);
        }
    }
    else{
        cerr << "Could not find orders.bin" << endl;
    }

    stream.close();
}
void orderRepo::RewriteFile( vector<Pontun> orders ){
    ofstream stream;

    stream.open("orders.bin", ios::binary);
    if(stream.is_open()){
        stream.seekp( stream.beg );
        for(unsigned int i = 0; i < orders.size(); i++){
            stream.write((char*)(&orders[i]), sizeof(Pontun));
        }
        stream.close();
    }
    _orders = orders;
}
void orderRepo::WriteOrderToFile( Pontun orderToWrite ){

    ofstream stream;
    stream.open("orders.bin", ios::binary|ios::app);
    stream.write((char*)(&orderToWrite), sizeof(Pontun));
    stream.close();

    _orders.push_back(orderToWrite);
}

int orderRepo::getOrderNo(){

    return _orders.size() + 1;

}
vector<Pontun> orderRepo::ReturnAllOrders(){
    return _orders;
}
