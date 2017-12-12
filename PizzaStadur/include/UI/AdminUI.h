#ifndef ADMINUI_H
#define ADMINUI_H

#include <iostream>
#include <stdlib.h>
#include "Pizza.h"
#include "AdminServices.h"

using namespace std;

class AdminUI {
    public:
        AdminUI();
        void mainMenu();

    private:
        //vector<Pizza> pizzaList;
        AdminServices _adminService;
};

#endif // ADMINUI_H
