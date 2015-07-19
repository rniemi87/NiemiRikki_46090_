/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: Play Yahtzee!
 * Created on July 18, 2015, 3:53 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

//User libraries

//Global Constants

//Function Prototypes
void hldRoll(unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,
             unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
void hldOne(unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short &,
            unsigned short &);
void hldTwo(unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short &,
            unsigned short &,unsigned short &,unsigned short &);
void hld3(unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short &,
            unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
//Execution Starts Here!

int main(int argc, char** argv) {
    //Declare variables
    unsigned short die1;        //Die one
    unsigned short die2;        //Die two
    unsigned short die3;        //Die three
    unsigned short die4;        //Die four
    unsigned short die5;        //Die five
    char choice;                //Choice to hold or score
    char hold;
    unsigned short hold1,hold2,hold3,hold4,hold5;
    char score;                 //Y/N to enter score function
    unsigned short roll;        //Number of rolls (Can only have 3 rolls))
    unsigned short minval=1;      //Minimum value
    unsigned short maxval=6;      //Maximum value
    unsigned short maxroll=3;   //Maximum number of rolls
    
    //Seed random number generator
    srand(time(0));
    
        //Set random number for dice
    die1= (rand() % (maxval-minval+1))+minval;
    die2= (rand() % (maxval-minval+1))+minval;
    die3= (rand() % (maxval-minval+1))+minval;
    die4= (rand() % (maxval-minval+1))+minval;
    die5= (rand() % (maxval-minval+1))+minval;
    
    for(roll=1;roll<=maxroll;roll++){
        //Output value of dice
        cout<<"Die 1 = "<<die1<<endl;
        cout<<"Die 2 = "<<die2<<endl;
        cout<<"Die 3 = "<<die3<<endl;
        cout<<"Die 4 = "<<die4<<endl;
        cout<<"Die 5 = "<<die5<<endl;
        
        cout<<"Would you like to hold dice any dice? Press 'y' for yes."<<endl;
        cin>>hold;
        if(hold=='y' || hold== 'Y'){
            //Hold/Roll function 
        }else{
            cout<<"Do you want to input your score? "<<endl;
            cin>>score;
            if(score=='y' || score=='Y'){
                //Enter score function
            }
        }
    }
    return 0;
}


/***********************************************************************
                            Hold Three Dice
 * *********************************************************************
 * Input:
 *      die1->Value of die one
 *      die2->Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 *      choice1->First die to hold
 *      choice2->Second die to hold
 *      choice3->Third die to hold
 * Output:
 *      hold1->Value of first held die
 *      hold2->Value of second held die
 *      hold3->Value of third held die
 * **********************************************************************
 ***********************************************************************/
void hld3(unsigned short die1,unsigned short die2,unsigned short die3,unsigned short die4,unsigned short die5,unsigned short &choice1,unsigned short &choice2,unsigned short &choice3,
            unsigned short &hold1,unsigned short &hold2,unsigned short &hold3){
    
    
    
}

/***********************************************************************
                            Hold two Dice
 * *********************************************************************
 * Input:
 *      die1->Value of die one
 *      die2->Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 *      choice1->First die to hold
 *      choice2->Second die to hold
 * Output:
 *      hold1->Value of first held die
 *      hold2->Value of second held die
 * **********************************************************************
 ***********************************************************************/
void hldTwo(unsigned short die1,unsigned short die2,unsigned short die3,unsigned short die4,unsigned short die5,unsigned short &choice1,unsigned short &choice2,
            unsigned short &hold1,unsigned short &hold2){
            
    //First die choice
            if(choice1==1){
                hold1=die1;
            }else if(choice1==2){
                hold1=die2;
            }else if(choice1==3){
                hold1=die3;
            }else if(choice1==4){
                hold1=die4;
            }else if(choice1==5){
                hold1=die5;
            }
    //Second die choice
            if(choice2==1){
                hold2=die1;
            }else if(choice1==2){
                hold2=die2;
            }else if(choice1==3){
                hold2=die3;
            }else if(choice1==4){
                hold2=die4;
            }else if(choice1==5){
                hold2=die5;
            }
    
    
}

/***********************************************************************
                            Hold One Die
 * *********************************************************************
 * Input:
 *      die1->Value of die one
 *      die2->Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 *      choice1->Which die to hold
 * Output:
 *      hold1->Value of first held dice

 * **********************************************************************
 ***********************************************************************/
void hldOne(unsigned short die1,unsigned short die2,unsigned short die3,unsigned short die4,unsigned short die5,unsigned short &choice1,unsigned short &hold1){
    if(choice1==1){
        hold1=die1;
    }else if(choice1==2){
        hold1=die2;
    }else if(choice1==3){
        hold1=die3;
    }else if(choice1==4){
        hold1=die4;
    }else if(choice1==5){
        hold1=die5;
    }
}

/***********************************************************************
                                Hold/Roll
 * *********************************************************************
 * Input:
 *      die1->Value of die one
 *      die2->Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Output:
 *      hold1->Value of first held dice
 *      hold2->Value of second held dice
 *      hold3->Value of third held dice
 *      hold4->Value of fourth held dice
 *      hold5->Value of fifth held dice
 * **********************************************************************
 ***********************************************************************/

void hldRoll(unsigned short die1,unsigned short die2,unsigned short die3,unsigned short die4,unsigned short die5,
             unsigned short &hold1,unsigned short &hold2,unsigned short &hold3,unsigned short &hold4,unsigned short &hold5){
    //Declare variables
    unsigned short howmny;          //How many die to hold
    unsigned short choice1;         //Which die to hold
    unsigned short choice2;         
    unsigned short choice3;
    unsigned short choice4;
    unsigned short choice5;

    //Find out how many dice to hold
    cout<<"How many dice would you like to hold?"<<endl;
    cin>>howmny;
    
    switch(howmny){
        case 1:
            cout<<"What die would you like to hold?"<<endl;
            cin>>choice1;
            //Call Hold one function
            hldOne(die1,die2,die3,die4,die5,choice1,hold1);
            break;
        case 2:
            cout<<"Which dice would you like to hold separated with a space?"<<endl;
            cin>>choice1>>choice2;
            hldTwo(die1,die2,die3,die4,die5,choice1,choice2,
            hold1,hold2);
            break;
        case 3:
            //First die to hold
            if(choice1==1){
                hold1=die1;
            }else if(choice1==2){
                hold1=die2;
            }else if(choice1==3){
                hold1=die3;
            }else if(choice1==4){
                hold1=die4;
            }else if(choice1==5){
                hold1=die5;
            }
            //Second die to hold
            if(choice2==1){
                hold2=die1;
            }else if(choice2==2){
                hold2=die2;
            }else if(choice2==3){
                hold2=die3;
            }else if(choice2==4){
                hold2=die4;
            }else if(choice2==5){
                hold2=die5;
            }
            //Third die to hold
             if(choice3==1){
                hold3=die1;
            }else if(choice3==2){
                hold3=die2;
            }else if(choice3==3){
                hold3=die3;
            }else if(choice3==4){
                hold3=die4;
            }else if(choice3==5){
                hold3=die5;
            }
        case 4:
            //First die to hold
            if(choice1==1){
                hold1=die1;
            }else if(choice1==2){
                hold1=die2;
            }else if(choice1==3){
                hold1=die3;
            }else if(choice1==4){
                hold1=die4;
            }else if(choice1==5){
                hold1=die5;
            }
            //Second die to hold
            if(choice2==1){
                hold2=die1;
            }else if(choice2==2){
                hold2=die2;
            }else if(choice2==3){
                hold2=die3;
            }else if(choice2==4){
                hold2=die4;
            }else if(choice2==5){
                hold2=die5;
            }
            //Third die to hold
             if(choice3==1){
                hold3=die1;
            }else if(choice3==2){
                hold3=die2;
            }else if(choice3==3){
                hold3=die3;
            }else if(choice3==4){
                hold3=die4;
            }else if(choice3==5){
                hold3=die5;
            }
            //Fourth die to hold
             if(choice4==1){
                hold4=die1;
            }else if(choice4==2){
                hold4=die2;
            }else if(choice4==3){
                hold4=die3;
            }else if(choice4==4){
                hold4=die4;
            }else if(choice4==5){
                hold4=die5;
            }
    }
}

