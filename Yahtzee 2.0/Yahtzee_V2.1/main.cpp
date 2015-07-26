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
void hldRoll(int[],unsigned short);
void roll4(int [],unsigned short);
void roll3(int[],unsigned short);
void roll2(int [],unsigned short);
void roll1(int [],unsigned short);
void scrUppr(int [],unsigned short,unsigned short &);
void rollDice(int [],unsigned short,unsigned short ,unsigned short);
int scrAce(int [],unsigned short);
int scrTwo(int [],unsigned short);
int scrThr(int [],unsigned short);
int scrFour(int [],unsigned short);
int scrFive(int [],unsigned short);
int scrSix(int [],unsigned short);
void scrLower(int [],unsigned short,unsigned short &);
int check3k(int [],unsigned short ,unsigned short &);
int check4k(int [],unsigned short ,unsigned short &);
int yahtzee(int [],unsigned short ,unsigned short &);
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
    unsigned int totRnd=3;        //Total number of rounds
    unsigned short totscore=0;
    char rollAgn;               //y/n to roll again
    unsigned short numdice=5;
    int die[numdice];
    
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
        cout<<"Please enlarge terminal screen to maximum height for optimal game play."<<endl;
 
        do{        
            rollDice(die,numdice,minval,maxval);   //Roll dice
            
            for(roll=1;roll<maxroll;roll++){


                cout<<"Would you like to hold dice any dice? Press 'y' for yes or 'n' for no."<<endl;
                cin>>hold;
                    if(hold=='y' || hold== 'Y'){
                    //Hold/Roll function 
                    hldRoll(die,numdice);

                    }else{
                        cout<<"Do you want to roll again? Type 'y' for yes or 'n' for no and to score your dice."<<endl;
                        cin>>rollAgn;       //Input option for roll again
                            if(rollAgn=='y'){   //If yes, roll again
                                rollDice(die,numdice,minval,maxval);//Roll by roll dice function
                            }else if(rollAgn=='n'){
                                prtCard();  //Print scoring card if choosing to score
                                cout<<"Do you want to score the upper or lower section? Choose 'u' for upper, 'l' for lower."<<endl;
                                cin>>chosScr;       //Enter option to score upper section or lower section
                                if(chosScr=='u'){
                                   scrUppr(die,numdice,totscore);
                                   break;       //Break out of loop to reset rolls
                                }else if(chosScr=='l'){
                                    scrLower(die,numdice,totscore);
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
                            scrUppr(die,numdice,totscore);
                        }else if(chosScr=='l'){
                            scrLower(die,numdice,totscore);
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

/***********************************************************************
                Print Score Card
 * *********************************************************************
 * Putpose: 
 *      To output score card to show what options are available on upper
 *      and lower score section
 * Ouput:
 *      Score Card
 * **********************************************************************
 ***********************************************************************/
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
                        Yahtzee
 * *********************************************************************
 * Purpose:
 *          to check for Yahtzee and then, if valid, score the points
 * Input:
 *          die[i]->Array of dice
 *          numdice->number of dice
 * Ouput:
 *      warning if not valid
 * **********************************************************************
 ***********************************************************************/
int yahtzee(int die[],unsigned short numdice,unsigned short &totscore){
     //Declare variables
    unsigned short value;                       //Value of die
    unsigned short match=0;                     //Total of value matches
    unsigned short yscre=50;                    //Score for yahtzee
    
            for(int i=0;i<numdice;i++){
                    value=die[i];
                    if(die[i+1]==value){
                        match+=1;
                    }
            }
            //Score 4 of a kind
            if(match==4){
                return yscre;             //Return score if sufficient number of matches is found
                
            }else{
                cout<<"You do no have enough dice of this value to score a yahtzee. Rolling again since you do not follow directions!"<<endl;
                return 0;
            }
}
/***********************************************************************
                Check 4 kind valid
 * *********************************************************************
 * Purpose:
 *          to check for 4 of a kind and then, if valid, score the points
 * Input:
 *          die[i]->Array of dice
 *          numdice->number of dice
 * Ouput:
 *      warning if not valid
 * **********************************************************************
 ***********************************************************************/
int check4k(int die[],unsigned short numdice,unsigned short &totscore){
     //Declare variables
    unsigned short value;                       //Value of die
    unsigned short match=0;                       //Total of value matches
    unsigned short four=4;
            
            for(int i=0;i<numdice;i++){         //Loop for all dice
                    value=die[i];               //Compare dice for matching values
                    if(die[i+1]==value){        //If there is a match,add to match counter
                        match+=1;
                    }
            }
            //Score 4 of a kind
            if(match>=3){
                return value*four;             //Return score if sufficient number of matches is found
                
            }else if(match<3){
                cout<<"You do no have enough dice of this value to score three of a kind. Rolling again since you do not follow directions!"<<endl;
                return 0;
            }
}
/***********************************************************************
                Check for 3 kind/Score
 * *********************************************************************
 * Purpose:
 *          to check for 3 of a kind and then, if valid, score the points
 * Input:
 *          die[i]->Array of dice
 *          numdice->number of dice
 * Ouput:
 *      warning && roll if not valid
 * **********************************************************************
 ***********************************************************************/
int check3k(int die[],unsigned short numdice,unsigned short &totscore){
 //Declare variables
    unsigned short value;                       //Value of die
    unsigned short match=0;                     //Total of value matches
    unsigned short three=3;

            for(int i=0;i<numdice;i++){         //Loop for all dice
                    value=die[i];               //Set value of die to compare against
                    if(die[i+1]==value){        //Increment match counter if there is a match
                        match+=1;
                    }
            }
            //Score 3 of a kind
            if(match>=2){
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
 *          die[i]->Array of dice
 *          numdice->Number of dice
 *          totscre->total game score
 * **********************************************************************
 ***********************************************************************/
void scrLower(int die[],unsigned short numdice,unsigned short &totscore){
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
                totscore+=check3k(die,numdice,totscore);
                 break;
            case 2:   //Score 4 of a kind 
                totscore+=check4k(die,numdice,totscore);
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
                totscore+=yahtzee(die,numdice,totscore);
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
 *          die[]->Array of dice
 *          numdice->number of dice
 * Output:
 *      score->Score of threes
 * **********************************************************************
 ***********************************************************************/
int scrSix(int die[],unsigned short numdice){
    //Declare variables
    unsigned int sixscre=0;         //Total score

    for(int i=0;i<numdice;i++){     //Loop for all dice
        if(die[i]==6){              //ADd six points for each die with value of six
            sixscre+=6;
        }
    }
    cout<<"The six score is = "<<sixscre<<endl;     //Output total six score
    cout<<endl;
    
    return sixscre;                                 //Return total six score
}
/***********************************************************************
                            Score Five
 * *********************************************************************
 * Input:
 *          die[]->Array of dice
 *          numdice->Number of dice
 * Output:
 *          fivescre->Score of all fives
 * **********************************************************************
 ***********************************************************************/
int scrFive(int die[],unsigned short numdice){
    //Declare variables
    unsigned int fivescre=0;         //Total score

    for(int i=0;i<numdice;i++){     //Loop for all dice
        if(die[i]==5){              //Add five points for each die with a value of five
            fivescre+=5;
        }
    }
    cout<<"The five score is = "<<fivescre<<endl;       //Output total fives score
    cout<<endl;
    return fivescre;        //Return total fives value
}

/***********************************************************************
                            Score Four
 * *********************************************************************
 * Input:
 *      die[]-> Array of dice
 *      numdice->Number of dice
 * Output:
 *      fourscre->Score of fours
 * **********************************************************************
 ***********************************************************************/
int scrFour(int die[],unsigned short numdice){
    //Declare variables
    unsigned int fourscre=0;         //Total score
    
    for(int i=0;i<numdice;i++){     //Loop for all dice
        if(die[i]==4){              //Add four points for each die with value of four
            fourscre+=4;
        }
    }
    cout<<"The four score is = "<<fourscre<<endl;       //Output total fours value
    cout<<endl;
    return fourscre;        //Return total fours score
}

/***********************************************************************
                            Score Threes
 * *********************************************************************
 * Input:
 *          die[]->Array of dice
 *          numdice->Number of dice
 * Output:
 *      threescre->Score of threes
 * **********************************************************************
 ***********************************************************************/
int scrThr(int die[],unsigned short numdice){
    //Declare variables
    unsigned int threescre=0;         //Total score
    for(int i=0;i<numdice;i++){         //Loop for all dice
        if(die[i]==3){                  //Add three points for all die with value fo three
            threescre+=3;
        }
    }
    cout<<"The three score is = "<<threescre<<endl; //Output total three score
    cout<<endl;
     return threescre;      //Return total threes score
}

/***********************************************************************
                            Score Twos
 * *********************************************************************
 * Input:
 *          die[]->Array of dice
 *          numdice->number of dice
 * Output:
 *      twoscre->Score of twos
 * **********************************************************************
 ***********************************************************************/
int scrTwo(int die[],unsigned short numdice){
    //Declare variables
    unsigned int twoscre=0;         //Total score
    for(int i=0;i<numdice;i++){     //Loop for all dice
        if(die[i]==2){              //Add two points for each two die
            twoscre+=2;
        }
    }
    cout<<"The two score is = "<<twoscre<<endl;     //Output two's score
    cout<<endl;
    return twoscre;                                 //Return total twos score
}

/***********************************************************************
                            Score Aces
 * *********************************************************************
 * Input:
 *      die[]->Array of dice
 *      numdice->Number of dice
 * Output:
 *      score->Score of aces
 * **********************************************************************
 ***********************************************************************/
int scrAce(int die[],unsigned short numdice){
    //Declare variables
    unsigned int acescre=0;         //Total score
    for(int i=0;i<numdice;i++){ //Loop for all dice
        if(die[i]==1)           //Add one point for each ace die
            acescre+=1;
    }
        cout<<"The ace score is = "<<acescre<<endl;     //Output ace score

    return acescre;         //Return total ace score
}

/***********************************************************************
                            Roll Dice
 * *********************************************************************
 * Input:
 *      minval->Minimum value of dice
 *      maxval->Maximum value of dice
 * Output:
 *      die[i]->Output value of dice
 * **********************************************************************
 ***********************************************************************/
void rollDice(int die[],unsigned short numdice,unsigned short minval,unsigned short maxval){
    //Set random number for dice
    for(int i=0;i<numdice;i++){
        die[i]=(rand() % (maxval-minval+1))+minval;
        //Output value of dice
        cout<<"Die "<<i+1<<" = "<<die[i]<<endl;
    }
            cout<<endl;
}
/***********************************************************************
                        Score Upper Section 
 * *********************************************************************
 * Input:
 *          die[i]->Array of dice
 *          numdice->Number of dice
 * Output:
 *      totscore->Total score
 * **********************************************************************
 ***********************************************************************/
void scrUppr(int die[],unsigned short numdice,unsigned short &totscore){
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
    cin>>choice;            //Input choice
        switch(choice){
            case 1:         //Score aces
                score1=scrAce(die,numdice);
                totscore+=score1;
                 break;
            case 2:         //Score twos
                score2=scrTwo(die,numdice);
                totscore+=score2;
                break;
            case 3:         //Score threes
                score3=scrThr(die,numdice);
                totscore+=score3;
                break;
            case 4:         //Score fours
                score4=scrFour(die,numdice);
                totscore+=score4;
                break;
            case 5:         //Score fives
               score5=scrFive(die,numdice);
               totscore+=score5;
                break;
            case 6:         //SCore sixes
               score6=scrSix(die,numdice);
               totscore+=score6;
                break;
        }

}

/***********************************************************************
                 Roll One Die
 * *********************************************************************
 * Input:
 *      select1->value of held die
 *      select2->Value of held die
 *      select3->Value of held die
 *      select4->Value of held die
 *      minval ->Minimum value die can have
 *      maxval-> Maximum value die can have
 *Output:
 *      die[i]-> Value of die
 * **********************************************************************
 ***********************************************************************/
void roll1(int die[],unsigned short numdice){
    //Declare variables
    unsigned short maxval=6;        //Maximum die value
    unsigned short minval=1;
    unsigned short select1;         //Value of first held die
    unsigned short select2;         //Value of second held die
    unsigned short select3;         //Value of third held die
    unsigned short select4;         //Value of fourth held die
    
    //Seed random number generator
    srand(time(0));
    //Output prompt for dice to hold
    
            cout<<"Select number of die/dice you want to hold"<<endl;
            cin>>select1>>select2>>select3>>select4;        //Input dice to hold

            for(int i=0;i<numdice;i++){//Loop for all dice
                if(i==select1-1 || i==select2-1 || i==select3-1 || i==select4-1){
                   //Nothing if die index is equal to held die
                }else{
                        die[i]=(rand() % (maxval-minval+1))+minval;
                }
            cout<<"Die "<<i+1<<" = "<<die[i]<<endl;         //Output new dice value
            }
}

/***********************************************************************
                            Roll Two Dice
 * *********************************************************************
 * Input:
 *      select1->value of held die
 *      hold2->Value of held die
 *      hold3->Value of held die
 *Output:
 *      die[i]-> Value of die
 * **********************************************************************
 ***********************************************************************/
void roll2(int die[],unsigned short numdice){
    //Declare variables
    unsigned short maxval=6;        //Maximum value of die
    unsigned short minval=1;        //Minimum value of die
    unsigned short select1;         //First hold selection
    unsigned short select2;         //Second hold selection
    unsigned short select3;         //Third hold selection

    //Seed random number generator
    srand(time(0));
            cout<<"Select number of die/dice you want to hold"<<endl;
            cin>>select1>>select2>>select3;                             //Input dice to hold

            for(int i=0;i<numdice;i++){
                if(i==select1-1 || i==select2-1 || i==select3-1){    
                    //Do not roll if die is equal to held die
                }else{
                      die[i]=(rand() % (maxval-minval+1))+minval;       //Assign new value to die that isn't held
                    }
                                      //Output value of dice            //Output new dice value
            cout<<"Die "<<i+1<<" = "<<die[i]<<endl;
                }
}

/***********************************************************************
                            Roll Three Dice
 * *********************************************************************
 * Input:
 *      die[]->Array of dice
 *      numdice->number of dice
 *      hold1->value of held die
 *      hold2->Value of held die
 * Output:
 *      die[i]->Value of die
 * **********************************************************************
 ***********************************************************************/
void roll3(int die[],unsigned short numdice){
    //Declare variables
    unsigned short maxval=6;    //Minimum value of die
    unsigned short minval=1;    //Maximum value of die
    unsigned short select1;     //First hold selection
    unsigned short select2;     //Second hold selection
    //Seed random number generator
    srand(time(0));
            cout<<"Select number of die/dice you want to hold"<<endl;
            cin>>select1>>select2;
            
            for(int i=0;i<numdice;i++){
                
                if(i==select1-1 || i==select2-1){       //Skip for held dice
              
                }else{
                        die[i]=(rand() % (maxval-minval+1))+minval;     //Reassign new value to die
                }
            }  
            //Output value of dice
            for(int i=0;i<numdice;i++){
            cout<<" Die "<<i+1<<" = "<<die[i];
            cout<<endl;
            }
}

/***********************************************************************
                            Roll Four Dice
 * *********************************************************************
 * Input:
 *      hold1->value of held die
 *      numdice-> number of dice
 * Output:
 *      die[]->Array of dice
 * **********************************************************************
 ***********************************************************************/
void roll4(int die[],unsigned short numdice){
    //Declare variables
    unsigned short minval=1;
    unsigned short maxval=6;
    unsigned short hold1;
    
    //Seed random number generator
    srand(time(0));
            cout<<"Select number of die/dice you want to hold"<<endl;
            cin>>hold1;     //Input die to hold

            for(int i=0;i<numdice;i++){
                
                if(i==hold1-1){             //Skip if i=hold
                    
                }else{
                    die[i]=(rand() % (maxval-minval+1))+minval;     //Reassign new value to die not held
                }
            }
            //Output value of dice
            
            for(int i=0;i<numdice;i++){
            cout<<"Die "<<i+1<<" = "<<die[i]<<endl;
            }
}

/***********************************************************************
                                Hold
 * *********************************************************************
 * Input:
 *      die[]->Array of dice
 *      numdice-> number of dice
 * 
 * **********************************************************************
 ***********************************************************************/

void hldRoll(int die[],unsigned short numdice){
    //Declare variables
    unsigned short howmny;          //How many die to hold
     //Find out how many dice to hold
    cout<<"How many dice would you like to hold?"<<endl;
    cin>>howmny;
    
    switch(howmny){
        case 1:     //Hold 1 die
           roll4(die,numdice);
            break;
        case 2:     //Hold 2 die
            roll3(die,numdice);
            break;
        case 3:         //Hold 3 die
           roll2(die,numdice);
            break;
        case 4:         //Hold four die
           roll1(die,numdice);
            break;
    }

}

