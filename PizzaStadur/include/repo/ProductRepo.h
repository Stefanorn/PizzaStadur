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
        void addProduct(vector<Products> product, int size);
        vector<Products> returnProducts();

    private:
        vector<Products> _prod;
        void readFile();
};
#endif // PRODUCTREPO_H
