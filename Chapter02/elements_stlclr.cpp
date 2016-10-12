// elements_stlclr.cpp

#include <cliext/map>

using namespace cliext;  // for STL/CLR
using namespace std;   // for
using namespace System;

typedef map<String^, int> PeriodicTable;

int main()
{
   PeriodicTable elementTable;
   elementTable.insert(PeriodicTable::make_value("Hydrogen", 1));
   elementTable.insert(PeriodicTable::make_value("Helium", 2));

   for each( PeriodicTable::value_type element in elementTable)
   {
      Console::WriteLine("{0} {1}", element->first, element->second);
   }

}
