#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <string>

using namespace std;

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"
#include "HaffmanTable.h"
#include "Encrypt.h"
#include "Decrypt.h"

int main()
{
    ValueTable* MyValue = new ValueTable("test.txt");
    Encrypt* MyEncrypt = new Encrypt("result1.txt");
    MyEncrypt->Encryption(MyValue);
    delete MyValue;
    delete MyEncrypt;

    Decrypt* MyDec = new Decrypt("result1.txt", "result.txt");
    MyDec->Decryption();
    delete MyDec;

    return 0;
}

