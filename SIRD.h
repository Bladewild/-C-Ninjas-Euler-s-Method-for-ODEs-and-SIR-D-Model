#ifndef SIRD_H
#define SIRD_H


#include <iostream>
#include <string>
#include <functional>
#include "MyVector.h"
#include "Euler.h"

using std::string;
using std::cout;
using std::function;
using std::endl;
using std::ostream;


class SIRD
{
private:
  double N0;
  double I0;
  double Nn;//current
  double In;//current
  double h;
  double S;
  double I;
  double R;
  double D;


  Euler<double> Susceptible;
  Euler<double> Infected;
  Euler<double> Deceased;
  Euler<double> Recovered;
  vector<double> vRates;
  void createODE();
  void init(double init_population, double init_infected, double step_size, vector<double>& v_input);


public:

  /*
  A constructor accepting the initial total population (N0), the initial number of infected (I0), 
  and a step size (h), and a vector [β,ν,δ], which should default to values provided in the driver instructions
  */
  SIRD()
  {
    //default 100 indivisuals, 1 infected,
    //[infection rate,recovery rate,death rate]
    vector<double> v ={0.01 ,0.1,0.05 };
    v.name = "kevin";

    init(100.0, 1.0, 0.1, v);
    createODE();

  }
  SIRD(double init_population,double init_infected, double step_size,vector<double> v_input)
  {
    init(init_population, init_infected, step_size, v_input);
    createODE();
  }

  

  void operator()()
  {
    double tempS, tempI, tempR, tempD;
    tempS = Susceptible();
    tempI =Infected();
    //---------------------------
    tempR =Recovered();
    tempD =Deceased();
    S = tempS;
    I = tempI;
    R = tempR;
    D = tempD;
    
  }
  //https://youtu.be/F6J3ZmXkMj0

  SIRD& operator()(double input_step)
  {
    //do nothing for now
  }

  friend ostream& operator << (ostream& os, const SIRD& Obj);
  ~SIRD();
  /*
  SIRD& operator = (const SIRD& source);
  {
    //todo later
  }



  {
    
  }*/
};

#include "SIRD.hpp"

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
