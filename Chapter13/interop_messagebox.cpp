// interop_messagebox.cpp

#include <windows.h>
//#include <vcclr.h> // for PtrToStringChars
#include <msclr\marshal.h>

using namespace System;
using namespace msclr::interop;

public ref class MessageBoxClass
{
   public:

   property String^ Message;
   property String^ Caption;

   int DisplayBox()
   {
      marshal_context context;
      /*// Use pinning pointers to lock down the data while it's being
      // used in native code.
      pin_ptr<const wchar_t> message = PtrToStringChars(Message);
      pin_ptr<const wchar_t> caption = PtrToStringChars(Caption);*/
      return MessageBoxW( 0, context.marshal_as<const wchar_t*>(Message),
                             context.marshal_as<const wchar_t*>(Caption), MB_OK);
   }
};

int main()
{
   MessageBoxClass m;
   m.Message = "Managed string used in native function";
   m.Caption = "Managed Code using Win32 Message Box";
   m.DisplayBox();
}
