// stlclr_make_collection.cpp

#include <cliext\vector>
#include <cliext\adapter> // for make_collection

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

typedef vector<int> IntVector;
typedef vector<int>::iterator IntVectorIter;

int main()
{

    IntVector vec;
    for (int i = 0; i < 20; i++)
    {
       vec.push_back(i);
    }

    ICollection<int>^ collection =
      make_collection<IntVectorIter>(vec.begin(), vec.end());

    for each (int i in collection)
    {
        Console::Write("{0} ", i);
    }
    Console::WriteLine();
}
