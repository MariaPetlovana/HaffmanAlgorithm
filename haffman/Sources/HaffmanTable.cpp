#include "HaffmanTable.h"

map<char, vector<bool> > HaffmanTable::BuildTable(Tree_Node* Node)
{
    vector<bool> b;
    BuildHaffmanTable(Node, m_TableMap, b);
    return m_TableMap;
}

void HaffmanTable::BuildHaffmanTable(Tree_Node* Tree_Root, map<char, vector<bool> > &MapTable, vector<bool> &b)
{
    if(NULL != Tree_Root->GetLeft())
    {
        b.push_back(0);
        BuildHaffmanTable(Tree_Root->GetLeft(), MapTable, b);
    }

    if(NULL != Tree_Root->GetRight())
    {
        b.push_back(1);
        BuildHaffmanTable(Tree_Root->GetRight(), MapTable, b);
    }

    if((NULL == Tree_Root->GetLeft()) &&  (NULL == Tree_Root->GetRight())) MapTable[Tree_Root->GetSymbol()] = b;

    b.pop_back();

    return;
}
