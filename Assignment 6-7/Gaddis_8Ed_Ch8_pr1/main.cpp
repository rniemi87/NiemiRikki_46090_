/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To search and see if a charge account number is in an array
 * Created on July 24, 2015, 10:08 AM
 */

//System LIbraries
#include <iostream>
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int linsrch(int[],int,bool,int);
//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    int size=18;            //Size of array
    int number[size]={5658845,4520125,7895122,8777541,8451277,1302850,
                        8080152,4562555,5552012,5050552, 7825877, 1250255,
                        1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    bool found=false;                   //Set flag 
    int account;                        //Account to search for
    int result;            //Position 

    //Prompt for account number input
    cout<<"Enter a 7 digit account number."<<endl;
    cin>>account;
    
    result=linsrch(number,size,found,account);
    
    if(result==-1){
        cout<<"This account number was not found."<<endl;
    }else{
        cout<<"This account was found at position "<<result+1<<endl;
    }
    
    //Exit Stage Right!
    return 0;
}
int linsrch(int number[],int size,bool found,int account){
    //Declare variables
    int position=-1;            //Position of found account number
    
    for(int i=0;i<size && !found; i++){ //Loop through whole array or until account number is found
        
        if(account==number[i]){
            found=true;                 //Set flag to true
            position=i;                 //Record position
        }
    }
    
    return position;
}
