#ifndef PRODUCTONFILEREPO_H
#define PRODUCTONFILEREPO_H
#include <vector>
#include "productOnFile.h"
#include <iostream>
#include <fstream>
#include "PizzaExeptions.h"

using namespace std;


class ProductOnFileRepo
{
    public:
        ProductOnFileRepo();
        void writeProdToFile( productOnFile prod );
        void RewriteFile(  vector<productOnFile> prods );
        vector<productOnFile> ReturnAllProds();

    private:
        void ReadFromFile();
        vector<productOnFile> _prods;
};

#endif // PRODUCTONFILEREPO_H
