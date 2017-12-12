#ifndef TOPPINGSMENUITEM_H
#define TOPPINGSMENUITEM_H
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class ToppingsMenuItem
{
    public:
        friend istream& operator >> (istream& ins, ToppingsMenuItem& toppingsMenuItem);
        friend ostream& operator << (ostream& outs, const ToppingsMenuItem& toppingsMenuItem);

        char getHotkey();
        double getPrice();
        string getName();

    private:
        char _name[32];
        char _hotkey;
        double _price;
};

#endif // TOPPINGSMENUITEM_H
