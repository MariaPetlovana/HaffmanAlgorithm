#include "BuildTreeFromVector.h"

void BuildTreeFromVector::BuildNodes(int indicator, vector<char>& vect, int& SizeV, Tree_Node* &put)
{
    if((2 * indicator + 1) < SizeV && 2 != vect[2 * indicator + 1])
    {
        put->SetLeft(new Tree_Node(0, vect[2 * indicator + 1]));
        BuildNodes(2 * indicator + 1, vect, SizeV, put->GetLeft());
    }

    if((2 * indicator + 2) < SizeV && 2 != vect[2 * indicator + 2])
    {
        put->SetRight(new Tree_Node(0, vect[2 * indicator + 2]));
        BuildNodes(2 * indicator + 2, vect, SizeV, put->GetRight());
    }

    return;
}

Tree_Node* BuildTreeFromVector::BuildTree(ifstream& fi)
{
    int VectorSize;
    char ch;
    int indicator = 0;
    fi >> VectorSize;

    fi.get(ch);

    vector<char> ScanfVect(VectorSize, 2);
    for(int i = 0; i < VectorSize; ++i)
    {
        fi.get(ch);
        if(2 != ch)
        {
            ScanfVect[i] = ch;
        }
    }

    fi.get(ch);
    m_str = "";
    while(!fi.eof())
    {
        fi.get(ch);
        m_str += ch;
    }

    Tree_Node* root = new Tree_Node(0, ScanfVect[0]);

    BuildNodes(indicator, ScanfVect, VectorSize, root);

    return root;
}

string BuildTreeFromVector::GetString()
{
    return m_str;
}
