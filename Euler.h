#ifndef EULER_H
#define EULER_H


#include <iostream>
#include <string>
#include <functional>

using std::string;
using std::cout;
using std::function;
using std::endl;


template<typename T>
class Euler
{
private:
  T y; //state
  double h; //step size
  function <T(T)> ODE;
public:

  Euler() = default;

  /*!
  * @brief
  * @param[in]
  * @pre
  * @post
  * @throw 
  */
  Euler(const std::function<T(T)>& callback_f,const T initial_y0,const double input_h = 0.01f); // constructor

  /*!
  * @brief
  * @param[in]
  * @pre
  * @post
  * @throw
  */
  Euler(const Euler<T>& otherEuler);
  
  /*  
  * @brief calls ()(double_input) with var h as step size
  * @param[in]
  * @pre
  * @post
  * @throw 
  */

  T operator()();

   /*!
  * @brief
  * @param[in]
  * @pre
  * @post
  * @throw
  */

  T operator()(double input_step);

  /*!
  * @brief
  * @param[in]
  * @pre
  * @post
  * @throw
  */
  Euler<T>& operator = (const Euler<T>& source);


};




#include "Euler.hpp"
/*
You will be also responsible for implementing the forward/explicit Euler method for ordinary differential equations.
Since we need to support Euler�s method for both scalars and Eulers (or any other type, for that matter), and for the solving of any arbitrary ODE,
this should also be templated on the type used to encapsulate the state of the differential equation. This class must include the following:

A constructor accepting a ODE callback, an initial state y0, and a step size h - an ODE callback is one that accepts a value of
the type used to encapsulate the state of the ODE, and returns a value of the same type

Other appropriate constructors/destructors/copy functionality

function evaluation operator () to �step� the differential equation, calculating and returning the value of the function for the next discrete value of the independent variable, yn+1, and allowing a custom step size for that step to optionally be specified, overriding the step size specified in the constructor
*/

#endif
