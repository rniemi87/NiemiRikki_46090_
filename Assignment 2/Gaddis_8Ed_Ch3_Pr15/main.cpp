/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate assessment value and property tax
 * Created on July 3, 2015, 10:37 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries
/*
 * //Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {

    //Declare variables
    float asval;                    //Assessment value
    int actval;                     //Actual Value
    float aspct;                    //Assessment percentage of actual value
    float tax;                      //Amount of tax per $100 of assessment value
    float taxtot;                   //Amount of tax in $'s               
    char again;
    //Initialize variables
    tax=.0075;
    aspct=.60;
    
    do{
        cout<<"Input the actual property value in $'s"<<endl;               //Prompt for actual value
        cin>>actval;                                                        //Input actual value

        asval=actval*aspct;                                                 //Assessment value calculation

        taxtot=asval*tax;                                                   //Tax amount in $'s

        cout<<"The assessment value is $"<<asval<<endl;
        cout<<"The property tax is     $"<<taxtot<<endl;

        cout<<"Would you like to perform another calculation? Type 'y' for yes and 'n' for no."<<endl;
        cin>>again;
    }while(again=='y' ||again=='Y');
    
    //Exit Stage Right!
    
    return 0;
}

