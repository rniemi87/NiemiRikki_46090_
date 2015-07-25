/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To sort two arrays using bubble and selection sort
 * Created on July 24, 2015, 9:58 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void bubble(int [],int,int&);
void slct(int [],int,unsigned short &);
//Execution Starts Here!
int main(int argc, char** argv) {
    //Declare variables
    int size=20;                //Size of array
    int a[size];
    int b[size];
    int min=1;
    int max=99;
    int bcount;
    unsigned short scount;
    //Seed random number generator
    srand(time(0));
    
    for(int i=0;i<size;i++){                //Fill array a
        a[i]=(rand()%(max-min+1))+min;
    }
    
    for(int i=0;i<size;i++){                //Fill array b
        b[i]=(rand()%(max-min+1))+min;
    }
    
    for(int i=0;i<size;i++){
        cout<<a[i]<<endl;

    }
    
    cout<<"Sorted array a"<<endl;
    bubble(a,size,bcount);
    
    for(int i=0;i<size;i++){
        cout<<a[i]<<endl;
    }
    cout<<"There were "<<bcount<<" exchanges."<<endl;
    

   for(int i=0;i<size;i++){
        cout<<b[i]<<endl;
    }
    slct(b,size,scount);
    cout<<"Sorted array b"<<endl;
    for(int i=0;i<size;i++){
        cout<<b[i]<<endl;
    }
   cout<<"There were "<<scount<<" exchanges."<<endl;
    
    //Exit Stage Right
    return 0;
}
void slct(int b[],int size ,unsigned short &scount){
    //Declare variables
    int strtscn,minInd,minval;
    scount=0;
    
    for(strtscn=0;strtscn<size-1;strtscn++){
        minInd=strtscn;
        minval=b[strtscn];
        for(int i=strtscn+1;i<size;i++){
            if(b[i]<minval){
                minval=b[i];
                minInd=i;
            }
            b[minInd]=b[strtscn];
            b[strtscn]=minval;
            scount+=1;
        }

    }

}

void bubble(int a[],int size,int &bcount){
    //Declare variables
    bool swap;
    int temp;
    bcount=0;
    do{
        swap=false;
        for(int i=0;i<size;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
                bcount++;
            }
        }
    }while(swap);
}
