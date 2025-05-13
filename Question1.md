# **Steps to find the nth element in the Fibonacci series**
This section documents the steps used in the C code to find nth Fibonacci number recursively.

* ## *Step 1: Including Header files*
  Includes the standard input output library to use printf and scanf.
  
  ```c
  #include<stdio.h>

* ## *Step 2: Recursive Function*
  Defining a function that takes an integer n and returns the nth Fibonacci number.

  It returns the sum of previous two numbers as the number for any n greater than or equal to 2.

  The first fibonacci number is 0 and the second fibonacci number is 1.

  ```c
  int fib(int n)
  {
    if(n==1)
        return 0; 
    else if(n==2)
        return 1; 
    else
        return fib(n-2)+fib(n-1);
  }
* ## *Step 3: Base Condition*
  If n is less than or equal to 2, n is returned diretly.

  The first fibonacci number is 0 and the second fibonacci number is 1.
  ```c
  if(n==1)
        return 0; 
  else if(n==2)
        return 1;
* ## *Step 4: Recursive Step*
  Recursively call fib(n-1) and fib(n-2).
  Add them to compute nth Fibonacci number.
  ```c
  return fib(n-2)+fib(n-1);
* ## *Step 5: Main Function*
  + ### Take input from the user.
    ```c
    int n,val;
    printf("Enter the value: ");
    scanf("%d",&n);
  + ### Printing Output.
    Call the function to get Fibonacci number and store the value in the variable "val".

    ```c
    val=fib(n);
    printf("The %dth fibonacci number is %d",n,val);
  So, the main function is:  
  ```c
  int main()
  {
      int n,val;
      printf("Enter the value: ");
      scanf("%d",&n);
      val=fib(n);
      printf("The %dth fibonacci number is %d",n,val);
      return 0;
  }

***
***
# **Steps to create "Hangman" game: 
This section documents the steps used in the C code to create Hangman Game.

* ## Step 1: List for random words.
  Define a structure to hold list of possible words to be guessed.
  ```c
  struct Word
  {
      char word[20];
  };
* ## Step 2: Choosing a random word.
  Choose a random word as secret word.
  ```c
  srand(time(NULL));
  struct Word w_list[5]={"apple","mango","orange","guava","papaya"};
  int idx= rand()%5;
* ## Step 3: Valid Guess or not
  Check if the guess is a valid one.  
  ```c
  if (guess<'a'||guess>'z')
  {
      printf("Invalid input. Please enter a letter a-z.\n\n");
      continue;
  }
  if(guess_l[guess-'a'])
  {
      printf("The letter was already guessed. Try again.\n");
      continue;
  }
* ## Step 4: Correct or Incorrect guess.
  Check if the letter is present in the secret word.
  ```c
  bool found=false;
  for(int i=0;i<wordlen;i++)
  {
      if(secret_word[i]==guess)
      {
          found=true;
      }
  }
* ## Step 5: Guessed word
  Check if the complete word is guessed.
  ```c
  bool all_guessed=true;
  for(int i=0;i<wordlen;i++)
  {
      if(!guess_l[secret_word[i]-'a'])
      {
          all_guessed=false;
          break;
      }
  }//If all_guessed=true complete word is guessed.
* ## Step 6: Out of tries
  Check if all tries are used.
  ```c
  if(tries==6)//Ran out of tries.
* ## Step 7: Displaying the guessed part.
  Display the status of the word after every guess.
  ```c
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
* ## Step 8: Displaying the Hangman
  Store the parts of hangman in an array and display it after every guess.   
  ```c
  char* hangman_parts[]={ "     _________",    "    |         |","    |         O",   "    |        /|\\","    |        / \\", "    |" };
  printf("\n");

  for(int i=0;i<tries;i++)//Printing upto the number of tries.
  {
      printf("%s\n",hangman_parts[i]);
  }
***
***
# **Steps to create Rock-Paper-Scissors Game.**
This section documents the steps used in the C code to create Rock-Paper-Scissors Game.

* ## Step 1: Computer's choice
  Select a random number from any range of numbers where rock,paper and scissors is assigned to every number with equal probabilities.
  ```c
  srand(time(NULL));
  n=rand()%99;
  if(n<=33)
      computer='r';
  else if(34<=n<=66)
      computer='p';
  else
      computer='s';
* ## Step 2: User's choice
  Take an input from the user.
  ```c
  printf("Enter r for ROCK, p for PAPER, s for SCISSORS: ");
  scanf(" %c", &user);
* ## Step 3: Comparing the choices
  Compare the choices of the two players to get a result.
  ```c
  if(user==computer)
      return 0;
  if(user=='r')
      if(computer=='s')
          return 1;
  if(user=='p')
      if(computer=='r')
          return 1;
  if(user=='s')
      if(computer=='p')
          return 1;
    return -1;
* ## Step 4: Result
  Display the result.
  ```c
  if(result==0)
      printf("Tie!!!");
  else if(result==1)
      printf("You win!!!");
  else
      printf("You lose...");
***
***
# Steps to create Guess the Number Game

* ## Step 1: Chosing random number
  Choose a random number in the input range.
  ```c
  srand(time(NULL));
  num=rand()%n;
* ## Step 2: Guessed value
  Take user's guess as input.
  ```c
  scanf("%d",&guess);
* ## Step 3: Checking if the guess is correct
  Compare the two numbers and check if the guess is higher,lower or equal to the actual number.
  ```c
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
* ## Step 4: Limit on number of attempts
  End the game if the number of attempts exceeds the limit.
  ```c
  if(attempts>l)
  {
      printf("\nToo many attempts. You lose.\nThe number is %d.\n",num);
      break;
  }