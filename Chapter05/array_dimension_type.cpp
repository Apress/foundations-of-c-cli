// array_dimension_type.cpp

void f(int a[][2][3]) { }

void g(int a[5][2][3]) { }

int main()
{
   int native_3d_array[5][2][3];
   int native_3d_array2[15][2][3];

   f(native_3d_array);
   f(native_3d_array2);
   g(native_3d_array);
   g(native_3d_array2);
}
