#include "Tree_Node.h"

Tree_Node::Tree_Node(Tree_Node* _left, Tree_Node* _right)
{
    l=_left;
    r=_right;
    digit=_left->digit+_right->digit;
    //symbol(_left->symbol){};
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
