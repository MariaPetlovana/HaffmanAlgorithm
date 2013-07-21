#include "Tree_Node.h"
#include "Tree.h"
#include "ValueTable.h"
#include "HaffmanTable.h"
#include "AbstractEnDecrypt.h"
#include "Encrypt.h"
#include "Decrypt.h"
#include "WriteVector.h"
#include "BuildTreeFromVector.h"

int main()
{
    Encrypt* MyEncrypt = new Encrypt("test.txt", "result1.txt");
    MyEncrypt->EnDecryption();
    delete MyEncrypt;

    Decrypt* MyDec = new Decrypt("result1.txt", "result.txt");
    MyDec->EnDecryption();
    delete MyDec;

    return 0;
}

