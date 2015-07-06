/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: To calculate balance after bank fees and/or check fee
 * Created on July 1, 2015, 1:19 PM
 */
 
//System Libraries
#include <iostream>
#include <iomanip>
 
 
using namespace std;
//User Libraries
/*//Global Constants
 * 
 * //Function Protypes
 * 
 * //Execution Starts Here!
 */
int main(int argc, char** argv) {
 
    //Declare variables
    float bal;                  //Balance of account before fees
    int chks;                   //Number of checks written
    float bnkfee;      //Bank fee if balance is under $400 before check fees
    float subBal;               //Balance of account after bank fee
    float chkfee;               //Check fee 
    float gndbal;               //Balance after bank and check fees
    float maxfee;               //Check fee for fewer the 20 checks
    float medfee;               //Check fee for 20-39 checks
    float smlfee;               //Check fee for 40-59 checks
    float minfee;               //Check fee for 60 or more checks
    float feeimp;               //Check fee imposed
 
    //Initialize variables
 
    maxfee=.10;
    medfee=.08;
    smlfee=.06;
    minfee=.04;
    bnkfee=15;
 
    cout<<"Enter account balance."<<endl;                       //Prompt for balance
    cin>>bal;                                                   //Input balance
 
    cout<<"Enter the number of checks written."<<endl;          //Prompt for number of checks written
    cin>>chks;                                                  //Input checks written
 
    if(bal<400){                                                //Balance below $400 gets bank fee
        subBal=bal-bnkfee;                                      //Subtract bank fee from balance
 
        if(chks>=0 && chks<20){
            feeimp=chks*maxfee;                                 //Check fee imposed
            gndbal=subBal-feeimp;                               //Bank balance after bank fee and max check fee
        cout<<"Bank fee imposed for balance under $400"<<endl;  //Prompt to make aware of bank fee
        cout<<"-----------------------------------"<<endl;
        cout<<fixed<<showpoint<<setprecision(2)<<"Bank fee $"<<bnkfee<<endl;                       //Bank fee amount
        }
        else if (chks>=20 && chks<=39){
            feeimp=chks*medfee;                                 //Check fee imposed
            gndbal=subBal-feeimp;                               //Bank balance after bank fee and med check fee
        cout<<"Bank fee imposed for balance under $400"<<endl;  //Prompt to make aware of bank fee
        cout<<"-----------------------------------"<<endl;
        cout<<fixed<<showpoint<<setprecision(2)<<"Bank fee $"<<bnkfee<<endl;                       //Bank fee amount
        }
        else if (chks>=40 && chks<=59){
            feeimp=chks*smlfee;                                 //Check fee imposed
            gndbal=subBal-feeimp;                               //Bank balance after bank fee and small check fee
        cout<<"Bank fee imposed for balance under $400"<<endl;  //Prompt to make aware of bank fee
        cout<<"-----------------------------------"<<endl;
        cout<<fixed<<showpoint<<setprecision(2)<<"Bank fee $"<<bnkfee<<endl;                       //Bank fee amount  
        }
        else if (chks>=60){
            feeimp=chks*minfee;                                 //Check fee imposed
            gndbal=subBal-feeimp;                               //Bank balance after bank fee and minimum fee 
        cout<<"Bank fee imposed for balance under $400"<<endl;  //Prompt to make aware of bank fee
        cout<<"-----------------------------------"<<endl;
        cout<<fixed<<showpoint<<setprecision(2)<<"Bank fee $"<<bnkfee<<endl;                       //Bank fee amount
        }
 
    }
    else{
        if (chks>=0 && chks<20){
            feeimp=chks*maxfee;                                 //Fee imposed after max fee
            gndbal=bal-feeimp;                                  //Bank balance after check fee
        }
        else if (chks>=20 && chks<=39){
            feeimp=chks*medfee;                                 //Fee imposed after medium fee
            gndbal=bal-feeimp;                                  //Bank balance after medium fee
        }
        else if (chks>=40 && chks<=59){
            feeimp=chks*smlfee;                                 //Fee imposed after small fee
            gndbal=bal-feeimp;                                  //Bank balance after small fee
 
        }
        else if (chks>60){
            feeimp=chks*minfee;                                 //Fee imposed after minimum fee
            gndbal=bal-chks*smlfee;                             //Bank balance after small fee
        }
 
    }
    if (chks>=0){
        cout<<fixed<<showpoint<<setprecision(2)<<"Original balance $"<<bal<<endl;                      //Output original balance
        cout<<fixed<<showpoint<<setprecision(2)<<"Check fee imposed $"<<feeimp<<endl;                  //Output check fee imposed
        cout<<fixed<<showpoint<<setprecision(2)<<"New balance $"<<gndbal<<endl;                        //OUtput new balance
    }else{
        cout<<"You cannot enter a negative amount of checks"<<endl;         //Invalid number of checks
 
    }
 
//Exit Stage Right!
    return 0;
}