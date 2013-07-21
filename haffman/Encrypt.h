#ifndef ENCRYPT_H_INCLUDED
#define ENCRYPT_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

#include "ValueTable.h"

using namespace std;

class Encrypt
{
    protected:
        ofstream m_output;

    public:
        Encrypt(char* NameFileTo);
        ~Encrypt();

        void Encryption(ValueTable* Value);
};


#endif // ENCRYPT_H_INCLUDED
