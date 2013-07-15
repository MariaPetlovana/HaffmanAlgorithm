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

void Decrypt::BuildNodes(int indicator, vector<char>& vect, int& SizeV, Tree_Node* &put)
{
    if(2*indicator+1<SizeV && 2!=vect[2*indicator+1])
    {
        Tree_Node* Node = new Tree_Node;
        Node->symbol = vect[2*indicator+1];

        cout<<Node->symbol<<" l "<<2*indicator+1<<endl;

        Node->digit = 0;
        put->l = Node;

        BuildNodes(2*indicator+1, vect, SizeV, Node);
    }

    if(2*indicator+2<SizeV && 2!=vect[2*indicator+2])
    {
        Tree_Node* Node = new Tree_Node;
        Node->symbol = vect[2*indicator+2];

        cout<<Node->symbol<<" r "<<2*indicator+2<<endl;

        Node->digit = 0;
        put->r = Node;

        BuildNodes(2*indicator+2, vect, SizeV, Node);
    }

    return;
}

string Decrypt::BuildTree()
{
    int VectorSize;
    char ch;
    int indicator=0;
    fi>>VectorSize;

    fi.get(ch);
    //VectorSize++;

    Tree_Node* StartNode;

    vector<char> ScanfVect(VectorSize, 2);
    for(int i=0; i<VectorSize; i++)
    {
        fi.get(ch);
        if(2!=ch) {ScanfVect[i]=ch;}
    }
    fi.get(ch);
    string str="";
    while(!fi.eof()) {fi.get(ch); str+=ch;}
    BuildNodes(indicator, ScanfVect, VectorSize, StartNode);

    root = StartNode;


    return str;
}

void Decrypt::Decryption()
{
    //ifstream fo2("result.txt");
    //root = MyTree.GetRoot();
    //Tree_Node* WorkRoot = root;

    string buf = BuildTree();
    Tree_Node* WorkRoot(root);
    cout<<buf<<endl;
    for(int i=0; i<buf.length(); i++)
    {
        for(int j=0; j<8; j++)
        {
            bool b=(buf[i] & (1 << (7-j)));
            cout<<b;
        }
    }
    cout<<"here\n";
    int cou=0, index=0;

    if(NULL!=root) cout<<root->digit<<" "<<root->symbol<<endl;
    //if(NULL!=WorkRoot) cout<<WorkRoot->digit<<" "<<WorkRoot->symbol<<endl;

    //char buf=0;
    //fi.get(buf);
    //cout<<buf<<endl;
    //fi.get(buf);
    //cout<<buf<<endl;
    /*
    while(index < buf.length())
    {
        cout<<buf[index]<<endl;
        bool b = buf[index] & (1<<(7-cou));
        if(b) {WorkRoot = WorkRoot->r; cout<<WorkRoot->symbol<<endl;}
        else {WorkRoot = WorkRoot->l; cout<<WorkRoot->symbol<<endl;}

        if(WorkRoot->l==NULL && WorkRoot->r==NULL)
        {
            fo<<WorkRoot->symbol;
            cout<<WorkRoot->symbol;
            WorkRoot = root;
        }
        ++cou;
        if(cou==8)
        {
            cou=0;
            ++index;
            //++buf;
            //fi.get(buf);
        }
        //++index;
    }
    */
    return;
}
