/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate a car's miles per gallon
 * Created on July 3, 2015, 6:23 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries
/*
 * //Global Constants
 * 
 * //Function Prototypes
 * 
 *///Execution Starts Here!

int main(int argc, char** argv) {

    //Declare variables
    
    float tank;                 //Tank capacity in gallons
    float mlstank;              //Miles driven on full tank
    float mpg;                  //Miles per gallon
    
    cout<<"Enter the tank capacity in gallons:"<<endl;              //Prompt for tank capacity
    cin>>tank;                                                      //Input tank capacity
    
    cout<<"Enter the amount of miles driven on a full tank:"<<endl; //Prompt for miles driven on full tank
    cin>>mlstank;                                                   //Input miles driven on fall tank
    
    mpg=mlstank/tank;                                               //Calculation for miles per gallon
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"MPG = "<<mpg<<endl;                                      //Output miles per gallon
    
    
    
    
    
    return 0;
}

