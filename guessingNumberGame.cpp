#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main(){
    while(true){
    cout<<"\nWelcome to random number generator!!"<<endl;
    cout<<"The system has generated a random number between 1 and 20, u have to guess that number.\n";
    int random;
    srand(time(0));
    random = 1+(rand()%20);
    while(true){
        cout<<"\nType your guess : \n";
        int guess;
        cin>>guess;
        if(guess==random){
        cout<<"\nCorrect answer!!!"<<endl;
        break;
        }
        else if(guess>=random){
            cout<<"Wrong answer, try a smaller number : "<<endl;
            continue;
        }
        else{
            cout<<"Wrong answer, try a greater number : "<<endl;
            continue;
        }
    }
    cout<<"\nEnter 1 to play again, enter any other character to exit."<<endl;
    int flag;
    cin>>flag;
    if(flag!=1){
        cout<<"\nThanks for playing!!\n\n";
        break;
    }
    else{
        continue;
    }
}
    return 0;
}
