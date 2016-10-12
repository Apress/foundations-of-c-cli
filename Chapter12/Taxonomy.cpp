// Taxonomy.cpp : main project file.

#include "TaxonLibrary.h"
using namespace System;

int main(array<System::String ^> ^args)
{
   Trees^ trees = gcnew Trees();
   trees->Add(gcnew Genus("Quercus"), gcnew Species("rubra"));
   trees->Add(gcnew Genus("Quercus"), gcnew Species("garryana"));
   trees->Add(gcnew Genus("Pseudotsuga"), gcnew Species("menziesii"));
   // print, using normal STL/CLR iterators
   trees->PrintAll();
   return 0;
}
