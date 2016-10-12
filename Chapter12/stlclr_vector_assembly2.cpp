// stlclr_vector_assembly2.cpp

#include <cliext\vector>

#using "stlclr_vector_assembly1.dll"

using namespace cliext;

typedef vector<int> VectorAssembly2;

int main()
{
   UsesVector^ usesVector = gcnew UsesVector();

   // Error: candidate function not accessible
   VectorAssembly2^ vec1 = usesVector->GetVectorTemplate();

   VectorAssembly2::generic_container^ vec2 = usesVector->GetVectorGeneric();
}
