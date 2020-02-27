#include "SIRD.h"

ostream& operator<<(ostream& os, const SIRD& Obj)
{

  //os << "----STATUS----"<< endl;
  //os << Obj.S<<" " << Obj.I << " " << Obj.R << " " << Obj.D<<endl;
  //os << "SUM: " << (Obj.S + Obj.I + Obj.R + Obj.D )<< endl;
  //os << "------------" << endl;
  os << Obj.S<<"," << Obj.I << "," << Obj.R << "," << Obj.D<<"\n";
  return os;
}

void SIRD::createODE()
{

  auto ODEsusceotible =
    [=](double susceptible_given) {
    return -(vRates[0] * I * susceptible_given);
  };
  auto ODEinfected =
    [=](double infected_given)
  {
    double first = (vRates[0] * infected_given * S);
    double second = (vRates[1] * infected_given);
    double third = (vRates[2] * infected_given);
    return (first - second - third);
  };

  //calculated from previous function
  auto ODErecovered =
    [=](double dummy) {return (vRates[1] * I); };
  auto ODEdead =
    [=](double dummy) {return (vRates[2] * I); };

  Susceptible = Euler<double>(ODEsusceotible, S, h); //pass in initial S
  Infected = Euler<double>(ODEinfected, I, h); //pass in initial S
  Recovered = Euler<double>(ODErecovered, R, h); //pass in initial S
  Deceased = Euler<double>(ODEdead, D, h); //pass in initial S
}

void SIRD::init(double init_population, double init_infected, double step_size, vector<double>& v_input)
{
  N0 = init_population;
  I0 = init_infected;
  h = step_size;
  vRates = v_input;
  Nn = N0;
  In = I0;
  //cout << "INITILIAZED" << endl;

  S = init_population-init_infected;
  I = init_infected;
  R = 0.0;
  D = 0.0;
}


SIRD::~SIRD()
{
  cout << "Deleting SIRD" << endl;
}
