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
        ifstream m_fi;
        ofstream m_fo;
        Tree_Node* m_root;

        void BuildNodes(int indicator, vector<char>& vect, int& SizeV, Tree_Node* &put);

    public:
        Decrypt(char* FileFromDecrypt, char* FileToDecrypt);
        ~Decrypt();
        void Decryption();
        string BuildTree();
};

#endif // DECRYPT_H_INCLUDED
