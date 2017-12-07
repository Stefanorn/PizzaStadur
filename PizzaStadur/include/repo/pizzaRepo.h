#ifndef PIZZAREPO_H
#define PIZZAREPO_H
#include "Pizza.h"
#include <vector>
#include <fstream>

using namespace std;

class pizzaRepo
{
    public:
        pizzaRepo();
        void RewriteFile( vector<Pizza> pizzas );
        void WriteOrderToFile( Pizza pizzaToAdd );

    private:
        void ReadFromFile();
        vector<Pizza> _pizzas;

};

#endif // PIZZAREPO_H
