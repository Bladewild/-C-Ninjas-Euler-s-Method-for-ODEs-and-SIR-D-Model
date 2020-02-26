#ifndef SIRD_H
#define SIRD_H


#include <iostream>
#include <string>
#include <functional>
#include "MyVector.h"
#include "Euler.h"

#include <iostream>
#include "MyVector.h"
#include "Euler.h"
using std::string;
using std::cout;
using std::function;
using std::endl;


using std::cout;
using std::cin;
using std::endl;
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


  Euler<vector<double>> Susceptible;
  Euler<vector<double>> Infected;
  Euler<vector<double>> Deceased;
  Euler<vector<double>> Recovered;

  vector<double> ODESusceptible(const vector<double>& input_stateSusceptible)
  {
    //infected,Susceptible, infection rate
    //calculate
    vector<double> new_v = input_stateSusceptible;
    double new_s = (-new_v[2]) * (new_v[0] * new_v[1]);
    new_v[1] = new_s;
    return new_v;
  }

  vector<double> ODEInfected(const vector<double>& input_stateInfected)
  {
    //infected,Susceptible, infection rate,recovery rate, death rate
    //calculate
    vector<double> new_v = input_stateInfected;
    double new_I = (new_v[2] * (new_v[0] * new_v[1]))
      - (new_v[3]*new_v[0]) -(new_v[4]*new_v[0]);
    new_v[0] = new_I;
    return new_v;
  }

  vector<double> ODERecovered(const vector<double>& input_stateRecovered)
  {
    //infected, recovery rate
    //calculate
    vector<double> new_v = input_stateRecovered;
    double new_I = new_v[1] * new_v[0];
    new_v[0] = new_I;
    return new_v;
  }

  vector<double> ODEDead(const vector<double>& input_stateDead)
  {
    //infected, death rate
    //calculate
    vector<double> new_v = input_stateDead;
    double new_D = new_v[1] * new_v[0];
    new_v[0] = new_D;
    return new_v;
  }

  vector<double> vRates;


public:

  /*
  A constructor accepting the initial total population (N0), the initial number of infected (I0), 
  and a step size (h), and a vector [β,ν,δ], which should default to values provided in the driver instructions
  */
  SIRD()
  {
    //default 100 indivisuals, 1 infected,
    //[infection rate,recovery rate,death rate]
    vector<double> v = { 0.01 ,0.1,0.05 };
    SIRD(100, 1, 0.1, v);
  }
  SIRD(double init_population,double init_infected, double step_size,vector<double> v_input)
  {
    N0 = init_population;
    I0 = init_infected;
    h = step_size;
    vRates = v_input;
    Nn = N0;
    In = I0;

    S = init_population;
    I = 0.0;
    R = 0.0;
    D = 0.0;
    //(const std::function<T(T)>& f,const T initial_y0,const double input_h = 0.01f);
    std::function<vector<double>(vector<double>)> function1 = ODESusceptible;
    std::function<vector<double>(vector<double>)> function2 = ODEInfected;
    std::function<vector<double>(vector<double>)> function3 = ODERecovered;
    std::function<vector<double>(vector<double>)> function4 = ODEDead;

    //infected,Susceptible, infection rate
    vector<double> stateSusceptible = { I,S,vRates[0]};

    //infected,Susceptible, infection rate,recovery rate, death rate
    vector<double> stateInfected = { I,S,vRates[0],vRates[1],vRates[2]};

    //infected, recovery rate
    vector<double> stateRecovered = { I,vRates[1] };

    //infected, death rate
    vector<double> stateDead = { I,vRates[2] };

    Susceptible = Euler<vector<double>>(function1, stateSusceptible, h); //pass in initial S
    Infected = Euler<vector<double>>(function1, stateInfected, h); //pass in initial S
    Recovered = Euler<vector<double>>(function1, stateRecovered, h); //pass in initial S
    Deceased = Euler<vector<double>>(function1, stateDead, h); //pass in initial S
  }

  SIRD& operator()()
  {
    //calculate susceptible people (S)
    vector<double> temp_s = h * Susceptible(I); // use initial I
    S = S + h*temp_s[1]; // use initial I
    //calculate infected people (I)

    vector<double> temp_s = h * Susceptible(I); // use new S
    S = S + h * temp_s[1]; // use initial I
    //---------------------------
    //calculate deceased people

    //calculate recovered people
  }
  //https://youtu.be/F6J3ZmXkMj0

  SIRD& operator()(double input_step);

  SIRD& operator = (const SIRD& source);



  ~SIRD();
};



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
