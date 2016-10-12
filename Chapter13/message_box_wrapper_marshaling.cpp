// message_box_wrapper_marshaling.cpp

#include "native_message_box_class.h"

#include <msclr\marshal.h>

using namespace System;
using namespace msclr::interop;

enum class MessageBoxTypeEnum
{
  OK, OKCANCEL, ABORTRETRYIGNORE,
  YESNOCANCEL, YESNO,
  RETRYCANCEL, CANCELTRYCONTINUE,
  ICONHAND = 0x10,
  ICONQUESTION = 0x20,
  ICONEXCLAMATION = 0x30,
  ICONASTERISK = 0x40,
  TYPEMASK = 0xF,
  ICONMASK = 0xF0
};

public ref class MessageBoxWrapper
{

   MessageBoxClass* nativeMessageBox;
   literal unsigned int maxSize = 1024;

   public:

   MessageBoxWrapper(String^ message, String^ caption, MessageBoxTypeEnum type)
   {
     marshal_context context;
     nativeMessageBox = new MessageBoxClass(
        context.marshal_as<const wchar_t*>(message),
        context.marshal_as<const wchar_t*>(caption),
        static_cast<MessageBoxType>(type));
   }

   property String^ Caption
   {
       String^ get()
       {
           return marshal_as<String^>(nativeMessageBox->GetCaption());
       }
       void set(String^ s)
       {
           marshal_context context;
           nativeMessageBox->SetCaption( context.marshal_as<const wchar_t*>(s) );
       }
   }
   property String^ Message
   {
       String^ get()
       {
           return marshal_as<String^>(nativeMessageBox->GetCaption());
       }
       void set(String^ s)
       {
           marshal_context context;
           nativeMessageBox->SetMessage( context.marshal_as<const wchar_t*>(s) );
       }
   }
   property MessageBoxTypeEnum Type
   {
       MessageBoxTypeEnum get()
       {
           return static_cast<MessageBoxTypeEnum>(nativeMessageBox->GetType());
       }
       void set(MessageBoxTypeEnum t)
       {
           nativeMessageBox->SetType( static_cast<MessageBoxType>( t ));
       }
   }
   int Display()
   {
      if (nativeMessageBox != NULL)
        return nativeMessageBox->Display();
      else return -1;
   }

   ~MessageBoxWrapper()
   {
      this->!MessageBoxWrapper();
   }

   !MessageBoxWrapper()
   {
       delete nativeMessageBox;

   }

};

int main()
{
   MessageBoxWrapper^ wrapper = gcnew MessageBoxWrapper(
      "Do you like this message box?",
      "Managed wrapper message box.",
       MessageBoxTypeEnum::YESNO);
   Console::WriteLine("Message is: {0}", wrapper->Message);
   int result = wrapper->Display();
   Console::WriteLine("Result was {0}", result);
}
