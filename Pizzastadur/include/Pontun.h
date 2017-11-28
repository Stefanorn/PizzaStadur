#ifndef PONTUN_H
#define PONTUN_H

#include "Pizza.h"

class Pontun
{
    public:
        Pontun();
        virtual ~Pontun();

    protected:

    private:
        Pizza _pizza; //Breyta �essu � array �� get �g haft margar pizzur i s�mu p�ntun
        bool hasBeenPayedFor;
        bool hasBeenBaked;
        bool hasBeenDelevired;
        //char[100] info; //Auka uppl�singar
        //auka[??] _auka; h�r mindi �g skilgreina gos franskar og auka d�t

};

#endif // PONTUN_H
