// TaxonLibrary.h
#include <cliext\map>

using namespace System;
using namespace cliext;

public ref class Taxon abstract
{
   public:

   Taxon() {}

   // copy constructor
   Taxon(Taxon% taxon_in) { }

   // destructor
   virtual ~Taxon() {}

   // assignment operator
   Taxon% operator=(Taxon% t) { return *this; }

   // multimap requires the < operator for its sorting operations
   virtual bool operator <(Taxon^ right)
   {
      return Name < right->Name;
   }

   property String^ Name;
};

public ref class Genus : public Taxon
{
   public:

   Genus() { Name = ""; }
   Genus(String^ name_in) { Name = name_in; }
   Genus(Genus% genus_in) { Name = genus_in.Name; }
   Genus% operator=(Genus% g) { Name = g.Name; return *this; }
   virtual ~Genus() {}
};

public ref class Species : public Taxon
{
public:
   Species() { Name = ""; }
   Species(String^ name_in) { Name = name_in; }
   Species(Species% species_in) { Name = species_in.Name; }
   Species% operator=(Species% s) { Name = s.Name; return *this; }
   virtual ~Species() {}
};

typedef multimap<Genus^, Species^> SpeciesMap1;
typedef multimap<Genus, Species> SpeciesMap2;

public ref class Trees
{
   SpeciesMap1^ speciesMap1;
   public:

   Trees()
   {
      speciesMap1 = gcnew SpeciesMap1();
   }

   bool Add(Genus^ genus, Species^ species)
   {
      speciesMap1->insert (make_pair(genus, species));
      return true;
   }

   // Iterate over the collection using STL/CLR iterators
   void PrintAll()
   {
      SpeciesMap1::iterator iter1;
      for (iter1 = speciesMap1->begin(); iter1 != speciesMap1->end(); ++iter1)
      {
         Console::WriteLine("{0} {1}", iter1->first->Name, iter1->second->Name);
      }
   }

   // Iterate over the collection using generic iterators
   void PrintAllGeneric()
   {
      // Declare a generic iterator for this collection
      SpeciesMap1::generic_iterator generic_iter1;

      // Get a generic version of the container using the generic_container typedef
      // and using the implicit conversion from the container to
      // the generic_container type
      SpeciesMap1::generic_container^ generic_container1 = speciesMap1;
      for (generic_iter1 = generic_container1->begin();
           generic_iter1 != generic_container1->end();
           ++generic_iter1)
      {
         SpeciesMap1::generic_value val = *generic_iter1;
         Console::WriteLine("{0} {1}", generic_iter1->first->Name, generic_iter1->second->Name);
      }
   }

};
