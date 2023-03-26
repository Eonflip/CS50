// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(argv[]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n", replace(argv[]));
    }
    else
    {
        printf("This is an error\n");
        return 1;
    }
}

int replace (string argv[])
{
    string input = argv[1];
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'a' || input[i] == 'A')
        {
            input[i] = '6';
        }
        else if (input[i] == 'e' || input[i] == 'E')
        {
            input[i] = '3';
        }
        else if (input[i] == 'i' || input[i] == 'I')
        {
            input[i] = '1';
        }
        else if (input[i] == 'o' || input[i] == 'O')
        {
            input[i] = '0';
        }
    }
    return input;
}
