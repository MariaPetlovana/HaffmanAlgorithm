#ifndef VALUETABLE_H_INCLUDED
#define VALUETABLE_H_INCLUDED

#include "Table.h"

class ValueTable: public Table<char, int>
{
    protected:
        string m_str;
        ifstream m_f;

        void ReturnValueTable();

    public:
        ValueTable(char* NameFile);
        ~ValueTable();

        string ReturnStr();
        virtual map<char, int> BuildTable();
};

#endif // VALUETABLE_H_INCLUDED
