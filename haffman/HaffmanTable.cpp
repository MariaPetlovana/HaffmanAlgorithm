#include "HaffmanTable.h"

HaffmanTable::HaffmanTable(Tree_Node* TNode)
{
    m_Node = TNode;
}

map<char, vector<bool> > HaffmanTable::BuildTable()
{
    vector<bool> b;
    BuildHaffmanTable(m_Node, m_TableMap, b);
    return m_TableMap;
}

void HaffmanTable::BuildHaffmanTable(Tree_Node* Tree_Root, map<char, vector<bool> > &MapTable, vector<bool> &b)
{
    if(Tree_Root->m_pl != NULL)
    {
        b.push_back(0);
        BuildHaffmanTable(Tree_Root->m_pl, MapTable, b);
    }

    if(Tree_Root->m_pr != NULL)
    {
        b.push_back(1);
        BuildHaffmanTable(Tree_Root->m_pr, MapTable, b);
    }

    if((NULL == Tree_Root->m_pl) &&  (NULL == Tree_Root->m_pr)) MapTable[Tree_Root->m_symbol] = b;

    b.pop_back();

    return;
}

void HaffmanTable::WriteVector(ofstream &fo)
{
    vector<char> ResultVector;
    ResultVector.push_back(2);
    WriteNode(ResultVector, m_Node, 0);

    fo << ResultVector.size() << endl;
    for(int i = 0; i < ResultVector.size(); ++i)
        fo << ResultVector[i];
    fo << endl;

    return;
}

void HaffmanTable::WriteNode(vector<char> &vect, Tree_Node* WNode, int indicator)
{
    if(NULL != WNode->m_pl)
    {
        while(vect.size() <= 2*indicator+1)
        {
            vect.push_back(2);
        }

        vect[2*indicator+1] = ((WNode->m_pl)->m_symbol);
        WriteNode(vect, WNode->m_pl, 2*indicator+1);
    }

    if(NULL != WNode->m_pr)
    {
        while(vect.size() <= 2*indicator+2)
        {
            vect.push_back(2);
        }

        vect[2*indicator+2] = ((WNode->m_pr)->m_symbol);
        WriteNode(vect, WNode->m_pr, 2*indicator+2);
    }

    return;
}
