#ifndef ENCRYPT_H_INCLUDED
#define ENCRYPT_H_INCLUDED

#include "AbstractEnDecrypt.h"

class Encrypt: public AbstractEnDecrypt
{
    public:
        //constructor
        Encrypt(char* NameFileFrom, char* NameFileTo);

        //destructor
        ~Encrypt();

        //function-encryption
        virtual void EnDecryption();
};


#endif // ENCRYPT_H_INCLUDED
