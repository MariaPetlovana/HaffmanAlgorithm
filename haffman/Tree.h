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

using namespace std;

class Tree
{
    protected:
        //friend class Tree_Node;
        Tree_Node* Tree_Root;

        struct MySort
        {
            bool operator()(Tree_Node* l, Tree_Node* r) const
            {
                if(l->m_digit == r->m_digit) return l->m_symbol < r->m_symbol;
                return l->m_digit<r->m_digit;
            }
        };

    public:
        Tree();
        Tree(Tree_Node t);
        Tree_Node* GetRoot();

        void CreateTree(set<Tree_Node*, MySort> SetTree);

        set<Tree_Node*, MySort> BuildNodes(map<char, int> TreeMap)
        {
            set<Tree_Node*, MySort> TreeSet;

            for(map<char, int>::iterator iter = TreeMap.begin(); iter != TreeMap.end(); ++iter)
            {
                Tree_Node* Node = new Tree_Node(iter->second, iter->first);
                TreeSet.insert(Node);
            }

            return TreeSet;
        }
};

#endif // TREE_H_INCLUDED
