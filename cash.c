#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //get user input
    float dollars; 
    do
    {
        dollars = get_float("change owed\n");
    }   
    while (dollars < 0);   
    
    //convert dollars to cents
    int cents = round(dollars * 100);
    printf("%i\n", cents);
    
    //count cents to give back
    int count = 0;
    int all_cents[] = {25, 10, 5, 1};
    for (int i = 0; i < 4; i++)
    {
        int current_cent = all_cents[i];
        while (cents >= current_cent)
        {
            count++; 
            cents = cents - current_cent;
        }    
    }
    printf("%i\n", count);
}
