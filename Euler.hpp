
#include "Euler.h"

/*
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
*/

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
  if (input_step <= 0)
  {
    throw std::invalid_argument("input_step cannot be < 0 or = 0");
  }
  //cout << "Result:" << result<<endl;
  //cout << "Result,stepsize:" << result*input_step << endl;
  y = y + input_step* ODE(y); //udpate first one only

  return y ;

}