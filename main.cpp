#include<iostream>
#include<cstdlib>
#include <time.h>

using namespace std;

int numberOfTries = 10000000;
int RPSWin=0 , RPSTie=0;
int RPSLSWin=0 , RPSLSTie=0;

bool RPSRules(int C1,int C2)
{
    /* 1 Rock
     * 2 Paper
     * 3 Scissors
     *
     * Scissors cuts Paper
     * Paper covers Rock
     * Rock crushes Scissors
     */

     if( (C1 == 3 && C2 == 2) || (C1 == 2 && C2 == 1) || (C1 == 1 && C2 == 3) )
        return true;
     else
        return false;
}

bool RPSLSRules(int C1,int C2)
{
   /* 1 Rock
    * 2 Paper
    * 3 Scissors
    * 4 Lizard
    * 5 Spock
    *
    *Scissors cuts Paper
    *Paper covers Rock
    *Rock crushes Lizard
    *Lizard poisons Spock
    *Spock smashes Scissors
    *Scissors decapitates Lizard
    *Lizard eats Paper
    *Paper disproves Spock
    *Spock vaporizes Rock
    *Rock crushes Scissors
    */

     if( (C1 == 3 && C2 == 2) ||
         (C1 == 2 && C2 == 1) ||
         (C1 == 1 && C2 == 4) ||
         (C1 == 4 && C2 == 5) ||
         (C1 == 5 && C2 == 3) ||
         (C1 == 3 && C2 == 4) ||
         (C1 == 4 && C2 == 2) ||
         (C1 == 2 && C2 == 5) ||
         (C1 == 5 && C2 == 1) ||
         (C1 == 1 && C2 == 3) )
        return true;
     else
        return false;
}

void RPSTesting()
{
    for(int i=0 ; i<=numberOfTries ; i++)
    {
        int C1 = 1 + rand() % 3;
        int C2 = 1 + rand() % 3;
        if(C1 == C2)
            RPSTie++;
        else
            if(RPSRules(C1,C2))
                RPSWin++;
    }
}

void RPSLSTesting()
{
    for(int i=0 ; i<=numberOfTries ; i++)
    {
        int C1 = 1 + rand() % 5;
        int C2 = 1 + rand() % 5;
        if(C1 == C2)
            RPSLSTie++;
        else
            if(RPSLSRules(C1,C2))
                RPSLSWin++;
    }
}

int main()
{
    srand (time(NULL));

    RPSTesting();
    RPSLSTesting();

    cout<<"Rock - Paper - Scissors "<<endl;
    cout<<"Wins: "<<RPSWin<<" Loses: "<<numberOfTries - (RPSWin+RPSTie)<<" Ties: "<<RPSTie<<endl<<endl;

    cout<<"Rock - Paper - Scissors - Lizard - Spock"<<endl;
    cout<<"Wins: "<<RPSLSWin<<" Loses: "<<numberOfTries - (RPSLSWin+RPSLSTie)<<" Ties: "<<RPSLSTie<<endl;

    return 0;
}
