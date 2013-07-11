#include "Decrypt.h"

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"
#include "HaffmanTable.h"
#include <vector>

Decrypt::Decrypt(char* FileFromDecrypt, char* FileToDecrypt)
{
    fi.open(FileFromDecrypt);
    fo.open(FileToDecrypt);
}

void Decrypt::Decryption(Tree* MyTree)
{
    //ifstream fo2("result.txt");
    root = MyTree->GetRoot();
    int cou=0;
    char buf=0;
    fi.get(buf);
    while(!fi.eof())
    {
        bool b = buf & (1<<(7-cou));
        if(b) root = root->r;
        else root = root->l;

        if(root->l==NULL && root->r==NULL)
        {
            fo<<root->symbol;
            //cout<<root_tree->symbol;
            root = MyTree->GetRoot();
        }
        ++cou;
        if(cou==8)
        {
            cou=0;
            fi.get(buf);
        }
    }

    return;
}
