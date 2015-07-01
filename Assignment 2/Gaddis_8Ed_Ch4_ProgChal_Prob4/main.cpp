/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate the areas of two rectangles
 * Created on June 29, 2015, 10:33 PM
 */

//System Libraries
#include <iostream>

//User Libraries
using namespace std;

/*//Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {

    short x,y;      //Rectangle one length and width
    short l,w;      //Rectangle two length and width
    short recone;   //Rectangle one area
    short rectwo;   //Rectangle two area
    
    recone=x*y;      //Calculate area one
    rectwo=l*w;      //Calculate area two
    
    cout<<"Enter the length and width of the first rectangle separated by a single space"<<endl;    //Prompt for first dimensions
    cin>>x>>y;      //Input dimensions

    cout<<"Enter the length and width of the second rectangle separated by a single space"<<endl;    //Prompt for second dimensions
    cin>>l>>w;      //Input dimensions
    
    if (l*w>x*y){
        cout<<"Rectangle two has the largest area."<<endl;  //Rectangle two largest
    }
    else{
        if (l*w==x*y){          //Areas equal
            cout<<"The areas of both rectangles are equal"<<endl;
        }
        else{                   //Rectangle one largest
            cout<<"Rectangle one has the largest area."<<endl;
        }
    }
    
    //Exit Stage Right!
    return 0;
}

