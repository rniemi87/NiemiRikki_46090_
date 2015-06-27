/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: TO find number of consumers who prefer citrus energy drinks
 * Created on June 23, 2015, 12:49 PM
 */
//System Libraries
#include <iostream>

using namespace std;//I/O Library

/*//Global constant
 * 
 * Function Prototype
 * 
 * Execution Starts Here!
 */
int main(int argc, char** argv) {
    
    //Declare Variables
    float pEdrink;              //pEdrink=Percentage of people who purchased energy drinks
    float pCit;                 //pCit=Percentage of people who purchased citrus drinks
    unsigned short cSurv;       //cSurv=number of people surveyed
    unsigned short Edrnkrs;     //Edrnkrs=People who purchased drinks
    unsigned short cPref;       //cPref=number of people who preferred citrus flavor
    
    cSurv=12467;//Number of those surveyed
    pEdrink=.14;//Percentage of people who bought one or more energy drinks

    Edrnkrs=cSurv*pEdrink;//Number of people out of sample group who bought energy drinks
    
    pCit=.64;//Percentage of people who preferred citrus flavored energy drinks
    cPref=Edrnkrs*pCit;//People who preferred citrus flavored drinks out of sample group
    
    cout<<"Out of those surveyed, "<<Edrnkrs<<" purchased energy drinks and "<<cPref<<" of those people preferred citrus flavor."<<endl;//Display people out of survey who preferred citrus flavor
        
    
    //Exit Stage Right!
        
    return 0;
}

