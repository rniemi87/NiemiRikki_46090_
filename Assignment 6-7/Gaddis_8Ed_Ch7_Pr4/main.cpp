/* 
 * File:   main.cpp
 * Author: Rikki  Niemi
 * Purpose: To display the numbers in array that are bigger than n
 * Created on July 22, 2015, 1:04 PM
 */

//System libraries
#include <iostream>
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void chkN(int [] ,unsigned short,unsigned short);

//Execution Stars Here!
int main(int argc, char** argv) {
    //Declare variables
    unsigned short n;   //Number to compare values in array with
    unsigned short SIZE=10;     //Size of array
    unsigned short minval=1;      //Minimum possible number in array
    unsigned short maxval=10;      //Maximum value of number in array
    int a[SIZE];                //Array
    
    cout<<"Input the number n you wish to compare against "<<endl;
    cin>>n;
    
    //Seed random number generator
    srand(time(0));
    
    //Fill array with random numbers
    for(int i=0;i<SIZE;i++){
        a[i]=(rand()%(maxval-minval+1))+minval;
    }
    
    //Check n function
    chkN(a,SIZE,n);
    
    //Exit Stage Right
    return 0;
}

/******************************************
             Check numbers
 ******************************************
 Input:
        a[]-> array filled with random numbers
        SIZE-> size of array
        n-> value of number to which you will
        compare numbers in array
 Output:
        numbers that are greater than n
 ********************************************
 ********************************************/
void chkN(int a[],unsigned short SIZE,unsigned short n){
    
    //Loop to compare numbers in array
    for(int i=0;i<SIZE;i++){
        if (n<a[i]){
            cout<<a[i]<<endl;   //Display number if greater than number n
        }else{
            
        }
    }
}
