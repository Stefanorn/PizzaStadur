#include "ProductOnFileRepo.h"

ProductOnFileRepo::ProductOnFileRepo(){
    ReadFromFile();
}

void ProductOnFileRepo::writeProdToFile( productOnFile prod ){

    ofstream stream;
    stream.open("productsOnFile.bin", ios::binary|ios::app);
    stream.write((char*)(&prod), sizeof(productOnFile));
    stream.close();


    _prods.push_back(prod);

}
void ProductOnFileRepo::RewriteFile(  vector<productOnFile> prods ){

    ofstream stream;

    stream.open("productsOnFile.bin", ios::binary);
    if(stream.is_open()){
        stream.seekp( stream.beg );
        for(unsigned int i = 0; i < prods.size(); i++){
            stream.write((char*)(&prods[i]), sizeof(productOnFile));
        }
        stream.close();
    }
    _prods = prods;

}
vector<productOnFile> ProductOnFileRepo::ReturnAllProds(){
    return _prods;

}
void ProductOnFileRepo::ReadFromFile(){

    ifstream stream;
    stream.open( "productsOnFile.bin", ios::binary );

    if(stream.is_open() ){
        stream.seekg(0,stream.end);
        int length = stream.tellg() / sizeof(productOnFile);
        stream.seekg(0, stream.beg);

        productOnFile temp;
        for(int i = 0; i < length; i++){
            stream.read((char*)(&temp), sizeof(productOnFile));
            _prods.push_back(temp);
        }
    }
    else{
        cerr << "Could not find productsOnFile.bin" << endl;
    }

    stream.close();

}
