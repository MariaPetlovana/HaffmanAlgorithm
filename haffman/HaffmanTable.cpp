#include "HaffmanTable.h"

HaffmanTable::HaffmanTable(Tree_Node* TNode)
{
    Node=TNode;
}

map<char, vector<bool> > HaffmanTable::BuildTable()
{
    vector<bool> b;
    BuildHaffmanTable(Node, TableMap, b);
    return TableMap;
}

void HaffmanTable::BuildHaffmanTable(Tree_Node* Tree_Root, map<char, vector<bool> > &MapTable, vector<bool> &b)
{
    if(Tree_Root->l!=NULL)
    {
        b.push_back(0);
        //cout<<0<<endl;
        BuildHaffmanTable(Tree_Root->l, MapTable, b);
    }

    if(Tree_Root->r!=NULL)
    {
        b.push_back(1);
        //cout<<1<<endl;
        BuildHaffmanTable(Tree_Root->r, MapTable, b);
    }

    if(Tree_Root->symbol) MapTable[Tree_Root->symbol]=b;

    b.pop_back();
}
