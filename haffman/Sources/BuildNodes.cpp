#ifndef BuildNodes_H_INCLUDED
#define BuildNodes_H_INCLUDED

#include "Tree_Node.h"
#include <map>
#include <set>

struct MySort
{
    bool operator()(Tree_Node* l, Tree_Node* r) const
    {
        if(l->GetDigit() == r->GetDigit()) return l->GetSymbol() < r->GetSymbol();
        return l->GetDigit() < r->GetDigit();
    }
};

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

#endif BuildNodes_H_INCLUDED
