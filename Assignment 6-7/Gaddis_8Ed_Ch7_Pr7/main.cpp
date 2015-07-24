/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: Read in numbers from a file into an array
 * Created on July 23, 2015, 1:38 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!

int main(int argc, char** argv) {
    //Declare variables
    ifstream inFile;            //Input file object
    ofstream outFile;           //Output file object
    unsigned short SIZE=100;    //Size of array
    unsigned short numArry[SIZE];//Array of random numbers
    unsigned short r[SIZE];//Array that will receive numbers from file
    string name;                //Name that user chooses for file
    string fileN;               //Full file name
    
    //Prompt for desired file name
    cin>>name;
    
    fileN="name";
    
    outFile
    
    cout<<fileN<<endl;
    
    
    
    outFile.close();
    //Exit Stage right!
    return 0;
}

