// stlclr_vector_assembly1.cpp

#include <cliext\vector>

using namespace cliext;

typedef vector<int> VectorAssembly1;

public ref class UsesVector
{
   private:
      VectorAssembly1^ m_vec;

   public:

   UsesVector() { m_vec = gcnew VectorAssembly1(); }

   // produces compiler warning since VectorAssembly1 is private
   VectorAssembly1^ GetVectorTemplate() { return m_vec; }

   VectorAssembly1::generic_container^ GetVectorGeneric() { return m_vec; }
};
