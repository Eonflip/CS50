// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        replace();
    }
    else
    {
        printf("This is an error\n");
        return 1;
    }
}

int replace ()
{
    string input = argv[1];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] == 'a' || argv[1][i] == 'A')
        {
            argv[1][i] == '6';
        }
        else if (argv[1][i] == '' || argv[1][i] == 'A')
        {

        }
    }
}
