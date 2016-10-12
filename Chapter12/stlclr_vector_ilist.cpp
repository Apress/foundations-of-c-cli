// stlclr_vector_ilist.cpp

#include <cliext\vector>

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

int main()
{
   // Create a vector with initial size 10 elements

   vector<int> v(10);

   // Use the vector like an array

   for (int n = 1, i = 0; n < 1024; i++, n *= 2)
   {
      v[i] = n;
   }

   // Retrieve elements using .NET Framework IList interface

   IList<int>^ list = (IList<int>^) %v;

   for each (int i in list)
   {
      Console::WriteLine("{0} ", i );
   }

}
