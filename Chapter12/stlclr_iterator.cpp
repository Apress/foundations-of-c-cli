// stlclr_iterator.cpp

#include <cliext/vector>

using namespace cliext;

int main()
{
   vector<int>^ vec;
   vector<int>::iterator iter;

   vec = gcnew vector<int>(10);

   int count = 0;
   for (iter = vec->begin(); iter != vec->end(); iter++)
   {
      *iter = count++;
      printf("%d\n", *iter);
   }
}
