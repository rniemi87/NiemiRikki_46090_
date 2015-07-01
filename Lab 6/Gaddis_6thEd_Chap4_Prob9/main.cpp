    /* 
     * File:   main.cpp
     * Author: Rikki Niemi
     * Purpose: How many candy bars can I eat per day w/o gaining wieght
     * Created on June 30, 2015, 12:18 PM
     */
     
    //System Libraries\
    

    #include <iostream>
    #include <ctime>
    #include <iomanip>
    #include <cstdlib>

     
    using namespace std;
     
    /*//User Libraries
     * 
     * //Global Constants
     * 
     * //Function Prototypes
     * 
     * //Execution Starts Here!
     * 
     */
    int main(int argc, char** argv) {
     
       //Set Random seed
        srand(static_cast<unsigned int>(time(0)));
        //Declare variables
        unsigned short op1, op2, result, answer;
        bool doAgain;
        char op;
     
        //Loop based upon continuting to play with the math tutor
        do{
            //Determine op1/op2
            op1=rand()%900+100; //[100-999]
            op2=rand()%900+100; //[100-999]
            op=rand()%5;
            
            //Display the problem
            cout<<setw(6)<<op1<<endl;
            switch(op){
                case 1 :{
                    cout<<" + "<<op2<<endl;
                    answer=op1+op2;
                    break;
                case 2:{
                        cout<<" - "<<op2<<endl;
                        answer=op1-op2;
                        break;
                case 3:{
                        cout<<" / "<<op2<<endl;
                        answer=op1/op2;
                        break;
                case 4:{
                        cout<<" % "<<op2<<endl;
                        answer=op1/op2;
                        break;
                    }
             
                        }
                    }
                    
                }
            }
            
            cout<<"------"<<endl;
            //Input value for sum
            cin>>result;
            //If correct, output congratulations else try again?
            if(result==op1+op2){
                cout<<"Congratulations"<<endl;
            }
            else{
                cout<<"Wrong Answer"<<endl;
                cout<<"The answer is "<<op1+op2<<endl;
            }
            //Prompt if to continue
            cout<<"Would you like to continue? y/n"<<endl;
            char response;
            cin>>response;
            if(response=='y')doAgain=true;
            else doAgain=false;
            
            
            
        }while(doAgain);
     
        return 0;
    }