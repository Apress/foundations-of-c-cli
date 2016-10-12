// appdomain_execute_assembly.cpp

using namespace System;

int main()
{
   try
   {
      String^ exeName;
      AppDomain^ appDomain = AppDomain::CreateDomain("Reflection2");
      Console::Write("Enter a pure or safe executable to execute:");
      exeName = Console::ReadLine();      
      Console::WriteLine("Executing assembly {0}", exeName);

      // You must compile the example program with the /clr:pure or /clr:safe option
      appDomain->ExecuteAssembly(exeName);
   }
   catch(Exception^ e)
   {
      Console::WriteLine("{0} {1}", e->Message, e->StackTrace);
   }

   Console::WriteLine("Finished.");
}