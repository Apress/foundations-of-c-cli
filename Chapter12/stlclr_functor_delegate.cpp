// stlclr_functor_delegate.cpp

#include <cliext\functional>

using namespace cliext;
using namespace System;

template <typename T>
bool IsLessThan(T a, T b)
{
   return a < b;
}

// managed template delegate type
typedef binary_delegate<int, int, bool> MyDelegate;

int main()
{
   MyDelegate^ func = gcnew MyDelegate(&IsLessThan<int>);

   int a = 100;
   int b = 200;

   // call managed template delegate
   Console::WriteLine("{0} < {1}? {2}", a, b, func(a, b));
}
