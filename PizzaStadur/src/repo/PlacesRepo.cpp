#include "PlacesRepo.h"

PlacesRepo::PlacesRepo()
{
    _readFile();
}

void PlacesRepo::_readFile(){

    ifstream fin;
    fin.open("Places.bin", ios::binary);

    if(fin.is_open() ){
        fin.seekg(0, fin.end);
        int size = fin.tellg() / sizeof(Pontun);
        fin.seekg(0, fin.beg);

        DeliveryPlaces temp;
        for(int i = 0; i < size; i++){
            fin.read((char*)(&temp), sizeof(DeliveryPlaces));
            _places.push_back(temp);
        }
    }
    else{
        cout << "Creating file places.bin" << endl;
    }
    fin.close();
}

void PlacesRepo::overWriteFile( vector<DeliveryPlaces> places){
    ofstream fout;

    fout.open("places.bin", ios::binary);
    if(fout.is_open()){
        fout.seekp(fout.beg);
        for(unsigned int i = 0; i < _places.size(); i++){
            fout.write((char*)(&places[i]), sizeof(DeliveryPlaces));
        }
    }
    else{
        cerr << "Unable to read file" << endl;
    }

    fout.close();
    _places = places;
}

void PlacesRepo::addPlaces(vector<DeliveryPlaces> places, int size){

    ofstream fout;
    fout.open("places.bin", ios::binary|ios::app);
    fout.write((char*)(&places), sizeof(DeliveryPlaces));
    _places.reserve(_places.size() + places.size());
    _places.insert(_places.end(), places.begin(), places.end());
    places.clear();
    fout.close();
}

vector<DeliveryPlaces> PlacesRepo::ReturnAllPlaces()
{
    return _places;
}
