#ifndef TREE_NODE_H_INCLUDED
#define TREE_NODE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class Tree_Node
{
    protected:
        //friend class Tree;
        //int digit;
        //char symbol;
        //Tree_Node *l, *r;
    public:
        int m_digit;
        char m_symbol;
        Tree_Node *m_pl, *m_pr;

        Tree_Node(Tree_Node* _left, Tree_Node* _right);
        Tree_Node();
        Tree_Node(Tree_Node* Node);
        Tree_Node(int _digit, char _symbol);

        //void PutLeft(Tree_Node* NodeLeft);
        //void PutRight(Tree_Node* NodeRight);

        bool operator< (const Tree_Node* Node1) const
        {
            if(Node1->m_symbol != m_symbol)
            return Node1->m_digit > m_digit;
        }
};

#endif // TREE_NODE_H_INCLUDED
