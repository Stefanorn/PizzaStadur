#ifndef BAKERUI_H
#define BAKERUI_H

#include <iostream>
#include "BakerServices.h"

using namespace std;

class BakerUI
{
    public:
        BakerUI();
        void _mainMenu();

    private:
        BakerServices bakerService;
};

#endif // BAKERUI_H
