#include "Decrypt.h"

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"
#include "HaffmanTable.h"
#include <vector>

Decrypt::Decrypt(char* FileFromDecrypt, char* FileToDecrypt)
{
    m_fi.open(FileFromDecrypt);
    m_fo.open(FileToDecrypt);
}

Decrypt::~Decrypt()
{
    m_fi.close();
    m_fo.close();
}

void Decrypt::BuildNodes(int indicator, vector<char>& vect, int& SizeV, Tree_Node* &put)
{
    if((2 * indicator + 1) < SizeV && 2 != vect[2 * indicator + 1])
    {
        put->m_pl = new Tree_Node(0, vect[2 * indicator + 1]);
        BuildNodes(2 * indicator + 1, vect, SizeV, put->m_pl);
    }

    if((2 * indicator + 2) < SizeV && 2 != vect[2 * indicator + 2])
    {
        put->m_pr = new Tree_Node(0, vect[2 * indicator + 2]);
        BuildNodes(2 * indicator + 2, vect, SizeV, put->m_pr);
    }

    return;
}

string Decrypt::BuildTree()
{
    int VectorSize;
    char ch;
    int indicator = 0;
    m_fi >> VectorSize;

    m_fi.get(ch);

    vector<char> ScanfVect(VectorSize, 2);
    for(int i = 0; i < VectorSize; ++i)
    {
        m_fi.get(ch);
        if(2 != ch)
        {
            ScanfVect[i] = ch;
        }
    }

    m_fi.get(ch);
    string str = "";
    while(!m_fi.eof())
    {
        m_fi.get(ch);
        str += ch;
    }

    m_root = new Tree_Node(0, ScanfVect[0]);

    BuildNodes(indicator, ScanfVect, VectorSize, m_root);

    return str;
}

void Decrypt::Decryption()
{
    string buf = BuildTree();
    Tree_Node* WorkRoot = new Tree_Node(m_root);
    int cou=0, index=0;

    while(index < buf.length())
    {
        bool b = buf[index] & (1 << (7 - cou));
        if(b)
        {
            WorkRoot = WorkRoot->m_pr;
        }
        else
        {
            WorkRoot = WorkRoot->m_pl;
        }

        if(NULL == WorkRoot->m_pl && NULL == WorkRoot->m_pr)
        {
            m_fo << WorkRoot->m_symbol;
            WorkRoot = m_root;
        }

        ++cou;
        if(8 == cou)
        {
            cou = 0;
            ++index;
        }
    }

    return;
}
