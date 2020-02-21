#pragma region Constructors

template <typename T>
vector<T>::vector() // constructor
{
  init(0);
}
template <typename T>
vector<T>::vector(int size) // constructor
{
  init(size);
}

template<typename T>
vector<T>::vector(std::initializer_list<T> init_list) 
{
  int index = 0;
  init(init_list.size());
  for (auto& element : init_list)
  {
    arr[index] = element;
    index++;
  }
  cout << "constructed with a " << current_size << "-element list\n";
}

template<typename T>
void vector<T>::init(int input_size)
{

  if (input_size < 0)
  {
    throw std::invalid_argument(" cannot be to a negative number.");
  }
  current_size = input_size;
  arr = new T[current_size];
  //arr is empty, remember to check

}


template <typename T>
int vector<T>::size() const
{
  return current_size;
}

template <typename T>
bool vector<T>::empty() const
{
  return (current_size<=0) ? true : false;
}
template <typename T>
void vector<T>::resize(const int new_size)
{
  //do nothing is same size
  if (new_size != current_size)
  {
    if (new_size < 1)
    {
      throw std::invalid_argument("cannot set size given");
    }
    T* new_arr = new T[new_size];   // allocate a new array on the free store
    current_size = new_size;
    std::copy(arr, arr + new_size, new_arr);

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
