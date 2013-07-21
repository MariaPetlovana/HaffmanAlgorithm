#include "Encrypt.h"

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"
#include "HaffmanTable.h"
#include <vector>
#include "Decrypt.h"

Encrypt::Encrypt(char* NameFileTo)
{
    m_output.open(NameFileTo);
}

Encrypt::~Encrypt()
{
    m_output.close();
}

void Encrypt::Encryption(ValueTable* Value)
{
    int cou=0;
    char buf=0;

    Tree MyTree;

    MyTree.CreateTree(MyTree.BuildNodes(Value->BuildTable()));
    HaffmanTable MyHaf(MyTree.GetRoot());

    string str = Value->ReturnStr();

    map<char, vector<bool> > HafTable = MyHaf.BuildTable();

    MyHaf.WriteVector(m_output);

    for(int i = 0; i < str.length(); ++i)
    {
        vector<bool> v = HafTable[str[i]];
        for(int j = 0; j < v.size(); ++j)
        {
            buf = buf | (v[j] << (7 - cou));
            ++cou;

            if(8 == cou)
            {
                cou = 0;
                m_output << buf;
                buf = 0;
            }
        }
    }
    /*
    if(cou)
    {
        cou = 0;
        m_output << buf;
        buf = 0;
    }
    */

    return;
}

