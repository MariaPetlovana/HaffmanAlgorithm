#include "ValueTable.h"

ValueTable::ValueTable(char* NameFile)
{
    m_f.open(NameFile);
}

ValueTable::~ValueTable()
{
    m_f.close();
}

void ValueTable::ReturnValueTable()
{
    m_str = "";
    char ch;

    while(!m_f.eof() && m_f.get(ch))
    {
        ++m_TableMap[ch];
        m_str += ch;
    }
}

string ValueTable::ReturnStr()
{
    return m_str;
}

map<char, int> ValueTable::BuildTable()
{
    ReturnValueTable();
    return m_TableMap;
}
