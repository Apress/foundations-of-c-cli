// stlclr_reverse_vector.cpp

#include <cliext\vector>
#include <cliext\list>

using namespace System;
using namespace cliext;

// version 1.0 : vector used as an array
void reverse1(vector<int>% vec)
{
   int n = vec.size();
   for (int i = 0; i < n / 2; i++)
   {
       int temp = vec[n - i - 1];
       vec[n - i - 1] = vec[i];
       vec[i] = temp;
   }
}

// version 2.0: iterators used
void reverse2(vector<int>% vec)
{
   vector<int>::iterator iter = vec.begin();
   vector<int>::reverse_iterator reverse_iter = vec.rbegin();

   for (int i = 0; i < vec.size() / 2; ++iter, ++reverse_iter, ++i)
   {
       int temp = *reverse_iter;
       *reverse_iter = *iter;
       *iter = temp;
   }
}

void printall(vector<int>% vec)
{
   vector<int>::iterator iter = vec.begin();
   for (; iter != vec.end(); ++iter)
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
   reverse1(v);
   printall(v);

}
