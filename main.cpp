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
#include "main.h"

using std::cout;
using std::endl;
//stuff tested
/*
for range
//sets
*/
int main()
{
  
  InitialTest();
  Test2();
  Test3();

  return 0;
}
void Test3()
{
  //tests 
  /*
  set
  vector(int size)
  operator <<
  */
  cout << "-------Test 3---" << endl;
  vector<int> vTest = { 1,2,3,4,5,6,7 };
  vTest.resize(5);
  cout << vTest << endl;
  cout << "------- END----" << endl;
}

void Test2()
{
  //tests 
  /*
  vector initilizer list
  operator <<
  vector v()
  vector v
  */
  cout << "-------Test 2---" << endl;
  vector<int> vTest = { 1,2,3,4,5,6,7 };
  cout << vTest << endl;
  cout << "isEmpty? " << vTest.empty() << endl;
  vector<int> vTest2 = {};
  cout << vTest2 << endl;
  cout << "isEmpty? " << vTest2.empty() << endl;
  cout << "------- END----" << endl;
  vector<int> vTest3 = vector<int>();
  vector<int> vTest4;
  cout << vTest3 << endl;
  cout << vTest4 << endl;
  cout << "isEmpty? " << vTest3.empty() << endl;
  cout << "isEmpty? " << vTest4.empty() << endl;
  cout << "------- END----" << endl;
}

void InitialTest()
{
  //tests 
  /*
  set
  vector(int size)
  operator <<
  */
  cout << "-------Test 1---" << endl;
  vector<int> hello(5);
  hello.set(0, 0);
  hello.set(1, 1);
  hello.set(2, 2);
  hello.set(3, 3);
  hello.set(4, 4);
  cout << hello << endl;
  cout << "------- END----" << endl;

}
