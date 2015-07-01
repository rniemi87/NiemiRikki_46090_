/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: to show the number of seconds, days, hours and minutes
 * Created on June 30, 2015, 8:56 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries
/*/
 * Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 * 
 */
int main(int argc, char** argv) {

    //Declare Variables
    int sec;        //Seconds
    float min;      //Minutes
    float hrs;      //Hours
    float days;     //Days
    int secday;     //Seconds in a day
    int sechr;      //Seconds in hour
    int secmin;     //Seconds in minute
    
    //Initialize variables
    secday=86400;  //Seconds in day
    sechr=3600;    //Seconds in hour
    secmin=60;     //Seconds in minute
    
    cout<<"Enter number of seconds"<<endl;      //Prompt for seconds
    cin>>sec;                                   //Input seconds
    
    if(sec>secday){
    
        days=static_cast<float>(sec)/secday;    //Calculate days
        cout<<fixed<<showpoint<<setprecision(4)<<"There are "<<days<<" days in "<<sec<<" seconds."<<endl;   //Output days 
    
    }else if(sec>sechr){
        hrs=static_cast<float>(sec)/sechr;      //Calculate hours
        cout<<fixed<<showpoint<<setprecision(4)<<"There are "<<hrs<<" hours in "<<sec<<" seconds."<<endl;    //Output hours            
    
    }else if (sec>secmin){
        min=static_cast<float>(sec)/secmin;                         //Calculate mintutes
        cout<<fixed<<showpoint<<setprecision(4)<<"There are "<<min<<" minutes in "<<sec<<" seconds."<<endl; //Output minutes
    }
    else if (sec>=0){
        cout<<"You entered "<<sec<<" seconds."<<endl;               //Output seconds
    }else
        cout<<"You cannot input a negative amount of seconds."<<endl;
    
    //Exit Stage Right!
    
    return 0;
}

