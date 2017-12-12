#ifndef PIZZAMENUREPO_H
#define PIZZAMENUREPO_H

#include "PizzaMenu.h"
#include <fstream>
#include <vector>

class PizzaMenuRepo
{
    public:
        PizzaMenuRepo();
        void ReadFromFile();
        void RewriteFile( vector<PizzaMenu> menuItem );
        void WriteToFile( PizzaMenu itemToWrite );

        vector<PizzaMenu> ReturnAllPizzaMenu();

    private:
        vector<PizzaMenu> _menuItem;
};

#endif // PIZZAMENUREPO_H
