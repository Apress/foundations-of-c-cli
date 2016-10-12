// stlclr_algorithm_on_net_collection.cpp

#include <cliext\algorithm>
#include <cliext\adapter>

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

typedef collection_adapter<IDictionary<String^,String^>> AdapterType;
typedef AdapterType::iterator AdapterIter;

// function object
ref class Print
{

   public:

   Print() {}

   Print(Print% p) {}

   void operator()(KeyValuePair<String^, String^>% kvp)
   {
      Console::WriteLine("{0} {1} ", kvp.Key, kvp.Value );
   }
};

int main()
{
   IDictionary<String^, String^>^ dict = gcnew Dictionary<String^, String^>();

   dict->Add( "cat", "small furry animal");
   dict->Add( "dog", "medium-size friendly animal");
   dict->Add( "goat", "large cantankerous animal");
   dict->Add( "turtle", "small reclusive reptile");

   AdapterType adapter1(dict);
   for_each(adapter1.begin(), adapter1.end(), Print() );
}
