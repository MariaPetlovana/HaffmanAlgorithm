#include "Encrypt.h"
#include "HaffmanTable.h"

Encrypt::Encrypt(char* NameFileFrom, char* NameFileTo)
{
    m_input.open(NameFileFrom);
    m_output.open(NameFileTo);
}

Encrypt::~Encrypt()
{
    m_input.close();
    m_output.close();
}

void Encrypt::EnDecryption()
{
    int cou=0;
    char buf=0;

    ValueTable Value;

    Tree MyTree;

    MyTree.CreateTree(MyTree.BuildNodes(Value.BuildTable(m_input)));

    HaffmanTable MyHaf;

    string str = Value.ReturnStr();

    map<char, vector<bool> > HafTable = MyHaf.BuildTable(MyTree.GetRoot());

    WriteVector WVect;
    WVect.WriteVect(m_output, MyTree.GetRoot());

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

