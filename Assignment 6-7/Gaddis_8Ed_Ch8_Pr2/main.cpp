/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To see if a lottery player has won
 * Created on July 24, 2015, 10:45 AM
 */

//System LIbraries
#include <iostream>
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int linsrch(int[],int,int);
//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    int size=10;            //Size of array
    int number[size]={13579,26791,26792,33445,55555,62483,77777,79422,85647,93121};
    int winning;           //Winning ticket number
    int result;            //Position 

    //Prompt for a winning ticker
    cout<<"Enter the 5 winning numbers."<<endl;
    cin>>winning;
    
    result=linsrch(number,size,winning);
    
    if(result==-1){
        cout<<"You did not win."<<endl;
    }else{
        cout<<"You won!"<<endl;
    }
    
    //Exit Stage Right!
    return 0;
}
int linsrch(int number[],int size,int winning){
    //Declare variables
    int position=-1;            //Position of found account number
    bool found=false;                   //Set flag 
    
    for(int i=0;i<size && !found; i++){ //Loop through whole array or until account number is found
        
        if(winning==number[i]){
            found=true;                 //Set flag to true
            position=i;                 //Record position
        }
    }
    
    return position;
}
