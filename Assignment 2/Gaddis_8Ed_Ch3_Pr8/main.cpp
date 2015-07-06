/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To find out how many widgets are on a pallet from weight
 * Created on July 4, 2015, 9:23 PM
 */

#include <iostream>
#include <iomanip>

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
    float totwdwt;                              //Total widget weight
    float palwt;                                //Pallet weight
    float totwt;                                //Weight of widgets and pallet
    float widgets;                              //Number of widgets on a pallet
    float widwt;                                //Weight of one widget
    
    //Intialize variables
    widwt=12.5;                                 //Weight of widgets in pounds
    
    cout<<"Enter the weight of the pallet in lbs. \n";                 //Prompt for pallet weight
    cin>>palwt;                                                         //Input pallet weight
    
    cout<<"Enter the total weight of the pallet and its contents \n";   //Prompt for weight of widgets and pallet
    cin>>totwt;
    
    totwdwt=totwt-palwt;                                                //Calculation to find total weight of widgets
    
    widgets=totwdwt/widwt;                                              //Calculation to find number of widgets
    
    cout<<"There are "<<widgets<<" widgets on the pallet"<<endl;       //Output results
    
    //Exit Stage Right!
    
    return 0;
}

