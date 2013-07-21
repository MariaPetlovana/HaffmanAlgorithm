#include "Tree_Node.h"

Tree_Node::Tree_Node(Tree_Node* _left, Tree_Node* _right)
{
    m_pl = _left;
    m_pr = _right;
    m_digit = _left->m_digit + _right->m_digit;
    m_symbol = (_left->m_symbol + _right->m_symbol) >> 1;
}

Tree_Node::Tree_Node()
{
    m_digit = 0;
    m_symbol = 2;
    m_pl = NULL;
    m_pr = NULL;
}


Tree_Node::Tree_Node(Tree_Node* Node)
{
    //this = new Tree_Node;
    m_pl = new Tree_Node();
    *m_pl = *(Node->m_pl);
    m_pr = new Tree_Node();
    *m_pr = *(Node->m_pr);
    m_digit = Node->m_digit;
    m_symbol = Node->m_symbol;
}

Tree_Node::Tree_Node(int _digit, char _symbol)
{
    m_digit = _digit;
    m_symbol = _symbol;
    m_pl = NULL;
    m_pr = NULL;
}


/*
void Tree_Node::PutLeft(Tree_Node* NodeLeft)
{
    l = new Tree_Node(NodeLeft);
}

void Tree_Node::PutRight(Tree_Node* NodeRight)
{
    r = new Tree_Node(NodeRight);
}
*/
