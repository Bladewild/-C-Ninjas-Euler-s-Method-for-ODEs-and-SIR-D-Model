#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>
#include <initializer_list>
#include <iterator>
#include <string>
#include <sstream> 
#include <functional>

using std::string;
using std::ostream;
using std::cout;
using std::istream;

template<typename T>
class vector;

template<typename T>
class Iter
{
public:
  Iter(const vector<T>* p_vec, int pos)
    : _pos(pos)
    , _p_vec(p_vec)
  { }

  // these three methods form the basis of an iterator for use with
  // a range-based for loop
  bool operator!= (const Iter& other) const
  {
    return _pos != other._pos;
  }

  // this method must be defined after the definition of vector<T>
  // since it needs to use it
  int operator* () const;

  const Iter& operator++ ()
  {
    ++_pos;
    // although not strictly necessary for a range-based for loop
    // following the normal convention of returning a value from
    // operator++ is a good idea.
    return *this;
  }

private:
  int _pos;
  const vector<T>* _p_vec;
};

template<typename T>
class vector
{
private:
  T* arr; // pointer to the first element of the underlying array
  int current_size;       // size of this myvec

  /*!
  * @brief initializes array
  * @param[in]  input_size integer
  * @pre  input_size is non negative
  * @post creates new array specified by input_size
  * @throw invalid_argument if input_size is negative
  */

  void init(int input_size);


  /*!
  * @brief  
  * @param[in] 
  * @pre  
  * @post
  * @throw
  */

  static T handleMath(char symbol,T left, T right);

  /*!
  * @brief  
  * @param[in] 
  * @param[out] 
  * @pre  
  * @post
  * @throw
  */

  static vector<T> operatorhandler(const T lhsarr[], 
  const T rhsarr[], char& symbol,const int leftsize,const int rightsize);
public: 

  string name="default";       // size of this myvec
  /*!
  * @brief Default Constructor, runs init(0)
  * @post create empty vector of size 0
  */

  vector(); 

  /*!
  * @brief Constructs vector of specificied size
  * @param[in] size of int
  * @pre size cannot be negative
  * @post creates vector of specified size
  */

  explicit vector(int size); // constructor

  /*!
  * @brief  makes a new vector from given array
  * @param[in] input_array array to replace current arr
  * @param[in] input_size size of array
  * @pre  input_array is not empty
  * @pre  input_size is the same size as array
  * @post initiliaze new array, given input_array size
  * @post copy over input_array to initialized array
  * @note array size cannot be found, must be passed
  */

  vector(const T * input_array, const int input_size); // constructor

  /*!
  * @brief creates vector from initializer list
  * @param[in]  initializer_list<T>
  * @post copies elements from init_list to index in order
  */

  vector(std::initializer_list<T> l);

  /*!
  * @brief  copy constructor
  * @param[in]  otherVector 
  * @pre  otherVector must have pass init() preconditions
  * @post copies contents of otherVector to *this vector
  */

  vector(const vector<T>& otherVector);

  /*!
  * @brief gives size of vector
  * @post returns integer current_size
  */

  int size() const;
  /*!
* @brief  checks if empty
* @post return bool of (current_size <= 0) ? true : false;
*/
  bool empty() const;
  
  /*!
  * @brief  complements vector
  * @param[in]  otherVector
  * @pre  otherVector must have pass init() preconditions
  * @post copies contents of otherVector to *this vector
  */

  vector<T> operator-() const;
  
  /*!
  * @brief  replaces vector contents with input stream
  * @param[in]  finput  input stream
  * @param[in]  Obj  vector object being called
  * @pre  finput stream contents must be getline compatible
  * @pre  contents must be white space delimited, all in oneline
  * @post creates vector contents from input stream given
  * @post modifies Obj vector
  * @post returns finput
  */

  template<typename U>
  friend istream& operator >> (istream& finput, vector<U>& Obj);

  /*!
  * @brief
  * @param[in]
  * @pre
  * @post
  * @throw
  */

  template<typename U>
  friend ostream& operator << (ostream& os, const vector<U>& Obj);

  /*!
  * @brief
  * @param[in]
  * @pre
  * @post
  * @throw
  */

  vector<T> apply(std::function<T(T)> & f);

  template<typename U>
  friend vector<U> operator+(const vector<U>& lhs, const vector<U>& rhs);
  template<typename U>
  friend vector<U> operator-(const vector<U>& lhs, const vector<U>& rhs);

  /*!
  * @brief  returns value of element at position
  * @param[in]  index_var index position to access
  * @pre index_var must be bounded,non negative
  * @post returns value to element at given index_var
  * @throw range_error if out of bounds
  * @throw range_error vector is empty
  */

  const T  operator [] (const int index_var) const;

  /*!
  * @brief  returns reference of element at position
  * @param[in]  index_var index position to access  
  * @pre index_var must be bounded,non negative
  * @post returns reference to element at given index_var
  * @throw range_error if out of bounds
  * @throw range_error vector is empty
  */

  T & operator [] (const int index_var);


  //dot operator

  /*!
  * @brief  Dot operator
  * @param[in] lhs left hand vector
  * @param[in] rhs right hand vector
  * @pre T must define = (assingment) operator
  * @pre T must define += (plus equals) operator
  * @post returns runs operatorhandlerfunction
  * @post returns sums up vector from said function
  * @post returns result of type T scalar dot opreator
  */

  template<typename U>
  friend U operator*(const vector<U>& lhs, const vector<U>& rhs);

  
  /*!
  * @brief 
  * @param[in] 
  * @param[in] 
  * @pre 
  * @post 
  * @throw 
  */

  template<typename U>
  friend vector<U> operator*(const U & lhsScalar, const vector<U>& rhs);

  /*!
  * @brief 
  * @param[in] 
  * @param[in] 
  * @pre 
  * @post 
  * @throw 
  */

  template<typename U>
  friend vector<U> operator*(const vector<U>& lhs, const U& rhsScalar);

  

  vector<T>& operator = (const vector<T>& source);


  ~vector();

  void resize(const int new_size);
  T get(int i) const;

  Iter<T> begin() const;

  Iter<T> end() const;
};

template<typename T>
int Iter<T>::operator* () const
{
  return _p_vec->get(_pos);
}




#include "MyVector.hpp"

/*
http://antonym.org/2014/02/c-plus-plus-11-range-based-for-loops.html
  */
  /*
  destructor
copy constructor
copy assignment operator

A parameterized constructor accepting a 1-dimensional std::initializer_list //done
A parameterized constructor accepting the size of the vector to create //done
Other appropriate constructors
A means of resizing and determining the size of the vector with resize and size functions //done
Appropriate functions such that range-based for loops can be used on your vector//in dev
Copy constructor/copy assignment operations //done
Element access with the [] operator
Addition, subtraction, scalar multiplication, and vector multiplication (dot product) //done
Unary minus //done
An apply function accepting a function and returning a new vector containing the result of the function when called on the elements of the calling object, and in which the function f must have the signature T f(T) (for template type T)
Stream operators for input/output of vector data - accepted input should be whitespace-delimited elements, and output should be single-space-delimited elements of the vector
*/

#endif
