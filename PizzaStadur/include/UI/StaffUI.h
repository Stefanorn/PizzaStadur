#ifndef STAFFUI_H
#define STAFFUI_H
#include <stdlib.h>
#include "staffServices.h"
class StaffUI
{
    public:
        StaffUI();
    protected:

    private:
        void PayForOrder();
        void DeliverOrder();
        staffServices service;
};

#endif // STAFFUI_H
