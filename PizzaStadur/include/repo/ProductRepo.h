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
        void readFile(); ///F�r�i � public �r private til a� geta fengi� a�gang �r ��rum klasa
        // friend ostream& operator << (ostream& outs, const );
        ///Er a� reyna a� lesa �r skr�nni h�r og birta �a� � skj�inn.
    private:
        vector<Products> _prod;

};
#endif // PRODUCTREPO_H
