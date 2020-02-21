/*
* Author: ALAIN MARKUS SANTOS-TANKIA
* File: main.cpp Date: 2/13/20
* Class: CS 5201
* Instructor : CLAYTON PRICE
*
* main file
*/
#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;
//stuff tested
/*
for range
//sets
*/
int main()
{
  vector<int> hello(5);
  hello.set(0, 0);
  hello.set(1, 1);
  hello.set(2, 2);
  hello.set(3, 3);
  hello.set(4, 4);
  cout << hello << endl;
  return 0;
}