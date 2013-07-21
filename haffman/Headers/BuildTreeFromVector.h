#ifndef BUILDTREEFROMVECTOR_H_INCLUDED
#define BUILDTREEFROMVECTOR_H_INCLUDED

#include "Tree_Node.h"
#include <string>
#include <vector>
#include <fstream>

class BuildTreeFromVector
{
    protected:
        string m_str;

        void BuildNodes(int indicator, vector<char>& vect, int& SizeV, Tree_Node* &put);

    public:
        string GetString();

        //returns the tree's root
        Tree_Node* BuildTree(ifstream& fi);
};


#endif // BUILDTREEFROMVECTOR_H_INCLUDED
