/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To swap
 * Created on June 29, 2015, 12:59 PM
 */

#include <iostream>

using namespace std;

/*//Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 * 
 */
int main(int argc, char** argv) {

    //Declare Variables
    int a, b;
    int min=10, max=100;
    
    //Input values for a and b
    
    cout<<"Input two integer values between "<<min<<" and "<<max<<endl;
    cin>>a>>b;
    
    //Validate the result
    if(a>=min && a <=max && b>=min && b<=max) {
        //Prompt user for which swap
        cout<<"What swap would you like to choose?"<<endl;
        cout<<"Storage variable -> s or in-place variable -> i ?"<<endl;
        //Declare the variable type
        char type; 
        cin>>type;
        switch(type){
            case 's':{
                int temp=a;
                a=b;
                b=temp;
                cout<<"type is visible because of scope"<<endl;
                cout<<"type = "<<endl;
                break;
            }
            case 'i':{
                a=a^b;
                b=a^b;
                a=a^b;
                
                
            }
            default: cout<<"you don't follow instructions"<<endl;
            
            
        }
        
    }else{
        cout<<"You don't follow instructions"<<endl;
        cout<<"No swap for you"<<endl;
    }
    
    //output results for swap
    cout<<"old a = "<<b<<", new a = "<<a<<endl;
    cout<<"old b = "<<a<<", new b = "<<b<<endl;
    //cout<<temp<<endl; //Scope visibility error
    //cout<<type<<endl; //Scope visibility error
    return 0;
}

