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

void InitialTest();
void Test3();
void Test4();
void Test2();
void Test4();

int main()
{
  
  try
  {
    InitialTest();
    Test2();
    Test3();
    Test4();

  }
  catch (const std::out_of_range & oor) {
    std::cerr << "\nOut of Range error: " << oor.what() << '\n';
  }
  catch (const std::invalid_argument & ia) {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
  }
  catch (const std::length_error & le) {
    std::cerr << "Length error: " << le.what() << '\n';
  }
  catch (...)
  {
    std::cerr << "An uknown error has occured." << '\n';
  }

  return 0;
}
void Test4()
{
  //unary minus
  //copy constructor
  //set test
  cout << "-------Test 4---" << endl;
  vector<int> vTest1 = { 1,2,3,4,5,6,7,8 };
  cout << vTest1 << endl;
  cout << "-------COPYING---" << endl;
  vector<int> vTest2 = vector<int>(vTest1);
  vTest2.set(0, 1);
  vTest2.set(1, 1);
  vTest2.set(2, 1);
  vTest2.set(3, 1);
  vTest2.set(4, 1);
  vector<int> vTest3 = vTest2;
  vTest3.set(0, 2);
  cout << "vTest1: " << vTest1 << endl;
  cout << "vTest2: " << vTest2 << endl;
  cout << "vTest3: " << vTest3 << endl;
  cout << "------- END----" << endl;
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
