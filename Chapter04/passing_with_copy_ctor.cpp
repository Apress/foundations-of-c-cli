// passing_with_copy_ctor.cpp
using namespace System;

ref class R
{
   int val;
   String^ str;

   public:

    property int Value
    {
       int get() { return val; }
       void set(int i) { val = i; }
    }
    property String^ Label
    {
       String^ get() { return str; }
       void set(String^ s) { str = s; }
    }

   R(int val_in, String^ label) : val(val), str(label)
   { }

    R(const R% r)
    {
         // Copy the elements of R.
         // Value is a value type, so it gets copied.
         val = r.val;
         // Strings in C++/CLI are immutable, so even though this does not copy the object
         // (it only copies a reference to the object), this is OK here 
         str = r.str;
    }
};

