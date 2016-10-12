// stlclr_exposedtocs.cpp
// compile with: stlclr_exposedtocs.cpp /clr:pure /LD

#include <cliext\vector>

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

namespace N
{

public ref class R
{
   private:

      vector<int>^ m_vec;

   public:

   R(int initial_size)
   {
      // Create a vector
      m_vec = gcnew vector<int>(initial_size);
      // Populate it
      for (int i = 0; i < initial_size; i++)
      {
         m_vec[i] = i;
      }
   }

   // The property to be accessed from C# cannot directly be the STL/CLR
   // vector type,
   // since that type is assembly-private and cannot be used in a public interface
   property IList<int>^ Vec
   {
      IList<int>^ get() { return m_vec; }
   }

};

}
