/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To record food eaten by monkeys and average food eaten by a family of monkeys in a 2-D array
 * Created on July 22, 2015, 1:43 PM
 */

//Sysem Libraries
#include <iostream>
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    int  nMonkey=3;               //Number of rows
    int nDay=5;               //Number of columns
    unsigned short toteat=0;              //Total eaten
    unsigned short highday;             //Day where food is eaten is highest
    unsigned short lowday;              //Food eaten where food is lowest
    float avg;                          //Average food eaten
    unsigned short foodeat;                //Food eaten in lbs.
    int  monkey;              //Number of monkey
    int day;                 //Day of week
    int food[nMonkey][nDay];
    
    //To fill array rows
    for(monkey=0;monkey<nMonkey;monkey++){
        
        
        for(int day=0;day<nDay;day++){       //To fill array columns
            cout<<"Enter food eaten by monkey #"<<monkey+1<<" on day #"<<day+1<<endl;
            cin>>food[monkey][day];
            
            //Calculate average total of food eaten by all monkeys
            toteat+=food[monkey][day];
            
            
            
            
        }
        
        
        
    }
    avg=toteat/(nMonkey);
    
    cout<<"The average amount of food eaten by the family of monkeys is = "<<avg<<endl;
    
    //Exit Stage Right!
    return 0;
}

