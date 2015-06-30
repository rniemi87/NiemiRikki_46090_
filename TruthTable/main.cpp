/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To show the truth
 * Created on June 29, 2015, 12:43 PM
 */

//System LIbraries
#include <iostream>

using namespace std;

//User Libararies

/*//Global Constants
 * 
 * Function Prototypes
 * 
 * //Exectution Starts Here! 
 */

int main(int argc, char** argv) {

    //Declare Variables
    bool x, y;
    
    //Output heading of the table
    cout<<"The Truth Table"<<endl;
    cout<<"X Y !X !Y X&&Y X||Y X^Y (X^Y)^Y ";
    cout<<"(X^Y)^X !X||!Y !(X||Y) !X&&!Y"<<endl;
    
    //Row 1 output
    x=true;y=true;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<" ";
    cout<<(!x?'T':'F')<<" ";
    cout<<(!y?'T':'F')<<" ";
    cout<<(x&&y?'T':'F')<<"  "<<endl;
    
    //Row 2 Output
    cout<<(x||y?'T':'F')<<" ";
    cout<<(x^y?'T':'F')<<" ";
    cout<<((x^y)^y?'T':'F')<<" ";
    cout<<((x^y)^x?'T':'F')<<" ";
    cout<<(!(x&&y)?'T':'F')<<" "<<endl;
    
    //Row 3 Output
    cout<<(!x||!y?'T':'F')<<" ";
    cout<<(!(x||y)?'T':'F')<<" ";
    cout<<(!x&&!y?'T':'F')<<" ";
    
    
    
    
    
    
    
    
    return 0;
}

