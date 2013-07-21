#ifndef ABSTRACTENDECRYPT_H_INCLUDED
#define ABSTRACTENDECRYPT_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

#include "ValueTable.h"
#include "WriteVector.h"
#include "Tree_Node.h"
#include "Tree.h"
#include "BuildTreeFromVector.h"

using namespace std;

class AbstractEnDecrypt
{
    protected:
        ifstream m_input;
        ofstream m_output;

    public:
        virtual void EnDecryption() = 0;
};

#endif // ABSTRACTENDECRYPT_H_INCLUDED
