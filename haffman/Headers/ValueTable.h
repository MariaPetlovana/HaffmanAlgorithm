#ifndef VALUETABLE_H_INCLUDED
#define VALUETABLE_H_INCLUDED

#include <string>
#include <map>
#include <fstream>

using namespace std;

class ValueTable
{
    protected:
        string m_str;
        map<char, int> m_TableMap;

        void ReturnValueTable(ifstream& f);

    public:
        //returns encoded string
        string ReturnStr();

        //builds frequent table of values
        virtual map<char, int> BuildTable(ifstream& f);
};

#endif // VALUETABLE_H_INCLUDED
