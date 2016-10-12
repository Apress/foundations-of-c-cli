// stl_simple1.cpp

#include <list>
#include <string>
#include <iostream>

using namespace std;

typedef list<string> StringList;
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
       cout << *iter << endl;
   }

}
