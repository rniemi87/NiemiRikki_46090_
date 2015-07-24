/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To record sales of salsa, display sales of each type, and display highest and lowest selling products
 * Created on July 22, 2015, 12:32 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    unsigned short high;                //High number of jars
    unsigned short low;                 //Low number of jars
    unsigned short SIZE=5;              //Size of array
    unsigned short highnam;             //Index for high name
    unsigned short lowname;             //Index for low name
    unsigned short totSls=0;              //Total sales
    
    string name[]={"Mild","Medium","Sweet","Hot","Zesty"};                  //Array to hold names
    unsigned short jars[SIZE];          //Array to hold jars sold
    
    for(int i=0;i<SIZE;i++){
        cout<<"Enter the number of jars sold of "<<name[i]<<endl;
        cin>>jars[i];
        
        totSls+=jars[i];
    }
    
    for(int i=0;i<SIZE;i++){
        if(i==0){
            high=jars[i];               //If first vale, set it to both high and low
            low=jars[i];
        }else{
            if(jars[i]>high){           //Compare subsequent values to new values in array
                high=jars[i];           //If new value is higher, set it to high
                highnam=i;              //Record number of index where it is high

            }else if(jars[i]<low){ 
                low=jars[i];            //If new value is lower, set it to low
                lowname=i;              //Record number of index of lowest value
            }
        }
        cout<<"The sales for "<<name[i]<<" salsa = "<<jars[i]<<" jars."<<endl;  //Display sales  
    }
    cout<<"The total number of jars sold this period = "<<totSls<<endl;         //Display total sales
    
    //Display highest and lowest selling products
    cout<<"The highest selling product is the "<<name[highnam]<<" salsa, selling "<<high<<" jars."<<endl;
    cout<<"The lowest selling product is the "<<name[lowname]<<" salsa, selling "<<low<<" jars."<<endl;
    
    //Exit Stage Right!
    return 0;
}

