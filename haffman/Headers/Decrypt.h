#ifndef DECRYPT_H_INCLUDED
#define DECRYPT_H_INCLUDED

#include "AbstractEnDecrypt.h"

class Decrypt: public AbstractEnDecrypt
{
    public:
        //constructor
        Decrypt(char* FileFromDecrypt, char* FileToDecrypt);

        //destructor
        ~Decrypt();

        //function-decryption
        virtual void EnDecryption();
};

#endif // DECRYPT_H_INCLUDED
