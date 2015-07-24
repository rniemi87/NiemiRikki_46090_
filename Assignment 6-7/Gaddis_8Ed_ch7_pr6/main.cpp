/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calclulate the number of rainy, cloudy, and sunny days in a summer session
 * Created on July 23, 2015, 12:32 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Starts Here!

int main(int argc, char** argv) {
    //Declare variables
    ifstream inFile;                            //Input file object
    ofstream outFile;                           //Ouput file object
    unsigned short ROWS;                        //Rows
    unsigned short COLS;                        //Number of columns
    char wthr[ROWS][COLS];                      //Array to hold weather data
    unsigned short totrain=0;                   //Total rainy days
    unsigned short totcld=0;                    //Total cloudy days
    unsigned short totsun=0;                    //Total sunny days
    unsigned short mntRain;                     //Number of rainy days in month
    unsigned short mntSun;                      //Number of sunny days in month
    unsigned short mntCld;                      //Number of cloudy days in month
    unsigned short highRn;                      //Highest number of rainy days
    unsigned short mnHgRn;                      //Month of highest rainy days
    
    outFile.open("RainOrShine.txt");
    
    for(int r=0;r<ROWS;r++){//Loop for months
     //Set rain values to zero for each month
      mntRain=0;      
      mntSun=0;
      mntCld=0;
      
        for(int c=0;c<COLS;c++){//Loop for columns
            
            cout<<"Input r, s, or c "<<endl;
            outFile<<wthr[r][c]<<endl;

            //Input from file
            inFile>>wthr[r][c];
                if(wthr[r][c]=='r'){
                    mntRain++;
                }else if(wthr[r][c]=='c'){
                    mntCld++;
                }else if(wthr[r][c]=='r'){
                    mntSun++;
                }
        }
      
      if(r==0){
          highRn=mntRain;    //Set rain value to compare others against
          mnHgRn=0;          //Set rain month to initial month
      }else if(mntRain>highRn){
          highRn=mntRain;       //Set new value to highRn
          mnHgRn=r;             //Record month where the happened
      }
      
      //Calculate total rain
      totrain+=mntRain;
      //Calculate total sun
      totsun+=mntSun;
      //Calculate total cloudy
      totcld+=mntCld;
      
      //Get month name and output totals for month
      if(r==0){
          cout<<"June had : "<<endl;
          cout<<mntRain<<" rainy days"<<endl;
          cout<<mntCld<<" cloudy days"<<endl;
          cout<<mntSun<<" sunny days"<<endl;
      }else if(r==1){
          cout<<"July had : "<<endl;
          cout<<mntRain<<" rainy days"<<endl;
          cout<<mntCld<<" cloudy days"<<endl;
          cout<<mntSun<<" sunny days"<<endl;
      }else if (r==2){
          cout<<"August had : "<<endl;
          cout<<mntRain<<" rainy days"<<endl;
          cout<<mntCld<<" cloudy days"<<endl;
          cout<<mntSun<<" sunny days"<<endl;
      }

      
    }
    
    //Output totals for summer
    cout<<"The total amount of rainy days for the summer = "<<totrain<<endl;
    cout<<"The total amount of cloudy days for the summer = "<<totcld<<endl;
    cout<<"The total amount of sunny days for the summer = "<<totsun<<endl;
    
   
    
    //Get name of month with highest rain
    if(mnHgRn==0){
        cout<<"June had the highest number of rainy days"<<endl;
    }else if (mnHgRn==1){
        cout<<"July had the highest number of rainy days"<<endl;
    }else if (mnHgRn==2){
        cout<<"August had the highest number of rainy days"<<endl;
    }
    
    inFile.close();   //Closing file
    //Exit Stage Right!
    return 0;
}

