#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int offset(char c)
{
    // 'A' == 65
    // 'a' == 97
    if (c >= 65 && c < 65 + 26)
    {
        return 65;
    }
    if (c >= 97 && c < 97 + 26)
    {
        return 97;
    }
    return 0;
}

int shift(char c)
{
    return c - offset(c);
}

int main(int argc, string argv[])
{
    // 1. get keyword from command line argument
    // 1.1. ensure exactly 1 argument is passed
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    // 1.2. ensure the argument is not a number
    string keyword = argv[1];
    int keyword_length = strlen(keyword);
    for (int i = 0; i < keyword_length; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    
    // 2. get plaintext as user input
    string plaintext = get_string("plaintext: ");
    
    // 3. encrypt plaintext
    printf("ciphertext: ");
    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        // plaintext == "hello"
        // keyword == "abc"
        
        char c = plaintext[i];
        int key = shift(keyword[j]);
        int o = offset(c);
        if (o > 0)
        {
            c = o + (c - o + key) % 26;
            j = (j + 1) % keyword_length;
        }
        printf("%c", c);
    }
    printf("\n");
}
