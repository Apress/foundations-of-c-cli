// stlclr_converting_from_net_to_stlclr.cpp

#include <cliext\map>
#include <cliext\adapter>

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

typedef map<String^, String^> MapType;
typedef MapType::iterator MapIter;
typedef collection_adapter<IDictionary<String^,String^>> AdapterType;
typedef AdapterType::iterator AdapterIter;

int main()
{
   IDictionary<String^, String^>^ dict = gcnew Dictionary<String^, String^>();
   MapType myMap;

   dict->Add( "cat", "small furry animal");
   dict->Add( "dog", "medium-size friendly animal");
   dict->Add( "goat", "large cantankerous animal");

   AdapterType adapter1(dict);

   for (AdapterIter iter = adapter1.begin(); iter != adapter1.end(); ++iter)
   {
       myMap.insert(make_pair((*iter).Key, (*iter).Value));
   }

   for (MapIter iter = myMap.begin(); iter != myMap.end(); ++iter)
   {
       Console::WriteLine("{0} {1} ", (*iter)->first, (*iter)->second );
   }
}
