/* 
 * File:   main.cpp
 * Author: Rikki
 *
 * Created on June 25, 2015, 12:25 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>


using namespace std;

/*//Global constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 * 
 */
int main(int argc, char** argv) {

    //Declare Variables
    float popUS;        //Population of US
    float popEng;       //Population of England
    float vcUS;         //Violent crimes US
    float vcEng;        //Violent crimes England
    float pctvcUS;      //Percent violent crimes per population of US
    float pctvcEng;     //Percent violent crimes per population of England
    
    //Initialize variables
    
    popUS=318.9*10e6;       //Population of US
    popEng=64.1*10e6;       //Population of England
    vcUS=11.88*10e6;        //Violent crimes in US
    vcEng=6.52*10e6;        //Violent crimes in England
    
    pctvcUS=vcUS/popUS*100;         //Percent violent crimes in US
    pctvcEng=vcEng/popEng*100;      //Percent violent crimes in England
    
    cout<<fixed<<showpoint<<setprecision(2)<<"The percent of violent crimes committed in the US is "<<pctvcUS<<"%"<<endl;      //Output percent of violent crimes in US
    cout<<fixed<<showpoint<<setprecision(2)<<"The percent of violent crimes committed in England is "<<pctvcEng<<"%"<<endl;    //Output percent of violent crimes in England
   
    //Exit Stage Right!
    
    return 0;
    
    
}

