/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To show price of sold units and their discount
 * Created on June 30, 2015, 9:46 PM
 */

//System Libraries
#include <iostream>

using namespace std;

//User Libraries
/*//Global Constants
 * 
 * //Function Prototypes
 * 
 *///Execution Starts Here!

int main(int argc, char** argv) {

    //Declare variables
    short units;        //units bought
    short price;         //Price
    float tot;          //total after discount
    float mindisc;      //discount for 10-19 units
    float smldisc;      //discount for 20-49 units
    float meddisc;      //discount for 50-99 unit
    float lrgdisc;      //discount for 100 or more units
    
    //initialize variables
    mindisc=.20;        //20% discount for 10-19 units
    smldisc=.30;        //30% discount for 20-49 units
    meddisc=.40;        //40% discount for 50-99 units
    lrgdisc=.50;        //50% discount for 100 or more units
    price=99;           //Price per unit in dollars
    
    cout<<"Enter number of units purchased to find total"<<endl;        //Prompt for units
    cin>>units;             //Input units
    
    if (units>=100){
        tot=(units*price)-(units*price)*lrgdisc;      //Calculate total price after discount
        cout<<"The price after discount for "<<units<<" units is $"<<tot<<"."<<endl;
    }
    else if(units>=50 && units<=99){
        tot=(units*price)-(units*price)*meddisc;      //Calculate total after discount
        cout<<"The price after discount for "<<units<<" units is $"<<tot<<"."<<endl;
    }
    else if(units>=20 && units<=49){
        tot=(units*price)-(units*price)*smldisc;       //Calculate total after discount
        cout<<"The price after discount for "<<units<<" units is $"<<tot<<"."<<endl;
    }
    else if (units>=10 && units<=19){
        tot=(units*price)-(units*price)*mindisc;      //Calculate price after discount
        cout<<"The price after discount for "<<units<<" units is $"<<tot<<"."<<endl;
    }
    else if (units>=0){
        tot=units*price;
        cout<<"The price for "<<units<<" units is $"<<tot<<"."<<endl;
    }
    else{
        cout<<"You cannot input a negative number of units"<<endl;
    }
    
    return 0;
}

