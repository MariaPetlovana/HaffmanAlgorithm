#ifndef HAFFMANTABLE_H_INCLUDED
#define HAFFMANTABLE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"

using namespace std;

class HaffmanTable: public Table<char, vector<bool> >
{
    protected:
        Tree_Node* m_Node;

        void BuildHaffmanTable(Tree_Node* N, map<char, vector<bool> > &HaffmanTableMap, vector<bool> &b);
        void WriteNode(vector<char> &vect, Tree_Node* Node, int indicator);

    public:
        HaffmanTable(Tree_Node* TNode);
        virtual map<char, vector<bool> > BuildTable();
        void WriteVector(ofstream &fo);
};

#endif // HAFFMANTABLE_H_INCLUDED
