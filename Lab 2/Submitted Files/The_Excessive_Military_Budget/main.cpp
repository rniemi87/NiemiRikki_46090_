/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate the percentage of U.S. military spending.
 * Created on June 23, 2015, 1:37 PM
 */

#include <iostream>

using namespace std;

/*//Global Constants
 * 
 * //Function Prototypes
 * 
 *///Execution BEgins Here!

int main(int argc, char** argv) {
    float fedbud;   //fedbud=federal budget in $'s
    float milbud;   //milbud=military budget in $'s    
    float pmilbud;  //Percentage military budget in $'s
    
    
    
    fedbud=3.9e12f;     //Value of federal budget
    milbud=.598e12f;    //Value of military budget
    
    cout<<"The total federal budget is $"<<fedbud<<". \n";      //Federal Budget
    cout<<"The total military budget is $"<<milbud<<". \n";     //Military Budget
      
    pmilbud=milbud/fedbud*100;//Percentage of military budget
    
    cout<<"The military budget is allocated "<<pmilbud<<"% of the U.S. federal budget."<<endl; //Percentage of federal budget is allocated to military
    
    return 0;
}

