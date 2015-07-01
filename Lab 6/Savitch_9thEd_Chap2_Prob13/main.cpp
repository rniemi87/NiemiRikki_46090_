/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: How many candy bars can I eat per day w/o gaining wieght
 * Created on June 30, 2015, 12:18 PM
 */

//System Libraries
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

/*//User Libraries
 * 
 * //Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 * 
 */
int main(int argc, char** argv) {

    //Declare variables
    unsigned short wtLbs, htInch, ageYrs, bmr;
    unsigned char nChcBar, calChoc=230;
    char sex;
    ifstream input;
    
    //loop as long as we have data
    input.open("bmr.dat");
    //Exhaust the data in the file
    while(input>>sex>>wtLbs>>htInch>>ageYrs){
        
        if (sex=='F'){
            bmr=655+4.3*wtLbs+4.7*htInch-4.7*ageYrs;
        }
        else{
            bmr=66+66.3*wtLbs+12.9*htInch-6.8*ageYrs;
        }
        //What is the equivalent number of chocolate bars
        nChcBar=bmr/calChoc;
        //Output the results
        cout<<"Sex = "<<sex<<endl;
        cout<<"wt = "<<wtLbs<<" (lbs)"<<endl;
        cout<<"Ht = "<<htInch<<" (inches)"<<endl;
        cout<<"Age = "<<ageYrs<<" (years)"<<endl;
        cout<<"Your BMR = "<<bmr<<" (cal)"<<endl;
        cout<<"Your number of candy bars you may consume = "<<static_cast<int>(nChcBar)<<endl;
        cout<<endl<<endl;
        
        //Exit stage right
        
    }
    
    
    return 0;
}

