/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To create a math tutor program
 * Created on July 4, 2015, 12:38 PM
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

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
    int minval;                     //Minimum value
    int maxval;                     //Maximum value
    int ans;                        //Actual answer
    int studans;                    //Student's answer
    int numone;                     //Number one
    int numtwo;                     //Number two
    char again;                     //(y/n)
    
    unsigned seed=time(0);          //Get system time
    srand(seed);                    //Seed random number generator
    
    
    
    
    do{
        //Initialize variables
        
        minval=1;                                                       //Minimum value
        maxval=999;                                                     //Maximum value
        numone=(rand()%(maxval-minval+1)+minval);                       //First number
        numtwo=(rand()%(maxval-minval+1)+minval);                       //Second number
        ans=numone+numtwo;                                              //Answer
        
        cout<<"   "<<numone<<endl;                                      //Output both numbers
        cout<<" + "<<numtwo<<endl;
        cout<<"---------------"<<endl;
        
        cin>>studans;                                                   //Input student answer
            if(studans==ans){
                cout<<"Congratulations! You are correct!"<<endl;        //Output congratulations on correct answer    

            }else{
                cout<<"Incorrect."<<endl;                               //Output if incorrect
            }
        cout<<"Would you like to try another?"<<endl;                   //Ask to try again
        cin>>again;                                                     //Input choice
        
    }while(again=='y' ||again=='Y');        
    
    //Exit Stage Right!
    
    return 0;
}

