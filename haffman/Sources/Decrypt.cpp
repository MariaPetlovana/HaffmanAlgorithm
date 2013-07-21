#include "Decrypt.h"

Decrypt::Decrypt(char* FileFromDecrypt, char* FileToDecrypt)
{
    m_input.open(FileFromDecrypt);
    m_output.open(FileToDecrypt);
}

Decrypt::~Decrypt()
{
    m_input.close();
    m_output.close();
}

void Decrypt::EnDecryption()
{
    BuildTreeFromVector BTFV;
    Tree_Node* Root = BTFV.BuildTree(m_input);
    Tree_Node* WorkRoot = new Tree_Node(Root);
    string buf = BTFV.GetString();

    int cou=0, index=0;

    while(index < buf.length())
    {
        bool b = buf[index] & (1 << (7 - cou));
        if(b)
        {
            WorkRoot = WorkRoot->GetRight();
        }
        else
        {
            WorkRoot = WorkRoot->GetLeft();
        }

        if(NULL == WorkRoot->GetLeft() && NULL == WorkRoot->GetRight())
        {
            m_output << WorkRoot->GetSymbol();
            WorkRoot = Root;
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
