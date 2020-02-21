


template<typename T>
ostream& operator << (ostream& os, const vector<T> & Obj)
{

   for (auto x : Obj)
   {
     os << x << " ";
   }
  return os;
}
