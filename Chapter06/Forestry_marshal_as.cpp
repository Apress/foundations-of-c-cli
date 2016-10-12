// Forestry.cpp

#include <msclr\marshal.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;

// a native class
class PlantData
{
   private:

   wchar_t* family;
   wchar_t* genus;
   wchar_t* species;

   public:

   PlantData(const wchar_t* botanical_name)
   {
       // Let's assume this method
       // populates its
       // fields with data from the database
   }

};

// The following managed class contains a pointer to a native class.

ref class TreeSpecies
{
   PlantData* treedata;

   public:
     TreeSpecies(String^ genus, String^ species)
     {
         String^ botanicalName = gcnew String(genus + " " + species);
         marshal_context context;
         const wchar_t* str = context.marshal_as<const wchar_t*>(botanicalName);
         treedata = new PlantData(str);

     }

     ~TreeSpecies() { this->!TreeSpecies(); }
     !TreeSpecies() { if (treedata) delete treedata; }
};
