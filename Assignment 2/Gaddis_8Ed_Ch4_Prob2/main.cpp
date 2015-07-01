/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: Roman Numeral Calculator
 * Created on June 29, 2015, 9:39 PM
 */

//System Libraries
#include <iostream>

//User Libraries
using namespace std;    //I/O Library

/*//Global constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {

    short digit;        //Number to be converted
    
    cout<<"Enter a number between 1 and 10 to be converted into its Roman numeral"<<endl;       //Prompt to enter number
    cin>>digit;     //Input number to be converted
    
    if (digit>=1 && digit<=10){ 
        switch(digit)
        {
            case 1:cout<<"This is roman numeral I."<<endl;
                break;
            case 2:cout<<"This is roman numeral II."<<endl;
                break;
            case 3:cout<<"This is roman numeral III."<<endl;
                break;
            case 4:cout<<"This is roman numeral IV."<<endl;
                break;
            case 5:cout<<"This is roman numeral V."<<endl;
                break;
            case 6:cout<<"This is roman numeral VI."<<endl;
                break;
            case 7:cout<<"This is roman numeral VII."<<endl;
                break;
            case 8:cout<<"This is roman numeral VIII."<<endl;
                break;
            case 9:cout<<"This is roman numeral IX."<<endl;
                break;
            case 10:cout<<"This is roman numeral X."<<endl;
                break;
                    
            
           
        }
    }    
    else{
        cout<<"You did not follow the directions. No roman numeral for you."<<endl;
    }    
        
        
    //Exit Stage Right!
        
    return 0;
}

