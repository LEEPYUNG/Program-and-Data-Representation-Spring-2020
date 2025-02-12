/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/10/2020
	File Name: prelab4.cpp
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <climits>

using namespace std;


void sizeOfTest();
void outputBinary(unsigned int x);
void overflow();

int main(){
  
  // unsigned int x;
  // cout << "Enter an input: " << endl;
  // cin >> x;
  
  //cout<< "Testing sizeOfTest(): " << endl;
  sizeOfTest();

  //  cout << "Testing BinaryOutput(): " << endl;
  // outputBinary(x);
  
  // cout << "Testing overflow(): " << endl;
  //overflow();
 
  
  return 0;
}

void sizeOfTest(){
   cout << "Size of int: " << sizeof(int) << endl;
   cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
   cout << "Size of float: " << sizeof(float) << endl;
   cout << "Size of double: " << sizeof(double) << endl;
   cout << "Size of char: " << sizeof(char) << endl;
   cout << "Size of bool: " << sizeof(bool) << endl;
   cout << "Size of int pointer: " << sizeof(int*) << endl;
   cout << "Size of char pointer: " << sizeof(char*) << endl;
   cout << "Size of double pointer: " << sizeof(double*) << endl;
}

void outputBinary(unsigned int x){
  int input = x;
  string ans;

  if(input == 0){
    ans = "0000 0000 0000 0000 0000 0000 0000 0000";
  }
  for(int i = 1; i <= 32; i++){ 
    if(input != 0) {
      ans = ans + std::to_string(input%2);
      //  cout<<ans << " This is ans right now" << endl;
      input = input/2;
      // cout<<input << " This is input right now" <<endl;
    }
    else{
      ans = ans + "0";
    }     
      if(i%4 == 0){
	ans = ans + " ";
      } 
  }

  reverse(ans.begin(),ans.end());
  cout << "Binary Output: " << ans << endl;

}

void overflow(){
  unsigned int x = UINT_MAX;
  cout << "This is the value of x: " <<  x << endl; 

  unsigned int y = x +1;
  cout << "This is x+1: " << y << endl;

  cout<< "The maximum value has all 32 bits are designated as a 1. But if you add a one, all of the bits flip to a 0. Since there is not another bit available for the addition of 1, the final value is 0." << endl;  
}
