#include "ProductRepo.h"

ProductRepo::ProductRepo()
{
    readFile();
}

void ProductRepo::overwriteFile(vector<Products> product)
{
    ofstream fout;
    fout.open("products.bin", ios::binary);
    if (fout.is_open()){
        fout.seekp(fout.beg);
        for(unsigned int i = 0; i < product.size(); i++){
            fout.write((char*)(&product[i]), sizeof(Products));
        }
        fout.close();
    }
    else{
        cerr << "Unable to read file" << endl;
    }
    _prod = product;
}

void ProductRepo::readFile()
{
    ifstream fin;
    fin.open("products.bin", ios::binary);

    if(fin.is_open()){
        fin.seekg(0, fin.end);
        int size = fin.tellg() / sizeof(Products);
        fin.seekg(0, fin.beg);

        Products temp;
        for(int i = 0; i < size; i++){
            fin.read((char*)(&temp), sizeof(Products));
            _prod.push_back(temp);
        }
    }
    else{
        cout << "Creating file products.bin" << endl;
    }
}

void ProductRepo::addProduct(vector<Products> product, int size)
{
    ofstream fout;
    fout.open("products.bin", ios::binary|ios::app);
    fout.write((char*)(&product), sizeof(Products)* size);
    fout.close();

    _prod.reserve(_prod.size() + product.size());
    _prod.insert(_prod.end(), product.begin(), product.end());
    product.clear();
}

vector<Products> ProductRepo::returnProducts()
{
    return _prod;
}
