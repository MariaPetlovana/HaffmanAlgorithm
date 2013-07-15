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

    if((NULL == Tree_Root->l) &&  (NULL == Tree_Root->r)) MapTable[Tree_Root->symbol]=b;

    b.pop_back();
}

void HaffmanTable::WriteVector(ofstream &fo)
{
    vector<char> ResultVector;
    ResultVector.push_back(2);
    WriteNode(ResultVector, Node, 0);

    fo<<ResultVector.size()<<endl;
    for(int i=0; i<ResultVector.size(); i++)
    fo<<ResultVector[i];
    fo<<endl;

    return;
}

void HaffmanTable::WriteNode(vector<char> &vect, Tree_Node* WNode, int indicator)
{
    if(NULL != WNode->l)
    {
        while(vect.size()<=2*indicator+1)
        {
            vect.push_back(2);
        }
        vect[2*indicator+1] = ((WNode->l)->symbol);
        WriteNode(vect, WNode->l, 2*indicator+1);
    }
    if(NULL != WNode->r)
    {
        while(vect.size()<=2*indicator+2)
        {
            vect.push_back(2);
        }
        vect[2*indicator+2] = ((WNode->r)->symbol);
        WriteNode(vect, WNode->r, 2*indicator+2);
    }

    return;
}
