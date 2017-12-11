#include "Products.h"

Products::Products()
{
    _productName[0] = '\0';
    _productPrice = 0;
}

string Products::getProductName()
{
    return _productName;
}

int Products::getProductID()
{
    return _productID;
}

double Products::getProductPrice()
{
    return _productPrice;
}

istream& operator >> (istream& ins, Products& product)
{
    ins >> product._productName;
    //ins >> topping._toppingType;
    ins >> product._productPrice;
    return ins;
}

ostream& operator << (ostream& outs, const Products& product)
{
    outs << product._productName << ", ";
    //outs << topping._toppingType << ", ";
    outs << product._productPrice << " kr." << endl;
    return outs;
}

