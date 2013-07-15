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
        ofstream output;

        //void WriteVector(vector<char> &vect);

    public:
        Encrypt(char* NameFileTo)
        {
            output.open(NameFileTo);
        }
        ~Encrypt()
        {
            output.close();
        }
        void Encryption(ValueTable* Value);
};


#endif // ENCRYPT_H_INCLUDED
