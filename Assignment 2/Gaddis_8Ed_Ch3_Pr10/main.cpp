/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To display the minimum amount of insurance
 * Created on July 3, 2015, 8:22 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries

/*//Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {

    //Declare variables
    float inspct;                     //Recommended insurance percentage
    float rplcst;                     //Replacement cost
    float insrnce;                    //Insurance needed
    char type;                      //Do again (y/n)
    
    //Initialize variables
    inspct=.80;                     //Recommended insurance is 80% of replacement cost
      
    do{
        
        
        cout<<"Input the replacement cost of the building: "<<endl;     //Prompt for replacement cost
        cin>>rplcst;                                                    //Input replacement cost
        
        
        insrnce=inspct*rplcst;                                          //Recommended insurance calculation
        
        cout<<"Your recommended minimum insurance amount is "<<insrnce<<endl;
        
        cout<<"Do you want to calculate another amount? (y/n)"<<endl;
        cin>>type;
    }while(type=='y' || type=='Y');
    
    //Exit Stage Right!
    
    return 0;
}

