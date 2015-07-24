/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To search and see if a charge account number is in an array
 * Created on July 24, 2015, 1:52 AM
 */

//System LIbraries
#include <iostream>
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void slctSrt(int [],int);
int binSrch(int [],int,int);

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    int size=18;            //Size of array
    int number[size]={5658845,4520125,7895122,8777541,8451277,1302850,
                      8080152,4562555,5552012,5050552,7825877,1250255,
                      1005231,6545231,3852085,7576651,7881200,4581002};
    bool found=false;                   //Set flag 
    int account;                        //Account to search for
    int result;                         //Position 

    //Prompt for account number input
    cout<<"Enter a 7 digit account number."<<endl;
    cin>>account;
 
    
    if(result==-1){
        cout<<"This account number was not found."<<endl;
    }else{
        cout<<"This account was found at position "<<result+1<<endl;
    }
    
    slctSrt(number,size);             //Sort array
    
    result=binSrch(number,size,account);
    
    if(result==-1){
        cout<<"This account was not found"<<endl;
        
    }else{
        cout<<"This account was found at position "<<result<<endl;
    }
    //Exit Stage Right!
    return 0;
}
int binSrch(int number[],int size,int account){
    int first;
    int last=size-1;
    int middle;
    int position=-1;
    bool found=false;
    
    while(!found&&first<last){
        middle=(first+last)/2;
        
        if(number[middle]==account){
            found=true;
            position=middle;
            
        }else if(number[middle]>account){
            last=middle-1;
        }else{
            first=middle+1;
            
        }
          return position;
    }
    
  
}





void slctSrt(int number[],int size){
    int minval;                 //Minimum value
    int stScan;                 //Start scan
    int minindex;               //Minimum index
    
    for(stScan=0;stScan<(size-1);stScan++){
        minindex=stScan;
        minval=number[stScan];
        
        for(int index=(stScan+1);index<size;index++){
            if(number[index]<minval){
               minval=number[index];
               minindex=index;
            }
        }
       number[minindex]=number[stScan]; 
       number[stScan]=minval;
    }
    
}