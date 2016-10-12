// interface_method_on_stlclr_collection.cpp


#include <cliext\vector>

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

int main()
{
   vector<int>^ v = gcnew vector<int>(10);

   for (int i = 0; i < 10; i++)
   {
       (*v)[i] = i;
   }

   ICollection<int>^ collection = (ICollection<int>^) v;

   collection->Add(11);  // OK


   for each (int i in collection)
   {
        Console::Write("{0} ", i);
   }
}
