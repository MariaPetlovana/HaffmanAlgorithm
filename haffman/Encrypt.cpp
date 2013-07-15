#include "Encrypt.h"

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"
#include "HaffmanTable.h"
#include <vector>
#include "Decrypt.h"

void Encrypt::Encryption(ValueTable* Value)
{
    int cou=0;
    char buf=0;

    //ofstream fo(NameFileTo);

    Tree MyTree;

    MyTree.CreateTree(MyTree.BuildNodes(Value->BuildTable()));
    HaffmanTable MyHaf(MyTree.GetRoot());

    string str=Value->ReturnStr();

    map<char, vector<bool> > HafTable = MyHaf.BuildTable();
    cout<<"bools"<<endl;
    for(map<char, vector<bool> >::iterator iter=HafTable.begin(); iter!=HafTable.end(); iter++)
    {
        cout<<(*iter).first<<" ";
        for(vector<bool>::iterator it=(iter->second).begin(); it!=(iter->second).end(); it++)
        cout<<*it;
        cout<<endl;
    }

    MyHaf.WriteVector(output);

    for(int i=0; i<str.length(); i++)
    {
        //char ch=str[i];
        vector<bool> v=HafTable[str[i]];
        for(int j=0; j<v.size(); j++)
        {
            //cout<<v[j];
            buf=buf | v[j]<<(7-cou);
            cou++;
            if(cou==8)
            {
                cou=0;
                output<<buf;
                buf=0;
            }
        }
        //if(cou)
        //{
          //  cou=0;
          //  fo<<buf;
          //  buf=0;
        //}
        //fo<<v[j];
    }
    /*if(cou)
    {
        cou=0;
        output<<buf;
        buf=0;
    }*/


    //Decrypt MyDec("result1.txt", "result.txt");
    //MyDec.Decryption(MyTree);

    return;
}

