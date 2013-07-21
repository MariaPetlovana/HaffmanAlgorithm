#ifndef WRITEVECTOR_H_INCLUDED
#define WRITEVECTOR_H_INCLUDED

#include <vector>
#include <fstream>
#include "Tree_Node.h"

class WriteVector
{
    protected:
        void WriteNode(vector<char> &vect, Tree_Node* Node, int indicator);

    public:
        void WriteVect(ofstream &fo, Tree_Node* Root);
};

#endif // WRITEVECTOR_H_INCLUDED
