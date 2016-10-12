// hello_interop.cpp

#include <stdio.h>
#include <string>

class HelloNative
{
   private:
      // string is a Stanard C++ class (actually a typedef for basic_string<char>) 
      // where each character is represented by a char
     std::string* s;

   public:   
     HelloNative()
     {
       s = new std::string("Hello from native type!");
     }
     void Greeting()
     {
        // The C++ basic_string class contains a method that returns a
        // “C string” of type “const char *” for the C runtime function printf.
        printf("%s\n", s->c_str());
     }
     ~HelloNative()
     {
        delete s;
     }
};

ref class HelloManaged
{
   private:
     System::String^ s;

   public:
     HelloManaged()
     {
        s = "Hello from managed type!";
     }
     void Greeting()
     {
        System::Console::WriteLine("{0}", s);
     }
};

int main()
{
   HelloNative* helloNative = new HelloNative();
   HelloManaged^ helloManaged = gcnew HelloManaged();
   
   helloNative->Greeting();
   helloManaged->Greeting();
}
