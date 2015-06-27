/* 
 * File:   main.cpp
 * Author: Rikki
 * Purpose: TO prove your math instructor wrong about adding two postive numbers.. not 
 * Created on June 25, 2015, 11:16 AM
 */

//System Library
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//User Libraries
/*
 * //GLobal constants
 * 
 * //Function Prototypes
 * 
 * //Execution Begins
 */
int main(int argc, char** argv) {

    //Declare Variables
    unsigned short a,b,c;
    short d, e, f;
    ofstream out;
    srand(static_cast<unsigned int>(time(0)));
    int thrwDce;
    
    //Initialize values
    
    a=20000;
    b=50000;
    d=20000;
    e=30000;
    out.open("numbers.dat");
    thrwDce=rand()% 6+1;
    
    
    
    
    //Perform a simple addition
    
    c=a+b;
    f=d+e;
            
    //Output results
   cout<<setw(6)<<c<<" = "<<a<<" + "<<b<<endl;
   cout<<setw(6)<<f<<" = "<<d<<" + "<<e<<endl; 
   cout<<pow(2,3)<<" = "<<exp(3*log(2))<<endl;
   out<<c<<" = "<<a<<" + "<<b<<endl;
   cout<<"The Dice value = "<<thrwDce<<endl;
   out<<pow(2,3)<<" = "<<exp(3*log(2))<<endl;
   //Exit Stage RIght!
   out.close(); 
    
    return 0;
}

