#ifndef ITEMDATABASE_H
#define ITEMDATABASE_H

#include <vector>
#include <iostream>
#include "Pizza.h"

using namespace std;

class ItemDataBase
{
    public:
        ItemDataBase();
        virtual ~ItemDataBase();

    protected:

    private:
        //þetta mætti bara vera sér classi >>
        void ReadFromFile();
        bool UpdateOrder();
        void WriteOrderToFile( Pizza itemToWrite );
        //<< þetta mætti bara vera sér classi


        vector<Pizza> _item;//Endurskíra þennan clasa items og gera honum kleift að vera annaðhvort pizza eða eitthvað item

};

#endif // ITEMDATABASE_H
