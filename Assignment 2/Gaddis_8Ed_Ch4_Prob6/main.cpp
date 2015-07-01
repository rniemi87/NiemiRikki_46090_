/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate weight and mass
 * Created on June 30, 2015, 8:29 PM
 */

//System Libraries
#include <iostream>

using namespace std;

/*//User Libraries
 * 
 * //Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {

    //Declare variables
    float weight;       //Weight in newtons
    float mass;         //Mass in kg
  
    cout<<"Enter the object's mass"<<endl;      //Prompt for mass
    cin>>mass;      //Prompt for mass
    
    weight=9.8*mass;    //Calculate weight in newtons
    
    if (weight<10){
        cout<<"The object is too light"<<endl;
    }
    else{
        cout<<"The object weighs "<<weight<<" newtons"<<endl;
    }
  
    //Exit Stage Right!
    
    return 0;
}

