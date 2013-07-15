#include "Tree_Node.h"

Tree_Node::Tree_Node(Tree_Node* _left, Tree_Node* _right)
{
    l=_left;
    r=_right;
    digit=_left->digit+_right->digit;
    symbol = (_left->symbol+_right->symbol) >> 1;
}

Tree_Node::Tree_Node()
{
    //digit=1;
    //symbol=-1;
    l=NULL;
    r=NULL;
}

Tree_Node::Tree_Node(Tree_Node* Node)
{
    //this = new Tree_Node;
    l = new Tree_Node();
    *l = *(Node->l);
    r = new Tree_Node();
    *r = *(Node->r);
    digit = Node->digit;
    symbol = Node->symbol;
}

void Tree_Node::PutLeft(Tree_Node* NodeLeft)
{
    l = new Tree_Node(NodeLeft);
}

void Tree_Node::PutRight(Tree_Node* NodeRight)
{
    r = new Tree_Node(NodeRight);
}
