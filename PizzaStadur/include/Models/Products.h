#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <string>
#include <iostream>

using namespace std;

class Products
{
    public:
        Products();
        string getProductName();
        double getProductPrice();
        int getProductID();
        friend istream& operator >> (istream& ins, Products& product);
        friend ostream& operator << (ostream& outs, const Products& product);

    private:
        char _productName[32];
        double _productPrice;
        int _productID;
};

#endif // PRODUCTS_H
