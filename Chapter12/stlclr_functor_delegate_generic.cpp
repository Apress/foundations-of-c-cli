// stlclr_functor_delegate_generic.cpp

#include <cliext\functional>

using namespace cliext;
using namespace System;

int main()
{
   less<int> func;

   // delegate_type is a Microsoft::VisualC::StlClr::BinaryDelegate generic
   less<int>::delegate_type^ dlg = func;

   int a = 100;
   int b = 200;

   // Call the functor
   Console::WriteLine("{0} < {1}? {2}", a, b, func(a, b));

   // Call the generic delegate
   Console::WriteLine("{0} < {1}? {2}", a, b, dlg(a, b));
}
