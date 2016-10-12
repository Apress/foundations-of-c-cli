// stlclr_custom_functor.cpp

#include <cliext\vector>
#include <cliext\map>
#include <cliext\algorithm>
#include <math.h>


using namespace cliext;
using namespace System;

// Function object for printing the value in a single value (nonassociative) collection
template <typename T>
ref class Print1
{

   public:

   Print1() {}

   Print1(Print1% p) {}

   void operator()(T t)
   {
      Console::Write("{0} ", t );
   }
};

// Function object for printing a pair of values in an associative collection
template <typename T1, typename T2>
ref class Print2
{

   public:

   Print2() {}

   Print2(Print2% p) {}

   void operator()(typename map<T1, T2>::generic_value p)
   {
      Console::WriteLine("{0} {1} ", p->first, p->second );
   }
};

int main()
{
   vector<int>^ sqrvec = gcnew vector<int>;
   map<double, double>^ sqrtmap = gcnew map<double, double>;

   for (int i = 1; i < 10; i++)
   {
       sqrvec->push_back( i*i );
       sqrtmap->insert( make_pair( (double) i, sqrtf(i)));
   }

   for_each(sqrvec->begin(), sqrvec->end(), Print1<int>() );
   Console::WriteLine();

   for_each(sqrtmap->begin(), sqrtmap->end(), Print2<double, double>() );

}
