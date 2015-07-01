/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To use conditional operator to fingure out which number is larger
 * Created on June 29, 2015, 9:03 PM
 */

//System Libraries
#include <iostream>

//User Libraries
using namespace std;    //I/O Library

/*//Global COnstants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {

    //Declare Variables
    short x, y;      //Two integers
    
    cout<<"Enter two integers separated by a space between 1 and 100 "<<endl;   //Prompt to enter numbers
    cin>>x>>y;
    (x<y)?cout<<y<<" is largest.":cout<<x<<" is largest."<<endl;
    
    
    return 0;
}

