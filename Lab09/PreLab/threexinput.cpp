// threexinput.cpp

/*
Pyung Lee
PKL4FR
4/7/20

 */



#include <iostream>
#include "timer.h"
#include <cstdlib>
using namespace std;

extern "C" long threexplusone(long);

int  main () {
    // delcare the local variables
  long  a;
  // int counter;
  // double totalTime;
  //  timer time;
  
    // how big is the array we want to use?
    cout << "Please enter a number:  ";
    cin >> a;
    //how many times are you calling the function?
    //  cout << "How many times are you going to call it? ";
    //  cin >> counter;

    // find product  and print out results
    int answer;

    // time.start();
    
    /// for(int i = 0; i < counter; i++){
      answer = threexplusone(a);
      cout << "It took this many counts:  " << answer << endl;
      
      //  }
    
    // time.stop();

      // totalTime = time.getTime()*1000;
      // totalTime= totalTime/counter;

      // cout << "It took: " << totalTime << " milliseconds." << endl; 
    
    // all done!
    return 0;
}
