// pinvoke_marshaling.cpp

#include <msclr\marshal.h>
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;

// note the use of managed equivalents of native types
[DllImport("user32.dll", CharSet=CharSet::Auto)]
int MessageBox(HANDLE, const wchar_t*, const wchar_t*, 
   unsigned int type);

int main()
{
   String^ message = "Hello World!";
   String^ caption = "Win32 Message Box";
   marshal_context context;
   MessageBox(marshal_as<HANDLE>(IntPtr::Zero), context.marshal_as<const wchar_t*>(message),
                            context.marshal_as<const wchar_t*>(caption), 0);
}
