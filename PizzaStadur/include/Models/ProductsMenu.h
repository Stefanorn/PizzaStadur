#ifndef PRODUCTSMENU_H
#define PRODUCTSMENU_H

#include "Products.h"

class ProductsMenu
{
    public:
        ProductsMenu();
        friend istream& operator >> (istream& in, ProductsMenu& product);
        friend ostream& operator << (ostream& out, const ProductsMenu& product);
        Products createProduct();
        char getID();
        double getPrice();
        string getName();

    private:
        int _ID;
        double _price;
        char _name[32];
};

#endif // PRODUCTSMENU_H
