#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess(int n,int l)
{
    int num,guess,attempts=0;

    srand(time(NULL));
    num=rand()%n;// Generating a random number.

    printf("Guess a number between 1 and %d:  ",n);

    do
    {
        if(attempts>l)//End the game if user exceeds the limit of attempts.
        {
            printf("\nToo many attempts. You lose.\nThe number is %d.\n",num);
            break;
        }
        scanf("%d",&guess);//Take user's guess.
        //Comparing the guess and actual number.
        if(guess>num)
        {
            printf("\nYour guess is higher than the number. Try again.\n");
            attempts++;
        }
        else if(guess<num)
        {
            printf("\nYour guess is lower than the number. Try again.\n");
            attempts++;
        }
        else
        {
            printf("\nYou guessed the number in %d attempts",attempts);
        }
    }while(guess!=num);
}

int main()
{
    printf("Enter the last possible number: ");
    int n,l;
    scanf("%d",&n);//Get the maximum number in the range.
    printf("Enter the limit on number of attempts: ");
    scanf("%d",&l);//Get the limit of number of guesses.
    guess(n,l);//Starting the number guessing with range[1,n] and l attempts.
    return 0;
}