/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate the amount of tax paid on gas per gallon, and the percentage of the price you pay in tax
 * Created on June 24, 2015, 1:19 PM
 */

//System Library
#include <iostream>

using namespace std; //I/O Library

//Global Constants
 

int main(int argc, char** argv) {
//Declare variables
    float fdtx;     //Federal tax amount
    float galpc;    //Price per gallon
    float catx;     //Cal Ex tax amount
    float netgas;   //Price before tax (not including sales)
    float totnet;   //Price before all tax
    float totax;    //Total tax paid
    float pctTax;   //Percent tax paid per gallon 
    float slstx;    //CA sales tax
    float slspd;    //CA sales tax paid
    short CNVPCT;   //Percent conversion 
    
    CNVPCT=100;     //Value assigned to allow conversion to percent
    fdtx=.18f;      //Federal tax in cents
    catx=.38f;      //CA Ex tax in cents
    slstx=.08f;     //CA sales tax 8%
    galpc=3.69f;     //Price per gallon
    
    netgas=galpc-fdtx-catx; //Price of gas before Fed tax and CA Ex tax

    cout<<"The price of gas before CA ex. tax and federal tax is $"<<netgas<<"."<<endl; //Display price before fed and CA ex tax
    
    totnet=.92*netgas;
    
    cout<<"The price of gas before all tax is $"<<totnet<<"."<<endl;            //Display price before all taxes
    
    slspd=netgas*.08;       //Amount of sales tax paid on gallon of gas
            
    cout<<"Per gallon, there is $"<<slspd<<" paid in sales tax."<<endl;        //Display sales tax paid
    
    totax=fdtx+catx+slspd;  //Sum of all taxes applied to gas
    
    cout<<"The total tax paid per gallon is $"<<totax<<"."<<endl;   //Display total tax paid per gallon
    
    pctTax=totax/galpc*CNVPCT;   //Percent of tax paid per gallon of gas
    
    cout<<"There is a total of "<<pctTax<<" percent paid per gallon of gas."<<endl; //Display percent of tax per gallon
    
    //The End
   
    return 0;
}

