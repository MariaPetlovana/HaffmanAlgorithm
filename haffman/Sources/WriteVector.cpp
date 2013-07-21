#include "WriteVector.h"

void WriteVector::WriteVect(ofstream &fo, Tree_Node* Root)
{
    vector<char> ResultVector;
    ResultVector.push_back(2);
    WriteNode(ResultVector, Root, 0);

    fo << ResultVector.size() << endl;
    for(int i = 0; i < ResultVector.size(); ++i)
        fo << ResultVector[i];
    fo << endl;

    return;
}

void WriteVector::WriteNode(vector<char> &vect, Tree_Node* WNode, int indicator)
{
    if(NULL != WNode->GetLeft())
    {
        while(vect.size() <= 2*indicator+1)
        {
            vect.push_back(2);
        }

        vect[2*indicator+1] = ((WNode->GetLeft())->GetSymbol());
        WriteNode(vect, WNode->GetLeft(), 2*indicator+1);
    }

    if(NULL != WNode->GetRight())
    {
        while(vect.size() <= 2*indicator+2)
        {
            vect.push_back(2);
        }

        vect[2*indicator+2] = ((WNode->GetRight())->GetSymbol());
        WriteNode(vect, WNode->GetRight(), 2*indicator+2);
    }

    return;
}
