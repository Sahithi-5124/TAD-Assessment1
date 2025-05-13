#include <stdio.h>

int fib(int n)
{
    if(n==1)
        return 0; //Considering 0 as the first fibonacci number.
    else if(n==2)
        return 1; //Considering 1 as the second fibonacci number.
    else
        return fib(n-2)+fib(n-1); //Sum of the previous two numbers.
}

int main()
{
    int n,val;
    printf("Enter the value: ");
    scanf("%d",&n);
    val=fib(n);
    printf("The %dth fibonacci number is %d",n,val);
    return 0;
}