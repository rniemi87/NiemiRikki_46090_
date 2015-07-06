/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate income generated from a softball game
 * Created on July 3, 2015, 6:45 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

/*//Global constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {

    //Declare variables
    short clsA;                    //Number of class A tickets sold
    short clsB;                    //Number of class B tickets sold
    short clsC;                    //NUmber of class C tickets sold
    short prcA;                    //Price of class A tickets
    short prcB;                    //Price of class B tickets sold
    short prcC;                    //Price of class C tickets sold
    float inc;                              //Income generated from tickets sold
    
    //Initialize Variables
    prcA=15;
    prcB=12;
    prcC=9;
    
    cout<<"Input the number of class A, class B, and class C tickets separated by a space"<<endl;
    
   cin>>clsA>>clsB>>clsC;
   
   while(clsA<0 || clsB<0 || clsC<0 ){
            
            cout<<"You cannot input a negative number, please input a valid number of tickets."<<endl;
            cin>>clsA>>clsB>>clsC;
   }                                                                                            //Input tickets sold     
    
    inc=clsA*prcA+clsB*prcB+clsC*prcC;                                                          //Calculation for income
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"The income generated is $"<<inc<<"."<<endl; 
    

    
    
    
    return 0;
}

