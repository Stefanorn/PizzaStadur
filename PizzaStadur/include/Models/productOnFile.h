#ifndef PRODUCTONFILE_H
#define PRODUCTONFILE_H
#include <string>
#include <iostream>
using namespace std;

class productOnFile
{
    public:
        productOnFile();
        productOnFile(string name, double price);
        string getProductName();
        double getProductPrice();
        int getID();
        void tagProductToOrder(int id);
        friend ostream& operator << (ostream& outs, const productOnFile& product);

    private:
        char _productName[32];
        double _productPrice;
        int _productToOrderID;
};

#endif // PRODUCTONFILE_H
