#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <map>

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"

using namespace std;

//template<typename T, typename D, typename F>
class Tree
{
    protected:
        Tree_Node* Tree_Root;
        /*
        int MySort(Tree_Node* l, Tree_Node* r) const
        {
            return l->digit<r->digit;
        }
        */
    public:
        Tree()
        {
            Tree_Root=NULL;
        }
        Tree(Tree_Node t)
        {
            *Tree_Root = t;
        }
        Tree_Node* GetRoot()
        {
            return Tree_Root;
        }
        void CreateTree(set<Tree_Node*> SetTree)
        {
            while(SetTree.size()!=1)
            {
        //ListTree.sort(MySort());

            Tree_Node* LNode = *SetTree.begin() ;
            SetTree.erase(*SetTree.begin());
            Tree_Node* RNode = *SetTree.begin();
            SetTree.erase(*SetTree.begin());

            Tree_Node* Parent_Node=new Tree_Node(LNode, RNode);
            SetTree.insert(Parent_Node);
            }

            Tree_Root = *SetTree.begin();
        }

        set<Tree_Node*> BuildNodes(map<char, int> TreeMap)
        {
            set<Tree_Node*> TreeSet;
    //map<D, T>::iterator iter<D, T>;

            for(map<char, int>::iterator iter = TreeMap.begin(); iter!=TreeMap.end(); iter++)
            {
                Tree_Node* Node=new Tree_Node();
                Node->symbol=iter->first;
                Node->digit=iter->second;
                TreeSet.insert(Node);
                //delete Node;
            }

            return TreeSet;
        }
};

#endif // TREE_H_INCLUDED
