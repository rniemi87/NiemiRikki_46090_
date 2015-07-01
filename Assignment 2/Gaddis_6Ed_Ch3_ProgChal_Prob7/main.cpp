/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate calories consumed from the number of cookies eaten
 * Created on June 28, 2015, 10:03 PM
 */

//System Libraries
#include <iostream>

using namespace std;

/*//Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution starts here
 */
int main(int argc, char** argv) {

    //Declare variables
    unsigned short cookserv;    //Cookies per serving
    float cookies;     //Cookies eaten;
    float serv;                 //Servings consumed
    float cal;                  //Calories per serving
    float caleatn;              //Calories consumed
    //Initialize variables
    cookserv=4;                 //4 cookies per serving
    cal=300;                    //Calories per serving
    serv=cookies/cookserv;      //Number of servings eaten from cookies eaten
    caleatn=serv*cal;           //Calories consumed
            
    cout<<"Enter how many cookies you haven eaten then press Enter"<<endl;      //Prompt to input cookies eaten
    cin>>cookies;               //Input cookies eaten
    serv=cookies/cookserv;      //Calculate servings eaten
    caleatn=serv*cal;           //Calculate calories eaten
    
    cout<<"You have consumed "<<caleatn<<" calories."<<endl;        //Output calories eaten
    
    
    //Exit Stage Right!
      
    return 0;
}

