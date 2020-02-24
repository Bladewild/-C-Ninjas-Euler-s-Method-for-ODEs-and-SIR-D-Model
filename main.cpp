/*
* Author: 
* File: main.cpp Date: 2/13/20
* Class: CS 5201
* Instructor : 
*
* main file
*/
#include <iostream>
#include "MyVector.h"

using std::cout;
using std::cin;
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
void Test5();
void Test6();
void Test7();

int main()
{
  
  try
  {
    InitialTest();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

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
void Test7()
{
  //unary minus
  int test[] = { 5,1,2,3,4 };
  cout << "-------Test 6---" << endl;
  vector<int> vTest1 = { 1,2,3,4,5,6,7,8 };
  cout << "vTest1: " << vTest1 << endl;
  cin >> vTest1;
  cout << "vTest1: " << vTest1 << endl;
  cout << "------- END----" << endl;

}
void Test6()
{
  //Test set and []
  int test[] = { 5,1,2,3,4 };
  cout << "-------Test 6---" << endl;
  vector<int> vTest1 = { 1,2,3,4,5,6,7,8 };
  const vector<int> vTest2 = { 1,1,1,1,1,1,1,1 };
  cout << "vTest1: " << vTest1 << endl;
  cout << "vTest1: " << vTest2 << endl;
  vTest1[5] = 8;
  cout << "vTest1: " << vTest1 << endl;
  cout << "------- END----" << endl;

}
void Test5()
{
  //unary minus
  //copy constructor
  //checks assingment I think
  //checks arithmatic
  int test[] = { 5,1,2,3,4 };
  cout << "-------Test 5---" << endl;
  vector<int> vTest1 = { 1,2,3,4,5,6,7,8};
  vector<int> vTest2 = { 2,2,2,2,2,2,2,2};
  vector<int> vTest9 = { 2,2,2,2,2,2,2,2 };
  vector<int> vTest8 = { 2,2,2,2,2,2,2,2 };
  vector<int> vTest3 = vTest1 + vTest2;
  vector<int> vTest4 = vTest1 - vTest2;
  int vTest5 = vTest8 * vTest9;
  vector<int> vTest6 =  3 * vTest2;
  vector<int> vTest7 = vTest2 * 5;
  cout << "vTest1: " << vTest1 << endl;
  cout << "vTest2: " << vTest2 << endl;
  cout << "vTest3: " << vTest3 << endl;
  cout << "vTest4: " << vTest4 << endl;
  cout << "vTest5: " << vTest5 << endl;
  cout << "vTest6: " << vTest6 << endl;
  cout << "vTest7: " << vTest7 << endl;
  cout << "------- END----" << endl;
}

void Test4()
{
  //unary minus
  //copy constructor
  //set test
  //array constructor
  int test[] = { 5,1,2,3,4 };
  cout << "-------Test 4---" << endl;
  vector<int> vTest1 = { 1,2,3,4,5,6,7,8 };
  cout << vTest1 << endl;
  cout << "-------COPYING---" << endl;
  vector<int> vTest2 = vector<int>(vTest1);
  vector<int> vTestarr(test,5);
  vTest2.set(0, 1);
  vTest2.set(1, 1);
  vTest2.set(2, 1);
  vTest2.set(3, 1);
  vTest2.set(4, 1);
  
  vector<int> vTest3 = -vTest2;
  vTest3.set(0, 2);
  cout << "vTest1: " << vTest1 << endl;
  cout << "vTest2: " << vTest2 << endl;
  cout << "vTestarr: " << vTestarr << endl;
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
