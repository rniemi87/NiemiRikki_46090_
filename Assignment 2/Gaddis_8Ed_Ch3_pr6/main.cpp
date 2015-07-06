/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To adjust a recipie to produce a new amount of cookies
 * Created on July 3, 2015, 7:45 PM
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
 * //Execution Starts Here!
 * 
 */
int main(int argc, char** argv) {

    //Declare variables
    
    float sug;                      //Amount of sugar
    float butter;                   //Amount of butter
    float flour;                    //Amount of flour
    float cvtrec;                   //Recipe conversion
    float oldamt;                   //Original amount of cookies
    float newamt;                   //Needed amount of cookies
    
    //Initialize variables
    
    sug=1.5;                        //Sugar in cups
    butter=1.0;                     //Butter in cups
    flour=2.75;                     //Flour in cups
    oldamt=48;                      //Amount of cookies in original recipe
    
    
    
    cout<<"Input the amount of cookies needed:"<<endl;          //Prompt for cookies
    cin>>newamt;                                                //Input cookies needed
    
    cvtrec=newamt/oldamt;                                       //Recipe conversion factor
    
    sug*=cvtrec;                                                //New sugar amount
    butter*=cvtrec;                                             //New butter amount
    flour*=cvtrec;                                              //New flour amount
    
    cout<<"To make "<<newamt<<" cookies, you need: \n";         //Output results
    cout<<sug<<" cups of sugar \n";
    cout<<butter<<" cups of butter \n";
    cout<<flour<<" cups of flour \n";
    
    //Exit Stage Right!
    
    return 0;
}

