#include "PizzaMenuRepo.h"

PizzaMenuRepo::PizzaMenuRepo()
{
    ReadFromFile();
}


void PizzaMenuRepo::ReadFromFile(){

    ifstream stream;
    stream.open( "PizzMenuItems.bin", ios::binary );

    if(stream.is_open() ){
        stream.seekg(0,stream.end);
        int length = stream.tellg() / sizeof(PizzaMenu);
        stream.seekg(0, stream.beg);

        cout << "Reading " << length << " PizzMenuItems" << endl;

        PizzaMenu temp;
        for(int i = 0; i < length; i++){
            stream.read((char*)(&temp), sizeof(PizzaMenu));
            _menuItem.push_back(temp);
        }
    }
    else{
        cerr << "Could not find PizzMenuItems.bin" << endl;
    }

   // _pantanir = new Pontun[ _numOfOrders ];
   // Þegar ég geri new þá fæ ég nýan pointer þarf þá að afrita allt af gamla arrayinum yfir á nýa

    stream.close();
}
void PizzaMenuRepo::RewriteFile( vector<PizzaMenu> menuItem ){
    ofstream stream;

    stream.open("PizzMenuItems.bin", ios::binary);
    if(stream.is_open()){
        stream.seekp( stream.beg );
        for(unsigned int i = 0; i < _menuItem.size(); i++){
            stream.write((char*)(&menuItem[i]), sizeof(PizzaMenu));
        }
        stream.close();
    }
    _menuItem = menuItem;
}
void PizzaMenuRepo::WriteToFile( PizzaMenu itemToWrite ){

    ofstream stream;
    stream.open("PizzMenuItems.bin", ios::binary|ios::app);
    stream.write((char*)(&itemToWrite), sizeof(PizzaMenu));
    stream.close();

    _menuItem.push_back(itemToWrite);
}

vector<PizzaMenu> PizzaMenuRepo::ReturnAllPizzaMenu(){
    return _menuItem;
}
