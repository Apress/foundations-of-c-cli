// managed_multidimensional_array_as_parameter.cpp

// g takes an array of 5 arrays 2 x 3 in size
void g(array<int,3>^ a)
{
   
}

int main()
{
   array<int,3>^ managed_3d_array1 = gcnew array<int,3>(5, 2, 3);
   array<int,3>^ managed_3d_array2 = gcnew array<int, 3>(15, 2, 3);

   g(managed_3d_array1);
   g(managed_3d_array2);  
}
