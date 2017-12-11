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

void ToppingMenuRepo::addTopping(vector<ToppingsMenuItem> menItem, int size)
{
    ofstream fout;
    fout.open("toppingsMenu.bin", ios::binary|ios::app);
    fout.write((char*)(&menItem), sizeof(ToppingsMenuItem)* size);
    fout.close();

    _menItem.reserve(_menItem.size() + menItem.size());
    _menItem.insert(_menItem.end(), menItem.begin(), menItem.end());
    menItem.clear();
}

vector<ToppingsMenuItem> ToppingMenuRepo::returnToppings()
{
    return _menItem;
}
