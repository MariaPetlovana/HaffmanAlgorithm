#include "Tree.h"

Tree::Tree()
{
    Tree_Root=NULL;
}

Tree::Tree(Tree_Node t)
{
    *Tree_Root = t;
}

Tree_Node* Tree::GetRoot()
{
    return Tree_Root;
}

void Tree::CreateTree(set<Tree_Node*, MySort> SetTree)
{
    while(SetTree.size() != 1)
    {
        Tree_Node* LNode = *SetTree.begin();
        SetTree.erase(*SetTree.begin());

        Tree_Node* RNode = *SetTree.begin();
        SetTree.erase(*SetTree.begin());

        Tree_Node* Parent_Node=new Tree_Node(LNode, RNode);
        SetTree.insert(Parent_Node);
    }

    Tree_Root = *SetTree.begin();

    return;
}

