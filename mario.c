#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Part 1: get user input
    int height;
    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // Part 2: build pyramid
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < height; x++)
        {
            if (x >= height - y - 1) 
            {            
                printf("#");
            }
            else
            {
                printf(" ");    
            }
        }
        printf("\n");
    }
}
