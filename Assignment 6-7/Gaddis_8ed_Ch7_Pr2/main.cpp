/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: Rainfall calculator
 * Created on July 20, 2015, 1:42 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts here!
int main(int argc, char** argv) {
    //Declare variables
    short month;                        //Month
    float rainfall;                     //Rainfall amount in inches
    float totfall;                      //Total rainfall for year
    float MnthAvg;                      //Monthly average rainfall             
    unsigned short SIZE=12;             //Size of array
    float a[SIZE];                      //Array to hold rainfall amounts
    unsigned short minfall=0;           //Minimum rainfall allowed for a month   '
    unsigned short hrain;               //High rain in inches
    string mnthnam;                     //Month name
    
    for(int i=0;i<SIZE;i++){
       cout<<"Enter a positive number for the amount of rainfall for month "<<i+1<<endl;
       cin>>a[i];
       
        if(a[i]<minfall){
            while(a[i]<minfall){
             cout<<"Enter a positive number for the amount of rainfall for month "<<i+1<<endl;
             cin>>a[i];
         }   
        }
       if(i==0){
           hrain=a[i];
           month=i;   
       }if(a[i]>hrain){
           hrain=a[i];
           month=i;
       }
       
        totfall+=a[i];                  //Calculate total rainfall for year
      
        
    }
    if(month==0){
        mnthnam='Januaray';
    }else if(month==1){
        mnthnam='Febuary';
    }else if(month==2){
        mnthnam='March';
    }else if(month==3){
        mnthnam='April';
    }else if(month==4){
        mnthnam='May';
    }else if(month==5){
        mnthnam='June';
    }else if(month==6){
        mnthnam='July';
    }else if(month==7){
        mnthnam='August';
    }else if(month==8){
        mnthnam='September';
    }else if(month==9){
        mnthnam='October';
    }else if(month==10){
        mnthnam='November';
    }else if(month==11){
        mnthnam='December';
    }
    
    
    cout<<"Total rainfall = "<<totfall;
    cout<<"The month with the highest rain = "<<mnthnam<<endl;
    cout<<hrain<<endl;
    
    
    return 0;
}

