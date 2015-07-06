/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: Word Game                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
 * Created on July 4, 2015, 1:16 PM
 */

#include <iostream>
#include <string>

using namespace std;
//User Libraries
/*
 * //Global Constants
 * 
 * //Function Prototypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {

    //Declare Variables
    string name;                                    //Name of user
    string age;                                     //User's name
    string city;                                    //User's city
    string college;                                 //User's college
    string prof;                                    //User's Profession
    string anml;                                    //Name of animal
    string petnm;                                   //Pet name
    
    cout<<"Enter your first and last name\n";       //Prompt for name
    getline(cin, name);                             //Enter name
    
    cout<<"Enter your age \n";                      //Prompt for age
    getline(cin, age);                              //Enter age
    
    cout<<"Enter a city \n";                        //Prompt for city
    getline(cin, city);                             //Enter city
    
    cout<<"Enter a college \n";                     //Prompt for college
    getline(cin, college);                          //Enter college
    
    cout<<"Enter a profession \n";                  //Prompt for profession
    getline(cin, prof);                             //Enter profession
    
    cout<<"Enter a type of animal \n";              //Prompt for animal
    getline(cin, anml);                             //Enter animal
    
    cout<<"Enter a pet's name \n";                  //Prompt for pets name
    getline(cin, petnm);                            //Enter pets name
    
    cout<<"There was once a person named "<<name<<" who lived in "<<city<<". \n";               //Output results
    cout<<"At the age of "<<age<<", "<<name<<" went to college at "<<college<<". \n";
    cout<<name<<" graduated and went to work as a "<<prof<<". \n";
    cout<<"Then, "<<name<<" adopted a pet "<<anml<<" named "<<petnm<<"."<<endl;
    
    //Exit Stage Right!
    
    return 0;
}

