#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

struct Word//Defining a structure to store the words.
{
    char word[20];
};

void display(const char word[],bool guessed[])//Function to display the current state of guessed word
{
    printf("Word: ");
    for(int i=0;word[i]!='\0';i++)
    {
        if(guessed[word[i]-'a'])//If the letter is guessed.
        {
            printf("%c ",word[i]);
        }
        else
        {
            printf("__ ");//If the letter is not guessed.
        }
    }
    printf("\n\n");
}

void hangman(int tries)//Function to display the hangman picture.
{
    //Array of hangman parts.
    char* hangman_parts[]={ "     _________",    "    |         |","    |         O",   "    |        /|\\","    |        / \\", "    |" };
    printf("\n");
    for(int i=0;i<tries;i++)//Printing upto the number of tries.
    {
        printf("%s\n",hangman_parts[i]);
    }
}

int main()
{
    srand(time(NULL));//To generate a random number.
    //List of possible words to guess.
    struct Word w_list[5]={"apple","mango","orange","guava","papaya"};
    int idx= rand()%5;//For selecting a random word from the list.

    char* secret_word=w_list[idx].word;

    int wordlen=strlen(secret_word);
    bool guess_l[26]={false};//To track guessed letters.

    int tries=0;
    while(tries<6)
    {
        display(secret_word,guess_l);//To display currently guessed letters in the word.
        hangman(tries);//To draw the hangman picture.
        printf("Guess a letter: ");
        char guess;
        scanf(" %c", &guess);
        guess=tolower(guess);//To convert into lowercase.
        
        //To check whether the guess is an alphabet,
        if (guess<'a'||guess>'z')
        {
            printf("Invalid input. Please enter a letter a-z.\n\n");
            continue;
        }
        //To check if the letter is already guessed.
        if(guess_l[guess-'a'])
        {
            printf("The letter was already guessed. Try again.\n");
            continue;
        }
        guess_l[guess-'a']=true;//Marking the letter as guessed.

        bool found=false;
        for(int i=0;i<wordlen;i++)//To check if the guessed letter is in the word.
        {
            if(secret_word[i]==guess)
            {
                found=true;
            }
        }

        if(found)
        {
            printf("Good Guess!\n\n");
        }
        else
        {
            printf("The letter %c is not present in the word.\n",guess);
            tries++;
        }

        bool all_guessed=true;
        for(int i=0;i<wordlen;i++)//To check if all the letters have been guessed;
        {
            if(!guess_l[secret_word[i]-'a'])
            {
                all_guessed=false;
                break;
            }
        }
        if(all_guessed)
        {
            display(secret_word,guess_l);
            printf("\nCongratulations. The word is %s.",secret_word);
            break;
        }
    }
    if(tries==6)//When all the tries are used.
    {
        hangman(6);
        printf("You have run out of tries.You lost.\nThe word is %s.",secret_word);
    }
    return 0;
}