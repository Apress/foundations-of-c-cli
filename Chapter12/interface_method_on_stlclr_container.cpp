// interface_method_on_stlclr_container.cpp
#include <cliext\vector>
using namespace cliext;
using namespace System;

int main()
{
   vector<int>^ v = gcnew vector<int>(10);
   for (int i = 0; i < 10; i++)
   {
       (*v)[i] = i;
   }
   v->Add(11);  // Error: candidate function not accessible
   for each (int i in v)
   {
        Console::Write("{0} ", i);
   }
}
