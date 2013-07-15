#include "ValueTable.h"
//#include <map>

//using namespace std;

void ValueTable::ReturnValueTable()
{
    str="";
    char ch;

    while(!f.eof() && f.get(ch))
    {
        ++TableMap[ch];
        str+=ch;
    }
}

string ValueTable::ReturnStr()
{
    return str;
}

ValueTable::ValueTable(char* NameFile)
{
    f.open(NameFile);
}

map<char, int> ValueTable::BuildTable()
{
    ReturnValueTable();
    for(map<char, int>::iterator iter=TableMap.begin(); iter!=TableMap.end(); iter++)
    cout<<(*iter).first<<" "<<(*iter).second<<endl;
    return TableMap;
}
