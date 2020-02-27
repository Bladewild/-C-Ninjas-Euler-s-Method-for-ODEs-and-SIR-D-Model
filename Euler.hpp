
#include "Euler.h"
template <typename T>
Euler<T>::Euler() // default constructor
{
  ODE = NULL;
  y = NULL;
  h = NULL;
}

template <typename T>
Euler<T>::Euler(const std::function<T(T)>& callback_f,const T initial_y0,const double input_h) // constructor
{
  ODE = callback_f;
  y = initial_y0;
  h = input_h;
}

template <typename T>
Euler<T>::Euler(const Euler<T>& otherEuler)
{
  ODE = otherEuler.ODE;
  y = otherEuler.y;
  h = otherEuler.h;
}


template<typename T>
Euler<T>& Euler<T>::operator = (const Euler<T>& source)
{
  if (this != &source)
  {
    ODE = source.ODE;
    y = source.y;
    h = source.h;
  }
  return *this;
}

template<typename T>
T Euler<T>::operator()()
{
  return (*this)(h);
}


template<typename T>
T Euler<T>::operator () (double input_step)
{
  T result = ODE(y);
  //cout << "Result:" << result<<endl;
  //cout << "Result,stepsize:" << result*input_step << endl;
  y = y + input_step* result; //udpate first one only

  return y ;

}

template<typename T>
Euler<T>::~Euler()
{
  cout << "Deleting Euler" << endl;
}

