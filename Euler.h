/*
* Author:
* File: main.cpp Date: 2/13/20
* Class: CS 5201
* Instructor :
*
* Euler file
*/

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
  * @post assigns variables
  */
  Euler(const std::function<T(T)>& callback_f, const T initial_y0, const double input_h) :
    ODE(callback_f), y(initial_y0), h(input_h) {};

  /*!
  * @brief
  * @param[in]
  * @pre
  * @post
  * @throw
  */
  Euler(const Euler<T>& otherEuler) :
    ODE(otherEuler.ODE), y(otherEuler.y), h(otherEuler.h) {};
  
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

#endif
