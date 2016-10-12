template <typename T>
void reverse3(vector<T>% vec)
{
   vector<T>::iterator iter = vec.begin();
   vector<T>::reverse_iterator reverse_iter = vec.rbegin();

   for (int i = 0; i < vec.size() / 2; ++iter, ++reverse_iter, ++i)
   {
      int temp = *reverse_iter;
      *reverse_iter = *iter;
      *iter = temp;
   }
}
