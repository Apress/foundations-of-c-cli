// stl_simple2.cpp

#include <list>

using namespace std;
using namespace System;

typedef list<String^> StringList;
typedef StringList::iterator StringListIter;

int main()
{
   StringList list;
   StringListIter iter;

   list.insert( list.end(), "first" );
   list.insert( list.end(), "second" );
   list.insert( list.end(), "third" );

   for (iter = list.begin(); iter != list.end(); iter++)
   {
       Console::WriteLine( *iter );
   }

}
