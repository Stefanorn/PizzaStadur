#ifndef PONTUN_H
#define PONTUN_H

#include "Pizza.h"

class Pontun
{
    public:
        Pontun();

    protected:

    private:
        Pizza _pizza; //Breyta þessu í array þá get ég haft margar pizzur i sömu pöntun
        bool _hasBeenPayedFor;
        bool _hasBeenBaked;
        bool _hasBeenDelevired;
        //char[100] info; //Auka upplýsingar
        //auka[??] _auka; hér mindi ég skilgreina gos franskar og auka dót

};

#endif // PONTUN_H
