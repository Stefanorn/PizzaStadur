#include "ToppingMenuRepo.h"

ToppingMenuRepo::ToppingMenuRepo()
{
    readFile();
}

void ToppingMenuRepo::overwriteFile(vector<ToppingsMenuItem> MenuItem)
{
    ofstream fout;
    fout.open("toppingsMenu.bin", ios::binary);
    if (fout.is_open()){
        fout.seekp(fout.beg);
        for(unsigned int i = 0; i < MenuItem.size(); i++){
            fout.write((char*)(&MenuItem[i]), sizeof(ToppingsMenuItem));
        }
        fout.close();
    }
    else{
        cerr << "Unable to read file" << endl;
    }
    _menItem = MenuItem;
}

void ToppingMenuRepo::readFile()
{
    ifstream fin;
    fin.open("toppingsMenu.bin", ios::binary);

    if(fin.is_open()){
        fin.seekg(0, fin.end);
        int size = fin.tellg() / sizeof(ToppingsMenuItem);
        fin.seekg(0, fin.beg);

        ToppingsMenuItem temp;

        for(int i = 0; i < size; i++){
            fin.read((char*)(&temp), sizeof(ToppingsMenuItem));
            _menItem.push_back(temp);
        }
    }
    else{
        cout << "Creating file toppingsMenu.bin" << endl;
    }
}

void ToppingMenuRepo::addTopping( ToppingsMenuItem item)
{
    ofstream stream;
    stream.open("toppingsMenu.bin", ios::binary|ios::app);
    stream.write((char*)(&item), sizeof(ToppingsMenuItem));
    stream.close();

    _menItem.push_back(item);
}

vector<ToppingsMenuItem> ToppingMenuRepo::returnToppings()
{
    return _menItem;
}
