#include "productOnFile.h"


productOnFile::productOnFile(){
    _productName[0] = '\0';
    _productPrice = 0;
    _productToOrderID = -1;
}
productOnFile::productOnFile(string name, double price){
//    _productName = name;
    _productPrice = price;
    _productToOrderID = -1 ;
}
string productOnFile::getProductName(){
    return _productName;
}
double productOnFile::getProductPrice(){
    return _productPrice;
}
int productOnFile::getID(){
    return _productToOrderID;
}
void productOnFile::tagProductToOrder( int id){
    _productToOrderID = id;
}
ostream& operator << (ostream& outs, const productOnFile& product){
    outs << product._productName << ", ";
    outs << product._productPrice << " kr." << endl;
    return outs;
}
