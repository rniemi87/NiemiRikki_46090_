/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate U.S. Dollars into Euros or Yen
 * Created on July 3, 2015, 9:32 PM
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
    float dolamt;                           //U.S. Dollar amount
    float yencvt;                           //Yen per dollar conversion
    float eurocvt;                          //Euro per dollar conversion
    float euro;                             //Amount of Euros
    float yen;                              //Amount of Yen
    char type;                              //To select euro or dollar
    char again;                             //To select yes or no
    
    do{
        
        
        cout<<"Would you like to convert to Euros or Yen? Type 'e' for euros or 'y' for yen"<<endl;
        cin>>type;
        
        if(type=='e'){
            eurocvt=0.74;                           //Conversion to euro
            cout<<"Input dollar amount"<<endl;      //Prompt for dollar amount  
            cin>>dolamt;                            //Input dollar amount
            euro=dolamt*eurocvt;                    //Conversion
            cout<<euro<<" Euros"<<endl;             //Output results
            
        }else if (type=='y'){
            yencvt=98.93;                           //Conversion to yen
            cout<<"Input dollar amount"<<endl;      //Prompt for dollar amount
            cin>>dolamt;                            //Input dollar amount 
            yen=dolamt*yencvt;                      //Conversion
            cout<<yen<<" Yen"<<endl;                //Output results
        }
        
        cout<<"Would you like to convert another amount? Type 'y' for yes and 'n' for no."<<endl;
        cin>>again;
    
                    
    }while(again=='y'||again =='Y');
    
    //Exit Stage Right!
   
    return 0;
}

