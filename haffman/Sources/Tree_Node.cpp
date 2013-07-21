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

Tree_Node::~Tree_Node()
{
    if(NULL != m_pl)
    {
        delete m_pl;
    }

    if(NULL != m_pr)
    {
        delete m_pr;
    }
}

void Tree_Node::SetLeft(Tree_Node* NodeLeft)
{
    m_pl = NodeLeft;
    return;
}

void Tree_Node::SetRight(Tree_Node* NodeRight)
{
    m_pr = NodeRight;
    return;
}

Tree_Node* & Tree_Node::GetLeft()
{
    return m_pl;
}

Tree_Node* & Tree_Node::GetRight()
{
    return m_pr;
}

char Tree_Node::GetSymbol()
{
    return m_symbol;
}

int Tree_Node::GetDigit()
{
    return m_digit;
}
