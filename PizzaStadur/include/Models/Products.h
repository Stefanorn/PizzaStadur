#ifndef PRODUCTS_H
#define PRODUCTS_H

#include<cstring>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Products
{
    public:
        Products();
        string getProductName();
        double getProductPrice();
        char getKey();
        friend istream& operator >> (istream& ins, Products& product);
        friend ostream& operator << (ostream& outs, const Products& product);

    private:
        char _productName[32];
        double _productPrice;
        char _hotkey;
};

#endif // PRODUCTS_H
