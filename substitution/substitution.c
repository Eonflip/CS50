#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main(int argc, string argv[])
{
    string cipher[] = {};

    if (argc == 2)
    {

       if (isblank(argv[1]))
       {
        printf("Usage: ./substitution key(26 unique letters)\n");
       }
       else if (isalnum(argv[1] != true))
       {
        printf("Key must only contain alphanumeric characters\n");
       }
       else if (isalnum(argv[1]))
       {
        for (int i = 0; i < 26; i++)
        {
            cipher[i] = argv[1][i];
            printf("%c", cipher[i]);
        }
       }

    }
    else
    {
        printf("Please enter a single argument that is 26 unique alphanumeric characters");
    }

}