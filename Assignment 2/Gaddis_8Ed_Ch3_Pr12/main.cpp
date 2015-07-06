/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To convert Fahrenheit to Celsius
 * Created on July 3, 2015, 8:58 PM
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
    float fahr;                 //Degrees Fahrenheit
    float cels;                 //Degrees celsius
    char type;                  //(y/n)
    
    do{
        cout<<"Enter the Celsius temperature to be converted:"<<endl;          //Prompt to input temperature 
        cin>>cels;                                                             //Input temp to be converted
        
        fahr=1.8*cels+32;                                                      //Conversion calculation
        
        cout<<cels<<" degrees Celsius is \n";
        cout<<fahr<<" degrees Fahrenheit."<<endl;
        
        cout<<"Do you want to perform another calculation? Type (y/n)"<<endl;
        cin>>type;
        
    }while(type=='y' || type=='Y');
    
    
    
    return 0;
}

