#ifndef BAKERUI_H
#define BAKERUI_H

#include <iostream>
#include <time.h>
#include "BakerServices.h"

using namespace std;

class BakerUI
{
    public:
        BakerUI();
        void _mainMenu();

    private:
        void _clockMessages();
};

#endif // BAKERUI_H
