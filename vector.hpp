
#pragma region Constructors

template <typename T>
vector<T>::vector(int size) // constructor
{
  //check if invalid size
  if (size < 0)
  {
    throw std::invalid_argument(" cannot set out of bounds.");
  }
  current_size = size;
  arr = new double[current_size];
  //arr is empty, remember to check
}

template <typename T>
int vector<T>::size() const
{
  return current_size;
}
template <typename T>
void vector<T>::resize(const int new_size)
{
  //do nothing is same size
  if (new_size != current_size)
  {
    if (new_size < 1)
    {
      throw std::bad_alloc("cannot set size given");
    }
    T* new_arr = new T[new_size];   // allocate a new array on the free store

    int difference = new_size - current_size;

    //new size can be lower or higher
    difference = new_size - current_size;
    std::copy(current_size, current_size + difference, new_arr.begin());

    delete[] arr;                       // delete the old vector
    arr = new_arr;
  }

}

#pragma endregion
template<typename T>
vector<T>::~vector()
{       // destructor
  delete[] arr;
}

template <typename T>
void vector<T>::set(int i, T val)
{
  if (i < 0 || i >= current_size)
  {
    throw std::range_error(" cannot set out of bounds.");
  }
  arr[i] = val;
}

template <typename T>
T vector<T>::get(int i) const
{
  if (i < 0 || i >= current_size)
  {
    throw std::range_error(" cannot set out of bounds.");
  }
  return arr[i];
}
//iterators

template<typename T>
Iter<T> vector<T>::begin() const
{
  return Iter<T>(this, 0);
}

template<typename T>
Iter<T> vector<T>::end() const
{
  return Iter<T>(this, current_size);
}

//
template<typename T>
ostream& operator << (ostream& os, const vector<T>& Obj)
{

   for (auto x : Obj)
   {
     os << x << " ";
   }
  return os;
}
