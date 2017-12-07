#include "ToppingsService.h"

ToppingsService::ToppingsService()
{
    //ctor
}

void ToppingsService::addTopping(const Toppings& topping)
{
    ToppingsRepo.addTopping(topping);
    cout << topping << endl;
}
