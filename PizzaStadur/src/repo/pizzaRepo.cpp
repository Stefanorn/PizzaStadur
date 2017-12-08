#include "pizzaRepo.h"


pizzaRepo::pizzaRepo(){
    ReadFromFile();
}

void pizzaRepo::ReadFromFile(){

    ifstream stream;
    stream.open( "pizza.bin", ios::binary );

    if(stream.is_open() ){
        stream.seekg(0,stream.end);
        int length = stream.tellg() / sizeof(Pizza);
        stream.seekg(0, stream.beg);

        cout << "Reading " << length << " pizzas" << endl;

        Pizza temp;
        for(int i = 0; i < length; i++){
            stream.read((char*)(&temp), sizeof(Pizza));
            _pizzas.push_back(temp);
        }
    }
    else{
        cerr << "Could not find pizza.bin" << endl;
    }

    stream.close();
}
void pizzaRepo::RewriteFile( vector<Pizza> pizzas ){
    ofstream stream;

    stream.open("pizza.bin", ios::binary);
    if(stream.is_open()){
        stream.seekp( stream.beg );
        for(unsigned int i = 0; i < pizzas.size(); i++){
            stream.write((char*)(&pizzas[i]), sizeof(Pizza));
        }
    }
    else{
        cerr << "Unable to read file" << endl;
    }

    stream.close();
    _pizzas = pizzas;
}
void pizzaRepo::WriteOrderToFile( Pizza pizzaToAdd ){

    ofstream stream;
    stream.open("pizza.bin", ios::binary|ios::app);
    stream.write((char*)(&pizzaToAdd), sizeof(Pizza));
    stream.close();

    _pizzas.push_back(pizzaToAdd);
}

vector<Pizza> pizzaRepo::ReturnAllPizzas(){
    return _pizzas;
}
