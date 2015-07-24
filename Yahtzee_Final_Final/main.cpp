/* 
 * File:   main.cpp
 * Author: Rikki Niemi
 * Purpose: Play Yahtzee!
 * Created on July 20, 2015, 10:48 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

//User libraries

//Global Constants

//Function Prototypes
void hldRoll(unsigned short &,unsigned short & ,unsigned short& ,unsigned short &,unsigned short&);
void roll4(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
void roll3(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
void roll2(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
void roll1(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
void scrUppr(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
void rollDice(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short,unsigned short);
int scrAce(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
int scrTwo(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
int scrThr(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
int scrFour(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
int scrFive(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
int scrSix(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
void scrLower(unsigned short & ,unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short&);
int check3k(unsigned short &,unsigned short &,unsigned short &,unsigned short &,unsigned short &);
void prtCard();

//Execution Starts Here!

int main(int argc, char** argv) {
    //Declare variables
    unsigned short die1;        //Die one
    unsigned short die2;        //Die two
    unsigned short die3;        //Die three
    unsigned short die4;        //Die four
    unsigned short die5;        //Die five
    char play;                  //y/n to enter game
    char holdAgn;               //Select to hold again
    char hold;
    char score;                 //Y/N to enter score function
    unsigned short roll;        //Number of rolls (Can only have 3 rolls))
    unsigned short minval=1;      //Minimum value
    unsigned short maxval=6;      //Maximum value
    unsigned short maxroll=3;   //Maximum number of rolls
    unsigned int nRound=1;         //Number of round
    unsigned int totRnd;        //Total number of rounds
    unsigned short totscore=0;
    char rollAgn;               //y/n to roll again
    
    //File objects
    
    ofstream outFile("score.txt");
    ifstream inFile;
    
    //Score function variables
    char chosScr;           //Choose section to score 

    //Seed random number generator
    srand(time(0));
    
    cout<<"Play Yahtzee!"<<endl;
    cout<<"Type 'y' to play game or 'n' to exit"<<endl;
   cin>>play;                                               //Enter game
    if(play=='y' || play=='Y'){
 
        do{        
            rollDice(die1,die2,die3,die4,die5,minval,maxval);   //Roll dice
            for(roll=1;roll<maxroll;roll++){


                cout<<"Would you like to hold dice any dice? Press 'y' for yes or 'n' for no."<<endl;
                cin>>hold;
                    if(hold=='y' || hold== 'Y'){
                    //Hold/Roll function 
                    hldRoll(die1,die2,die3,die4,die5);

                    }else{
                        cout<<"Do you want to roll again? Type 'y' for yes or 'n' for no and to score your dice."<<endl;
                        cin>>rollAgn;       //Input option for roll again
                            if(rollAgn=='y'){   //If yes, roll again
                                rollDice(die1,die2,die3,die4,die5,minval,maxval);//Roll by roll dice function
                            }else if(rollAgn=='n'){
                                prtCard();  //Print scoring card if choosing to score
                                cout<<"Do you want to score the upper or lower section? Choose 'u' for upper, 'l' for lower."<<endl;
                                cin>>chosScr;       //Enter option to score upper section or lower section
                                if(chosScr=='u'){
                                   scrUppr(die1,die2,die3,die4,die5,totscore);
                                   break;       //Break out of loop to reset rolls
                                }else if(chosScr=='l'){
                                    scrLower(die1,die2,die3,die4,die5,totscore);
                                    break;      //Break out of loop to reset rolls
                                }
                            }
                    }
            }           
        //When all rolls used, prompt for score input
            if(roll==maxroll){
                    prtCard();
                    cout<<"Do you want to score the upper or lower section? Choose 'u' for upper, 'l' for lower."<<endl;
                    cin>>chosScr;
                        if(chosScr=='u'){
                            scrUppr(die1,die2,die3,die4,die5,totscore);
                        }else if(chosScr=='l'){
                            scrLower(die1,die2,die3,die4,die5,totscore);
                        }
            }
            nRound++;    //Increment number of rolls
        }while(nRound<totRnd);
    
    }else{                     //If no enter game, exit
        cout<<"Goodbye!"<<endl;
    }
 
   //Output to file
   outFile<<"Total score:"<<endl;
   outFile<<totscore<<endl;
   
   inFile>>totscore;
   cout<<"Your total score = "<<totscore<<endl;
   
   outFile.close();
    return 0;
}
void prtCard(){
    cout<<"UPPER SECTION"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1."<<setw(15)<<" aces "<<endl;
    cout<<"2."<<setw(15)<<" twos "<<endl;
    cout<<"3."<<setw(15)<<" threes "<<endl;
    cout<<"4."<<setw(15)<<" fours "<<endl;
    cout<<"5."<<setw(15)<<" fives "<<endl;
    cout<<"6."<<setw(15)<<" sixes "<<endl;
    cout<<endl;
    cout<<"LOWER SECTION"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1."<<setw(15)<<" 3 of a kind "<<endl;
    cout<<"2."<<setw(15)<<" 4 of a kind "<<endl;
    cout<<"3."<<setw(15)<<" Full House "<<endl;
    cout<<"4."<<setw(15)<<" Small Straight "<<endl;
    cout<<"5."<<setw(15)<<" Large Straight "<<endl;
    cout<<"6."<<setw(15)<<" Yahtzee "<<endl;
    cout<<"7."<<setw(15)<<" Chance "<<endl;
    cout<<"---------------------------------"<<endl;
    
}
/***********************************************************************
                Check 3 kind valid
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Ouput:
 *      warning if not valid

 * **********************************************************************
 ***********************************************************************/
int check3k(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
 //Declare variables
    unsigned short i;                           //Die number index
    unsigned short value;                       //Value of die
    unsigned short match=0;                       //Total of value matches
    unsigned short maxdie=5;                      //Maximum number of dice
    unsigned short select;
    unsigned short newdie;
    unsigned short three=3;

    
            cout<<"Enter one die to score for 3 of a kind"<<endl;
            cin>>select;
            
            if(select==1){              //Select value to check matches
                value=die1;
            }else if(select==2){
                value=die2;
            }else if(select==3){
                value=die3;
            }else if(select==4){
                value=die4;
            }else if(select==5){
                value=die5;
            }
            
            for(i=1;i<=maxdie;i++){ 
                
                if(i==1){               //Assign value to die index
                    newdie=die1;
                }else if(i==2){
                    newdie=die2;
                }else if(i==3){
                    newdie=die3;
                }else if(i==4){
                    newdie=die4;
                }else if(i==5){
                    newdie=die5;
                }
                if(newdie==value){      //If new die has the same value as the selected value, increment match counter
                    match+=1;
                   if(i==select){       //If the die index is the same as the die you selected, do no count this as a match
                    match-=1;
                    }
                }
            }
            //Score 3 of a kind
            if(match==2){
                return value*three;             //Return score if sufficient number of matches is found
            }else if(match<2){
                cout<<"You do no have enough dice of this value to score three of a kind. Rolling again since you do not follow directions!"<<endl;
                return 0;
            }
    }
    
 
/***********************************************************************
                        Score Lower Section
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five

 * **********************************************************************
 ***********************************************************************/
void scrLower(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5,unsigned short &totscore){
       //Declare variables
    unsigned short choice;          //Which section to score

    
    //Display menu
    cout<<"Input corresponding number for section you wish to score"<<endl;
    cout<<"1."<<"Score 3 of a Kind"<<endl;
    cout<<"2."<<"Score 4 of a Kind"<<endl;
    cout<<"3."<<"Score Full House"<<endl;
    cout<<"4."<<"Score Small Straight"<<endl;
    cout<<"5."<<"Score Large Straight"<<endl;
    cout<<"6."<<"Score Yahtzee"<<endl;
    cout<<"7."<<"Score Chance"<<endl;
    
    cin>>choice;        //Input choice
    switch(choice){
            
            case 1:    //Score 3 of a kind
                totscore+=check3k(die1,die2,die3,die4,die5);
                 break;
            case 2:   //Score 4 of a kind 
                //Check function
                break;
            case 3:         //Score Full House
                //Check function
                break;
            case 4:         //Score small straight
                break;
            case 5:         //score lrg. straight
                //Check function
                break;
            case 6:             //Score yahtzee
                //Check function
                break;
            case 7:             //Score chance
                //Check function       
                break;
        }
    cout<<"Total score = "<<totscore<<endl;

}

/***********************************************************************
                            Score Six
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Output:
 *      score->Score of threes
 * **********************************************************************
 ***********************************************************************/
int scrSix(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    bool six1=false;            //Die one is a six
    bool six2=false;            //Die two is a six
    bool six3=false;            //Die three is a six
    bool six4=false;            //Die four is a six
    bool six5=false;            //Die five is a six
    unsigned int i=0;           //Score index
    unsigned int sixscre;         //Total score
    unsigned int six=6;

    
    if(die1==6){
       six1=true;              //Set to true if die is a six
        i++;
    }
    if(die2==6){
       six2=true;
        i++;
    }
    if(die3==6){
       six3=true;
        i++;
    }
    if(die4==6){
       six4=true;
        i++;
    }
    if(die5==6){
        six5=true;
        i++;
    }
   sixscre=i*six;                    //Total score
    cout<<"The six score is = "<<sixscre<<endl;
    cout<<endl;
    
    return i*six;
}
/***********************************************************************
                            Score Five
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Output:
 *      score->Score of threes
 * **********************************************************************
 ***********************************************************************/
int scrFive(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    bool five1=false;            //Die one is a five
    bool five2=false;            //Die two is a five
    bool five3=false;            //Die three is a five
    bool five4=false;            //Die four is a five
    bool five5=false;            //Die five is a five
    unsigned int i=0;           //Score index
    unsigned int fivescre;         //Total score
    unsigned int five=5;
   
    if(die1==5){
       five1=true;              //Set to true if die is a five
        i++;
    }
    if(die2==5){
       five2=true;
        i++;
    }
    if(die3==5){
       five3=true;
        i++;
    }
    if(die4==5){
        five4=true;
        i++;
    }
    if(die5==5){
        five5=true;
        i++;
    }
   fivescre=i*five;                    //Total score
    cout<<"The five score is = "<<fivescre<<endl;
    cout<<endl;
   
    return fivescre;
}

/***********************************************************************
                            Score Four
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Output:
 *      score->Score of threes
 * **********************************************************************
 ***********************************************************************/
int scrFour(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    bool four1=false;            //Die one is a four
    bool four2=false;            //Die two is a four
    bool four3=false;            //Die three is a four
    bool four4=false;            //Die four is a four
    bool four5=false;            //Die five is a four
    unsigned int i=0;           //Score index
    unsigned int fourscre;         //Total score
    unsigned int four=4;
    
    if(die1==4){
       four1=true;              //Set to true if die is a four
        i++;
    }
    if(die2==4){
        four2=true;
        i++;
    }
    if(die3==4){
       four3=true;
        i++;
    }
    if(die4==4){
        four4=true;
        i++;
    }
    if(die5==4){
        four5=true;
        i++;
    }
   fourscre=i*four;                    //Total score
    cout<<"The four score is = "<<fourscre<<endl;
    cout<<endl;
    return fourscre;
}

/***********************************************************************
                            Score Threes
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Output:
 *      score->Score of threes
 * **********************************************************************
 ***********************************************************************/
int scrThr(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    bool three1=false;            //Die one is a three
    bool three2=false;            //Die two is a three
    bool three3=false;            //Die three is a three
    bool three4=false;            //Die four is a three
    bool three5=false;            //Die five is a three
    unsigned int i=0;             //Score index
    unsigned int threescre;         //Total score
    unsigned int three=3;

    if(die1==3){
        three1=true;              //Set to true if die is an ace
        i++;
    }
    if(die2==3){
        three2=true;
        i++;
    }
    if(die3==3){
        three3=true;
        i++;
    }
    if(die4==3){
        three4=true;
        i++;
    }
    if(die5==3){
        three5=true;
        i++;
    }
   threescre=i*three;                    //Total score
    cout<<"The three score is = "<<threescre<<endl;
    cout<<endl;

     return threescre;
}

/***********************************************************************
                            Score Twos
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Output:
 *      score->Score of twos
 * **********************************************************************
 ***********************************************************************/
int scrTwo(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    bool two1=false;            //Die one is a two
    bool two2=false;            //Die two is a two
    bool two3=false;            //Die three is a two
    bool two4=false;            //Die four is a two
    bool two5=false;            //Die five is a two
    unsigned int i=0;           //Score index
    unsigned int twoscre;         //Total score
    unsigned int two=2;

    if(die1==2){
        two1=true;              //Set to true if die is an ace
        i++;
    }
    if(die2==2){
        two2=true;
        i++;
    }
    if(die3==2){
        two3=true;
        i++;
    }
    if(die4==2){
        two4=true;
        i++;
    }
    if(die5==2){
        two5=true;
        i++;
    }
    twoscre=i*two;                    //Total score
    cout<<"The two score is = "<<twoscre<<endl;
    cout<<endl;
    return twoscre;
}

/***********************************************************************
                            Score Aces
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Output:
 *      score->Score of aces
 * **********************************************************************
 ***********************************************************************/
int scrAce(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    bool ace1=false;            //Die one is an ace
    bool ace2=false;            //Die two is an ace
    bool ace3=false;            //Die three is an ace
    bool ace4=false;            //Die four is an ace
    bool ace5=false;            //Die five is an ace
    unsigned int i=0;           //Score index
    unsigned int acescre;         //Total score
    
        if(die1==1){
            ace1=true;              //Set to true if die is an ace
            i++;
        }
        if(die2==1){
            ace2=true;
            i++;
        }
        if(die3==1){
            ace3=true;
            i++;
        }
        if(die4==1){
            ace4=true;
            i++;
        }
        if(die5==1){
            ace5=true;
            i++;
        }
        acescre=i;                    //Total score
        cout<<"The ace score is = "<<acescre<<endl;

    return acescre;
}

/***********************************************************************
                            Roll Dice
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 *      minval->Minimum value of dice
 *      maxval->Maximum value of dice
 * Output:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five    
 * **********************************************************************
 ***********************************************************************/
void rollDice(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5,unsigned short minval,unsigned short maxval){
                //Set random number for dice
            die1= (rand() % (maxval-minval+1))+minval;
            die2= (rand() % (maxval-minval+1))+minval;
            die3= (rand() % (maxval-minval+1))+minval;
            die4= (rand() % (maxval-minval+1))+minval;
            die5= (rand() % (maxval-minval+1))+minval;
            
            //Output value of dice
            cout<<"Die 1 = "<<die1<<endl;
            cout<<"Die 2 = "<<die2<<endl;
            cout<<"Die 3 = "<<die3<<endl;
            cout<<"Die 4 = "<<die4<<endl;
            cout<<"Die 5 = "<<die5<<endl;
            cout<<endl;
}
/***********************************************************************
                        Score Upper Section 
 * *********************************************************************
 * Input:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * Output:
 *      totscore->Total score
 * **********************************************************************
 ***********************************************************************/
void scrUppr(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5,unsigned short &totscore){
    //Declare variables
    unsigned short choice;          //Which section to score
    int score1;                 //Ace score            
    int score2;                 //Two score
    int score3;                 //Three score
    int score4;                 //Four score
    int score5;                 //Five score
    int score6;                 //Six score

    //Display menu
    cout<<"Input corresponding number for section you wish to score"<<endl;
    cout<<"1."<<"Score aces"<<endl;
    cout<<"2."<<"Score twos"<<endl;
    cout<<"3."<<"Score threes"<<endl;
    cout<<"4."<<"Score fours"<<endl;
    cout<<"5."<<"Score fives"<<endl;
    cout<<"6."<<"Score sixes"<<endl;
    cin>>choice;        //Input choice
        switch(choice){
            case 1:    //Score aces
                score1=scrAce(die1,die2,die3,die4,die5);
                totscore+=score1;
                 break;
            case 2:         //Score twos
                score2=scrTwo(die1,die2,die3,die4,die5);
                totscore+=score2;
                break;
            case 3:         //Score threes
                score3=scrThr(die1,die2,die3,die4,die5);
                totscore+=score3;
                break;
            case 4:         //Score fours
                score4=scrFour(die1,die2,die3,die4,die5);
                totscore+=score4;
                break;
            case 5:         //Score fives
                score5=scrFive(die1,die2,die3,die4,die5);
                totscore+=score5;
                break;
            case 6:         //SCore sixes
                score6=scrSix(die1,die2,die3,die4,die5);
                totscore+=score6;
                break;
        }

}

/***********************************************************************
                 Roll One Die
 * *********************************************************************
 * Input:
 *      hold1->value of held die
 *      hold2->Value of held die
 *      hold3->Value of held die
 *      hold4->Value of held die
 *      minval ->Minimum value die can have
 *      maxval-> Maximum value die can have
 * Input-Output:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * **********************************************************************
 ***********************************************************************/
void roll1(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    unsigned short maxval=6;        //Maximum die value
    unsigned short minval=1;
    unsigned short select1;         //Value of first held die
    unsigned short select2;         //Value of second held die
    unsigned short select3;         //Value of third held die
    unsigned short select4;         //Value of fourth held die
    unsigned short hold1;           
    unsigned short hold2;
    unsigned short hold3;
    unsigned short hold4;
    unsigned short maxdice=5;
    //Seed random number generator
    srand(time(0));
    //Output prompt for dice to hold
            cout<<"Select number of die/dice you want to hold"<<endl;
            cin>>select1>>select2>>select3;
            switch(select1){
                case 1:
                     hold1=select1;break;
                case 2:
                    hold1=select1;break;
                case 3:
                    hold1=select1;break;
                case 4:
                    hold1=select1;break;
                case 5:
                    hold1=select1;break;
            }
            switch(select2){
                case 1:
                     hold2=select2;break;
                case 2:
                    hold2=select2;break;
                case 3:
                    hold2=select2;break;
                case 4:
                    hold2=select2;break;
                case 5:
                    hold2=select2;break;
            }
            switch(select3){
                case 1:
                     hold3=select3;break;
                case 2:
                    hold3=select3;break;
                case 3:
                    hold3=select3;break;
                case 4:
                    hold3=select3;break;
                case 5:
                    hold3=select3;break;
            }
            switch(select4){
                case 1:
                     hold4=select4;break;
                case 2:
                    hold4=select4;break;
                case 3:
                    hold4=select4;break;
                case 4:
                    hold4=select4;break;
                case 5:
                    hold4=select4;break;
            }
            for(int i=1;i<=maxdice;i++){//Loop for all dice
                if(i==hold1 || i==hold2 || i==hold3 || i==hold4){
                   //Nothing if die index is equal to held die
                }else{
                    if(i==1){
                        die1=(rand() % (maxval-minval+1))+minval;
                    }else if(i==2){
                        die2= (rand() % (maxval-minval+1))+minval;
                    }else if(i==3){
                        die3= (rand() % (maxval-minval+1))+minval;
                    }else if(i==4){
                        die5= (rand() % (maxval-minval+1))+minval;
                    }else if(i==5){
                        die5= (rand() % (maxval-minval+1))+minval;
                    } 
                }
            }
                      //Output value of dice
            cout<<"Die 1 = "<<die1<<endl;
            cout<<"Die 2 = "<<die2<<endl;
            cout<<"Die 3 = "<<die3<<endl;
            cout<<"Die 4 = "<<die4<<endl;
            cout<<"Die 5 = "<<die5<<endl;
            cout<<endl;
}


/***********************************************************************
                            Roll Two Dice
 * *********************************************************************
 * Input:
 *      hold1->value of held die
 *      hold2->Value of held die
 *      hold3->Value of held die
 * Input-Output:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * **********************************************************************
 ***********************************************************************/
void roll2(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,
    unsigned short &die5){
    //Declare variables
    unsigned short maxval=6;
    unsigned short minval=1;
    unsigned short select1;
    unsigned short select2;
    unsigned short select3;
    unsigned short hold1;
    unsigned short hold2;
    unsigned short hold3;
    unsigned short maxdice=5;
    srand(time(0));
            cout<<"Select number of die/dice you want to hold"<<endl;
            cin>>select1>>select2>>select3;     
            switch(select1){
                case 1:
                     hold1=select1;break;
                case 2:
                    hold1=select1;break;
                case 3:
                    hold1=select1;break;
                case 4:
                    hold1=select1;break;
                case 5:
                    hold1=select1;break;
            }
            switch(select2){
                case 1:
                     hold2=select2;break;
                case 2:
                    hold2=select2;break;
                case 3:
                    hold2=select2;break;
                case 4:
                    hold2=select2;break;
                case 5:
                    hold2=select2;break;
            }
            switch(select3){
                case 1:
                     hold3=select3;break;
                case 2:
                    hold3=select3;break;
                case 3:
                    hold3=select3;break;
                case 4:
                    hold3=select3;break;
                case 5:
                    hold3=select3;break;
            }
            for(int i=1;i<=maxdice;i++){
                if(i==hold1 || i==hold2 || i==hold3){    
                    //Do not roll if die is equal to held die
                }else{
                    if(i==1){
                        die1=(rand() % (maxval-minval+1))+minval;
                    }else if(i==2){
                        die2= (rand() % (maxval-minval+1))+minval;
                    }else if(i==3){
                        die3= (rand() % (maxval-minval+1))+minval;
                    }else if(i==4){
                        die5= (rand() % (maxval-minval+1))+minval;
                    }else if(i==5){
                        die5= (rand() % (maxval-minval+1))+minval;
                    } 
                }
            }
                      //Output value of dice
            cout<<"Die 1 = "<<die1<<endl;
            cout<<"Die 2 = "<<die2<<endl;
            cout<<"Die 3 = "<<die3<<endl;
            cout<<"Die 4 = "<<die4<<endl;
            cout<<"Die 5 = "<<die5<<endl;
            cout<<endl;  
    
}

/***********************************************************************
                            Roll Three Dice
 * *********************************************************************
 * Input:
 *      hold1->value of held die
 *      hold2->Value of held die
 * Input-Output:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * **********************************************************************
 ***********************************************************************/
void roll3(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    unsigned short maxval=6;
    unsigned short minval=1;
    unsigned short select1;
    unsigned short select2;
    unsigned short hold1;
    unsigned short hold2;
    unsigned short maxdice=5;
    
    srand(time(0));
            cout<<"Select number of die/dice you want to hold"<<endl;
            cin>>select1>>select2;
            switch(select1){
                case 1:
                     hold1=select1;break;
                case 2:
                    hold1=select1;break;
                case 3:
                    hold1=select1;break;
                case 4:
                    hold1=select1;break;
                case 5:
                    hold1=select1;break;
            }
            switch(select2){
                case 1:
                     hold2=select2;break;
                case 2:
                    hold2=select2;break;
                case 3:
                    hold2=select2;break;
                case 4:
                    hold2=select2;break;
                case 5:
                    hold2=select2;break;
            }
            for(int i=1;i<=maxdice;i++){
                
                if(i==hold1 || i==hold2){
              
                }else{
                    if(i==1){
                        die1=(rand() % (maxval-minval+1))+minval;
                    }else if(i==2){
                        die2= (rand() % (maxval-minval+1))+minval;
                    }else if(i==3){
                        die3= (rand() % (maxval-minval+1))+minval;
                    }else if(i==4){
                        die5= (rand() % (maxval-minval+1))+minval;
                    }else if(i==5){
                        die5= (rand() % (maxval-minval+1))+minval;
                    } 
                }
            }
                      //Output value of dice
            cout<<"Die 1 = "<<die1<<endl;
            cout<<"Die 2 = "<<die2<<endl;
            cout<<"Die 3 = "<<die3<<endl;
            cout<<"Die 4 = "<<die4<<endl;
            cout<<"Die 5 = "<<die5<<endl;
            cout<<endl;  
}

/***********************************************************************
                            Roll Four Dice
 * *********************************************************************
 * Input:
 *      hold1->value of held die
 * Input-Output:
 *      die1-> Value of die one
 *      die2-> Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * **********************************************************************
 ***********************************************************************/
void roll4(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    unsigned short minval=1;
    unsigned short maxval=6;
    unsigned short hold1;
    unsigned short maxdice=5;
    srand(time(0));
            cout<<"Select number of die/dice you want to hold"<<endl;
            cin>>hold1;
            
            switch(hold1){
                case 1:
                     hold1=hold1;break;
                case 2:
                    hold1=hold1;break;
                case 3:
                    hold1=hold1;break;
                case 4:
                    hold1=hold1;break;
                case 5:
                    hold1=hold1;break;
            }
            for(int i=1;i<=maxdice;i++){
                
                if(i==hold1){
                    
                }else{
                    if(i==1){
                        die1=(rand() % (maxval-minval+1))+minval;
                    }else if(i==2){
                        die2= (rand() % (maxval-minval+1))+minval;
                    }else if(i==3){
                        die3= (rand() % (maxval-minval+1))+minval;
                    }else if(i==4){
                        die5= (rand() % (maxval-minval+1))+minval;
                    }else if(i==5){
                        die5= (rand() % (maxval-minval+1))+minval;
                    } 
                }
            }
            //Output value of dice
            cout<<"Die 1 = "<<die1<<endl;
            cout<<"Die 2 = "<<die2<<endl;
            cout<<"Die 3 = "<<die3<<endl;
            cout<<"Die 4 = "<<die4<<endl;
            cout<<"Die 5 = "<<die5<<endl;
            cout<<endl;  
}

/***********************************************************************
                                Hold
 * *********************************************************************
 * Input:
 *      die1->Value of die one
 *      die2->Value of die two
 *      die3->Value of die three
 *      die4->Value of die four
 *      die5->Value of die five
 * 
 * **********************************************************************
 ***********************************************************************/

void hldRoll(unsigned short &die1,unsigned short &die2,unsigned short &die3,unsigned short &die4,unsigned short &die5){
    //Declare variables
    unsigned short howmny;          //How many die to hold
     //Find out how many dice to hold
    cout<<"How many dice would you like to hold?"<<endl;
    cin>>howmny;
    
    switch(howmny){
        case 1:     //Hold 1 die
            
           roll4(die1,die2,die3,die4,die5);
            break;
            
        case 2:     //Hold 2 die
            roll3(die1,die2,die3,die4,die5);
            break;
        case 3:         //Hold 3 die

            roll2(die1,die2,die3,die4,die5);
            break;
            
        case 4:         //Hold four die

            roll1(die1,die2,die3,die4,die5);
            break;
    }

}

