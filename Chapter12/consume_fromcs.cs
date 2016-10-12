// consume_fromcs.cs
// csc /r:stl_exposedtocs.dll consume_fromcs.cs

using N;
using System.Collections.Generic;

class C
{
   public static void Main()
   {
      R r;
      r = new R(20);

      IList<int> list_dotnet = r.Vec;
      foreach (int i in list_dotnet)
      {
         System.Console.Write( i );
      }
      System.Console.WriteLine();
   }

}
