#include "SIRD.h"

SIRD::SIRD() :
  h(0.1), vRates(vector<double>{0.01, 0.1, 0.05 }),
  state(vector<double>{ 100, 1, 0.0, 0.0}), SIRDeuler()
{
  createODE();

}

SIRD::SIRD(double init_population, double init_infected, double step_size, vector<double> v_input) :
  h(step_size), vRates(v_input),
  state(vector<double>{ (init_population - init_infected), init_infected, 0.0, 0.0}), SIRDeuler()
{
  createODE();
}



void SIRD::operator()()
{
  state = SIRDeuler();
}


void SIRD::operator()(double input_step)
{
  state = SIRDeuler(input_step);
}

ostream& operator<<(ostream& os, const SIRD& Obj)
{

  //os << "----STATUS----"<< endl;
  //os << Obj.S<<" " << Obj.I << " " << Obj.R << " " << Obj.D<<endl;
  //os << "SUM: " << (Obj.S + Obj.I + Obj.R + Obj.D )<< endl;
  //os << "------------" << endl;
  //os << Obj.S<<"," << Obj.I << "," << Obj.R << "," << Obj.D<<"\n";

  os << Obj.state[0]<<"," << Obj.state[1] << "," << Obj.state[2] << "," << Obj.state[3] <<"\n";
  return os;
}


SIRD& SIRD::operator=(const SIRD& source)
{
  if (this != &source)
  {
    h=source.h;
    vRates= source.vRates;
    state= source.state;
    SIRDeuler= source.SIRDeuler;
  }

  return *this;
}



void SIRD::createODE()
{
  
  auto ODESIRD =
	  [=](vector<double> stateGiven) 
      {
	  double susceptibility = -(vRates[0] * stateGiven[1] * stateGiven[0]);
	  //infected
	  double first = (vRates[0] * stateGiven[1] * stateGiven[0]);
	  double second = (vRates[1] * stateGiven[1]);
	  double third = (vRates[2] * stateGiven[1]);

	  double infected = (first - second - third);
	  //-----
	  double recovered = vRates[1] * stateGiven[1];
	  double dead = vRates[2] * stateGiven[1];
	  vector<double> toReturn = { susceptibility, infected, recovered, dead };
	  return toReturn;
	};

  SIRDeuler = Euler<vector<double>>(ODESIRD, state, h);
}
/*
void SIRD::init(double init_population, double init_infected, double step_size, vector<double>& v_input)
{
  h = step_size;
  vRates = v_input;

  state = vector<double>{ (init_population - init_infected),init_infected,
  0.0,0.0};
 
}

 */