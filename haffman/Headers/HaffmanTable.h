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
#include "WriteVector.h"

using namespace std;

class HaffmanTable
{
    protected:
        map<char, vector<bool> > m_TableMap;

        void BuildHaffmanTable(Tree_Node* N, map<char, vector<bool> > &HaffmanTableMap, vector<bool> &b);

    public:
        //returns Haffman table
        virtual map<char, vector<bool> > BuildTable(Tree_Node* Node);
};

#endif // HAFFMANTABLE_H_INCLUDED
