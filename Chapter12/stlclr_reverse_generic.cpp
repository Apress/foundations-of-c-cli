// stlclr_reverse_generic.cpp

#include <cliext\vector>
#include <cliext\list>

using namespace System;
using namespace cliext;

template <typename collection_type>
void reverse4(collection_type% coll)
{
   collection_type::iterator iter = coll.begin();
   collection_type::reverse_iterator reverse_iter = coll.rbegin();

   for (int i = 0; i < coll.size() / 2; ++iter, ++reverse_iter, ++i)
   {
       collection_type::value_type temp = *reverse_iter;
       *reverse_iter = *iter;
       *iter = temp;
   }
}

template <typename collection_type>
void printall(collection_type% coll)
{
   collection_type::iterator iter = coll.begin();
   for (; iter != coll.end(); ++iter)
   {
       Console::Write("{0} ", *iter);
   }
   Console::WriteLine();
}

int main()
{
   vector<int> v;
   for (int i = 0; i < 5; i++)
   {
      v.push_back(i);
   }

   printall(v);
   reverse4(v);
   printall(v);

   list<String^> stringList;
   for (int i = 0; i < 5; i++)
   {
      stringList.push_back( i.ToString());
   }

   printall(stringList);
   reverse4(stringList);
   printall(stringList);

}
