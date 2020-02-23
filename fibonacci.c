#include <stdio.h>
#include <cs50.h>

int fibonacci(int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
    for (int i=0; i<7; i++)
    {
        printf("%i\n", fibonacci(i));
    }
}
