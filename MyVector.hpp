#include "MyVector.h"
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

//array of refernce not allowed
template <typename T>
vector<T>::vector(const T* input_array, const int input_size) // constructor
{
  //cout << "array Constructor" << std::endl;
  init(input_size);
  std::copy(input_array, input_array + current_size, arr);
}
template<typename T>
vector<T>::vector(std::initializer_list<T> init_list)
{
  int index = 0;
  init(init_list.size());
  for (auto element : init_list)
  {
    arr[index] = element;
    index++;
  }
  //cout << "constructed with a " << current_size << "-element list\n";
}

template<typename T>
vector<T>::vector(const vector<T>& otherVector)
{
  //cout << "Copy Constructor" << std::endl;
  //cout << "Size: " << otherVector.current_size << std::endl;
  init(otherVector.current_size);
  std::copy(otherVector.arr, otherVector.arr + otherVector.current_size, arr);
  name = name + "-";
}

template<typename T>
void vector<T>::init(int input_size)
{
  if (input_size < 0)
  {
    //cout << "input_size: " << input_size << std::endl;
    throw std::invalid_argument(" cannot be to a negative number.");
  }
  current_size = input_size;
  arr = new T[current_size];

}



#pragma endregion

template <typename T>
int vector<T>::size() const
{
  return current_size;
}

template <typename T>
bool vector<T>::empty() const
{
  return (current_size <= 0) ? true : false;
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

#pragma region Overloads

template<typename T>
istream& operator >> (istream& finput, vector<T>& Obj)
{
  //clears out entire vector
  //check for invalid range

  string temp_input;
  std::getline(finput, temp_input);
  //run until non empty line has been found.
  while (temp_input.length() == 0)
  {
    std::getline(finput, temp_input);
  }
  std::istringstream tokenStream(temp_input);


  
  std::istream_iterator<T> eos;              // end-of-stream iterator
  std::istream_iterator<T> iit(tokenStream);   // stdin iterator
  int size = 0;
  //getsize first
  while (iit != eos)
  {
    size++;
    ++iit;
  }
  int index = 0;
  T* new_arr = new T[size];
  //restart and put into new array; done backwards
  tokenStream = std::istringstream(temp_input);//reset stream
  iit = std::istream_iterator<T>(tokenStream);
  //get contents
  while (iit != eos)
  {
    new_arr[index] = *iit;
    index++;
    ++iit;
  }
  Obj = vector<T>(new_arr, size);
  delete[] new_arr;


  return finput;
}


template<typename T>
const T vector<T>::operator [] (const int index_var) const
{
  if (current_size == 0)
  {
    throw std::range_error(" vector is empty");
  }

  if (index_var < 0 || index_var >= current_size)
  {
    throw std::range_error(" cannot set out of bounds.");
  }
  return arr[index_var];
}
/*
  @pre T must define == (unary operator)
  @pre T must define = (assingment operator)
  @post returns element at position itr if 
*/
template<typename T>
T& vector<T>::operator [] (const int index_var)
{

  if (index_var < 0 || index_var >= current_size)
  {
    throw std::range_error(" cannot set out of bounds.");
  }
  return arr[index_var];
}

/*
  UNARY OPERATOR
  @pre T must define - (unary operator)
*/
template<typename T>
vector<T> vector<T>::operator-() const
{
  //check if vector is empty;
  T* new_complementarr = new T[current_size];

  for (int i = 0; i < current_size; i++)
  {
    new_complementarr[i] = -(arr[i]);
  }
  vector<T> v = vector<T>(new_complementarr, current_size);
  delete [] new_complementarr;
  return v;
}

template<typename T>
vector<T> vector<T>::apply(std::function<T(T)> & f)
{

  T* new_arr = new T[current_size];
  for (int i = 0; i < current_size; i++)
  {
    new_arr[i] = f(arr[i]);
  }


  vector<T> v = vector<T>(new_arr, current_size);
  delete[] new_arr;

  return v;
}

template<typename T>
vector<T>& vector<T>::operator = (const vector<T> & source)
{
  if (this != &source)
  {
	if (arr != NULL)
	{
		delete[] arr;
	}
    cout << "COPYYING VECTOR" <<std:: endl;
    current_size = source.current_size;
    init(current_size);
    //std::copy(source.arr, source.arr + source.current_size, arr);
    for (int i = 0; i < current_size; ++i)  // copy old vector into new one
    {
        arr[i] = source.arr[i];
    }
    name = source.name + "+++";
  }
  return *this;
}

template<typename T>
vector<T>::~vector()
{       // destructor
  cout << "Deleting: " << name<<std::endl;
  delete[] arr;
  /*
  if (arr != NULL)
  {

    for (int i = 0; i < current_size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << "----------" << std::endl;
    delete[] arr;
  }*/
}


template<typename T>
ostream& operator << (ostream& os, const vector<T>& Obj)
{

  for (auto x : Obj)
  {
    os << x << " ";
  }
  return os;
}

template<typename T>
vector<T> operator+(const vector<T>& lhs, const vector<T>& rhs)
{
  char symbol = '+';
  return vector<T>::operatorhandler(lhs.arr, rhs.arr, symbol,lhs.current_size,
    rhs.current_size);
}
template<typename T>
vector<T> operator-(const vector<T>& lhs, const vector<T>& rhs)
{
  char symbol = '-';
  return vector<T>::operatorhandler(lhs.arr, rhs.arr, symbol, lhs.current_size,
    rhs.current_size);
}

/*
  @Pre += operator must be defined
*/
template<typename T>
T operator*(const vector<T>& lhs, const vector<T>& rhs)
{
  char symbol = '*';
  vector<T> vTemp = vector<T>::operatorhandler(lhs.arr, rhs.arr, symbol,
    lhs.current_size, rhs.current_size);
  //now add them all up together
  T result = vTemp[0];
  //add up rest
  for (int i = 1; i < vTemp.current_size; i++)
  {
    result += vTemp[i];
  }
  return result;

}

template<typename T>
vector<T> operator*(const T& lhsScalar, const vector<T>& rhs)
{
  if (rhs.current_size <0)
  {
    throw std::invalid_argument("vector size is < 0");
  }
  char symbol = '*';
  int size = rhs.current_size;
  T* new_arr = new T[size];
  for (int i = 0; i < size; i++)
  {
    new_arr[i] = lhsScalar;
  }
  vector<T> v = vector<T>::operatorhandler(new_arr, rhs.arr, symbol, size, size);
  delete[] new_arr;
  return v;
}

template<typename T>
vector<T> operator*(const vector<T>& lhs, const  T& rhsScalar)
{
  if (lhs.current_size < 0)
  {
    throw std::invalid_argument("vector size is < 0");
  }

  char symbol = '*';
  int size = lhs.current_size;
  T* new_arr = new T[size];
  for (int i = 0; i < size; i++)
  {
    new_arr[i] = rhsScalar;
  }
  vector<T> v = vector<T>::operatorhandler(lhs.arr, new_arr, symbol, size, size);
  delete[] new_arr;
  return v;
}


template<typename T>
vector<T> vector<T>::operatorhandler(const T lhsarr[], const T rhsarr[],
  char& symbol, const int leftsize, const int rightsize)
{
  //check if empty
  if (leftsize != rightsize)
  {
    throw std::invalid_argument("array sizes are unequal");
  }
  int size = leftsize;
  T* new_arr = new T[size];
  for (int i = 0; i < size; i++)
  {
    new_arr[i] = handleMath(symbol, lhsarr[i], rhsarr[i]);
  }
  vector<T> v = vector<T>(new_arr, size);
  delete[] new_arr;
  return v;
}


template<typename T>
T vector<T>::handleMath(char symbol,T left, T right)
{
  T result;
  switch (symbol)
  {
    case '+':
      result = left + right;
      break;
    case '-':
      result = left - right;
      break;
    case '*':
      result = (left * right);
      break;
    default:
      throw std::invalid_argument("symbol not found");
  }
  //cout <<symbol<<":"<< result << std::endl;
  return result;


}
#pragma endregion

template<typename T>
T* vector<T>::begin() const
{
  return current_size > 0 ? &arr[0] : nullptr;
}

template<typename T>
T* vector<T>::end() const
{
  return current_size > 0 ? &arr[current_size-1] : nullptr;
}

/*
template<typename T>
int vector<T>::operator* () const
{
  return (i < 0 || i >= current_size) ? &arr[0] : nullptr;

}*/
//iterators
/*
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

template<typename T>
T vector<T>::get(int i) const
{
  if (i < 0 || i >= current_size)
  {
    throw std::range_error(" cannot set out of bounds.");
  }
  return arr[i];
}

*/