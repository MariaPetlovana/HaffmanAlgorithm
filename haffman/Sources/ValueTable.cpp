#include "ValueTable.h"

void ValueTable::ReturnValueTable(ifstream& f)
{
    m_str = "";
    char ch;

    while(!f.eof() && f.get(ch))
    {
        ++m_TableMap[ch];
        m_str += ch;
    }

    return;
}

string ValueTable::ReturnStr()
{
    return m_str;
}

map<char, int> ValueTable::BuildTable(ifstream& f)
{
    ReturnValueTable(f);
    return m_TableMap;
}
