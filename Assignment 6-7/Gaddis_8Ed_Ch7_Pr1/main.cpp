/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: Fill an array and then display largest and smallest number in it
 * Created on July 20, 2015, 1:00 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here

int main(int argc, char** argv) {
    //Declare variables
    unsigned short SIZE=10;                     //Size of array
    int a[SIZE];                                //Array
    int low;                                    // Low Value
    int high;                                   //High Value
    
    for(int i=0;i<SIZE;i++){                    //Loop until array is filled
        cout<<"Input number "<<i+1<<endl;                     
        cin>>a[i];                              //Input value
 
        if(i==0){                               //Set initial number to compare
            low=a[i];   //Set initial value to compare
            high=a[i];
        } 
        
        if(a[i]<low){                           //To find if new value is lower
            low=a[i];
         }else if (a[i]>high){                  //To find if new value is higher
             high=a[i];
         }

    }
    cout<<"The highest value is "<<high<<endl;  //Output results
    cout<<"The lowest value is "<<low<<endl;
    
    //Exit Stage Right!
    return 0;
}

