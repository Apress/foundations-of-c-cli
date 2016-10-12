The code in this folder supports the book "Foundations of C++/CLI: The Visual C++ Language for .NET"
(Apress, 2008).

The code is intended to compile with Visual Studio 2008 and .NET 3.5.  In most cases, the following
command line will compile each .cpp file:

cl /clr filename.cpp

Most of the code will also compile with other variations of the /clr compiler option, including /clr:pure
and /clr:safe.  For details, see the text.

If the compilation command line differs from the above, the correct command line is given in the code. For
example, many samples produce a DLL instead of an EXE, in which case the /LD command line option is used.

Not all numbered code snippets in the book appear in this set of files.  If a code snippet in the book is
not included here, it may be that the code snippet is part of another snippet, or in a few cases, the code
may be from a library or system header file.

Executing the code that results from the compilation should produce the output in the book.

This code is intended to be executed and compiled on a single development machine.  Executing code on
a different machine than the machine where you compiled it is referred to as deployment. These rules
are described in the Visual C++ documentation.



 