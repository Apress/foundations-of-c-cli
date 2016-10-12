// stlclr_make_vector.cpp

#include <cliext\vector>

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

typedef vector<int> IntVector;
typedef vector<int>::iterator IntVectorIter;

int main()
{

    List<int>^ intList = gcnew List<int>();


    for (int i = 0; i < 20; i++)
    {
       intList->Add(i);
    }

    IntVector vec(intList);

    for each (int i in vec)
    {
        Console::Write("{0} ", i);
    }
    Console::WriteLine();
}
