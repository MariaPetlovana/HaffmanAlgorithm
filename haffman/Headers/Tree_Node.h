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
        friend class Tree;
        int m_digit;
        char m_symbol;
        Tree_Node *m_pl, *m_pr;

    public:
        //constructors
        Tree_Node(Tree_Node* _left, Tree_Node* _right);
        Tree_Node();
        Tree_Node(Tree_Node* Node);
        Tree_Node(int _digit, char _symbol);

        //destructor
        ~Tree_Node();

        //setters
        void SetLeft(Tree_Node* NodeLeft);
        void SetRight(Tree_Node* NodeRight);

        //getters
        Tree_Node* & GetLeft();
        Tree_Node* & GetRight();
        char GetSymbol();
        int GetDigit();
};

#endif // TREE_NODE_H_INCLUDED
