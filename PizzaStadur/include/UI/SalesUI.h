#ifndef SALESUI_H
#define SALESUI_H
#include <stdlib.h>
#include "SalesServices.h"

class SalesUI
{
    public:
        SalesUI();

    protected:

    private:
        SalesServices service;
        void createOrder();
        void GetInfoAboutOrder();
};

#endif // SALESUI_H
