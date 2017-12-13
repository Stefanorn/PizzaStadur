#ifndef PRODUCTREPO_H
#define PRODUCTREPO_H

#include "Products.h"
#include <fstream>
#include <vector>

class ProductRepo
{
    public:
        ProductRepo();
        void overwriteFile(vector<Products> product);
        void addProduct(Products product);
        vector<Products> returnProducts();
        void readFile(); ///Færði í public úr private til að geta fengið aðgang úr öðrum klasa
        // friend ostream& operator << (ostream& outs, const );
        ///Er að reyna að lesa úr skránni hér og birta það á skjáinn.
    private:
        vector<Products> _prod;

};
#endif // PRODUCTREPO_H
