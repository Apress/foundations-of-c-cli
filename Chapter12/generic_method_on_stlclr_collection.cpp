// generic_method_with_stlclr_collection.cpp

#include <cliext\vector>

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

generic <typename CollectionType, typename ItemType>
where CollectionType : IList<ItemType>
void Reverse(CollectionType collection)
{

   int n = collection->Count;
   for (int i = 0; i < n; i++)
   {
      ItemType temp = collection->default[n - i];
      collection->RemoveAt(n - i);
      collection->Add(temp);
   }

}

int main()
{
   vector<int>^ v = gcnew vector<int>(10);

   for (int i = 0; i < 10; i++)
   {
       (*v)[i] = i;
   }

   Reverse<vector<int>^, int>(v);

   for each (int i in v)
   {
        Console::Write("{0} ", i);
   }

}
