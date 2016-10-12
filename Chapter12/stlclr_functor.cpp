// stlclr_functor.cpp

#include <cliext\functional>

using namespace cliext;
using namespace System;

int main()
{
   less<int> func;

   int a = 100;
   int b = 200;


   Console::WriteLine("{0} < {1}? {2}", a, b, func(a, b));
}
