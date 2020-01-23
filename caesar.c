#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char rotate(char c, int shift_by, int key)
{
    return shift_by + (c - shift_by + key) % 26;
}

int main(int argc, string argv[])
{
    // $ ./caesar 1 2
    // argc == 3
    // argv[0] == "./caesar"
    // argv[1] == "1"
    // argv[2] == "2"

    // $ ./caesar dog
    // argc == 2
    // argv[0] == "./caesar"
    // argv[1] == "dog"
    
    // 1. get key from command line argument
    // 1.1. ensure exactly 1 argument is passed
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // 1.2. ensure the argument is a number
    string key_string = argv[1];
    for (int i = 0; i < strlen(key_string); i++)
    {
        // string x = "dog";
        // x[0] == 'd';
        // x[1] == 'o';
        // x[2] == 'g';
        if (!isdigit(key_string[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // 1.3. convert key from string to int
    int key = atoi(argv[1]);
    
    // 2. get plaintext as user input
    string plaintext = get_string("plaintext: ");
    
    // 3. add key in each characters in plaintext
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];
        // 'A' == 65
        // 'a' == 97
        if (c >= 65 && c < 65 + 26)
        {
            c = rotate(c, 65, key);
        }
        else if (c >= 97 && c < 97 + 26)
        {
            c = rotate(c, 97, key);
        }
        printf("%c", c);
    }
    printf("\n");
}
