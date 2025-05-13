#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Return values 
//0 - tie
//1 - user wins
//-1- user loses
int game(char user,char computer)
{
    if(user==computer)//Condition for a tie.
        return 0;
    if(user=='r')//To check all winning conditions.
        if(computer=='s')
            return 1;
    if(user=='p')
        if(computer=='r')
            return 1;
    if(user=='s')
        if(computer=='p')
            return 1;
    return -1;//Returns if user loses.        
}

int main()
{
    int n;
    char user,computer,result;

    srand(time(NULL));
    n=rand()%99;//Choosing a random number.

    //Assigning computer's choice by the random number.
    if(n<=33)
        computer='r';
    else if(34<=n<=66)
        computer='p';
    else
        computer='s';
            
    printf("Enter r for ROCK, p for PAPER, s for SCISSORS: ");
    scanf(" %c", &user);//Taking user's choice as input.
    
    result=game(user,computer);

    //To display result.
    if(result==0)
        printf("Tie!!!");
    else if(result==1)
        printf("You win!!!");
    else
        printf("You lose...");

    //Showing choices made by both.
    printf("\n\nYou chose: %c\nComputer chose: %c",user,computer);

    return 0;
}