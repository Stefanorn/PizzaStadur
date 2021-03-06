#include "Products.h"
#include <stdlib.h>

Products::Products()
{
    _productName[0] = '\0';
    _productPrice = 0;
    _hotkey = '\0';
}

string Products::getProductName()
{
    string temp = _productName;
    return temp;
}

char Products::getKey(){
    return _hotkey;
}

double Products::getProductPrice()
{
    return _productPrice;
}

istream& operator >> (istream& ins, Products& product)
{
    string name;
    cout << "Enter product: ";
    ins.sync();
    getline(ins, name);
    strcpy(product._productName ,name.c_str());
    product._productName[31] = '\0';

    cout << "Pick a hot-key to quickly select your product from menu ";
    ins >> product._hotkey;
    cout << "Enter the price of product: ";
    ins >> product._productPrice;

    return ins;
}

ostream& operator << (ostream& outs, const Products& product)
{
    outs << "Product : " << product._productName << endl;
    outs << "  Price : " << product._productPrice << " kr." << endl;
    outs << "Press '" << product._hotkey << "' to add this product to your order." << endl;
    return outs;
}

