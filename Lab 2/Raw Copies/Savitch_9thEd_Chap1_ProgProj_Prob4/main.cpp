/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To find distance traveled
 * Created on June 23, 2015, 12:06 PM
 */

//System Libraries
#include <iostream>//I/O Library

using namespace std;

const float GRAVITY=32.174e1f;//Acceleration due to gravity

//Function Protoypes

//Execution starts here!

int main(int argc, char** argv) {
  
    //Declare Variables
    
    float time;         //time=time in (secs)
    float dstnce;       //Dstnce=The distance propped in (ft)
    
    cout<<"Input the Time in Seconds"<<endl;    //Prompt for time input
    
    cin>>time;  //Input time
    
    //Incorrect dstnce=1/2GRAVITY*time*time
    //Also correct dstnce=GRAVITY*time*time/2
    dstnce=GRAVITY*time*time/2;     //Calculate the free-fall distance
    
    cout<<"The distance traveled = "<<dstnce<<"(ft)"<<endl;
    
    //Exit Stage right!
    
    return 0;
}

