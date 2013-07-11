#ifndef DECRYPT_H_INCLUDED
#define DECRYPT_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

#include "Tree_Node.h"
#include "Tree.h"

using namespace std;

class Decrypt
{
    protected:
        ifstream fi;
        ofstream fo;
        Tree_Node* root;
    public:
        Decrypt(char* FileFromDecrypt, char* FileToDecrypt);
        ~Decrypt(){fi.close(); fo.close();}
        void Decryption(Tree* MyTree);
};

#endif // DECRYPT_H_INCLUDED