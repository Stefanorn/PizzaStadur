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
        //�etta m�tti bara vera s�r classi >>
        void ReadFromFile();
        bool UpdateOrder();
        void WriteOrderToFile( Pizza itemToWrite );
        //<< �etta m�tti bara vera s�r classi


        vector<Pizza> _item;//Endursk�ra �ennan clasa items og gera honum kleift a� vera anna�hvort pizza e�a eitthva� item

};

#endif // ITEMDATABASE_H
