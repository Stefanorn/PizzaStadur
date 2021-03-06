#include "ToppingsRepo.h"

ToppingsRepo::ToppingsRepo()
{
    readFile();
}

void ToppingsRepo::overwriteFile(vector<Toppings> topping)
{
    ofstream fout;
    fout.open("toppings.bin", ios::binary);
    if (fout.is_open()){
        fout.seekp(fout.beg);
        for(unsigned int i = 0; i < topping.size(); i++){
            fout.write((char*)(&topping[i]), sizeof(Toppings));
        }
        fout.close();
    }
    else{
        cerr << "Unable to read file" << endl;
    }
    _topp = topping;
}

void ToppingsRepo::readFile()
{
    ifstream fin;
    fin.open("toppings.bin", ios::binary);

    if(fin.is_open()){
        fin.seekg(0, fin.end);
        int size = fin.tellg() / sizeof(Toppings);
        fin.seekg(0, fin.beg);

        Toppings temp;
        for(int i = 0; i < size; i++){
            fin.read((char*)(&temp), sizeof(Toppings));
            _topp.push_back(temp);
        }
    }
    else{
        cout << "Creating file toppings.bin" << endl;
    }
}

void ToppingsRepo::addTopping(Toppings toppingsToAdd)
{
    ofstream stream;
    stream.open("toppings.bin", ios::binary|ios::app);
    stream.write((char*)(&toppingsToAdd), sizeof(Toppings));
    stream.close();

    _topp.push_back(toppingsToAdd);
}

vector<Toppings> ToppingsRepo::returnToppings()
{
    return _topp;
}
