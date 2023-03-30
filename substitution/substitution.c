#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main(int argc, string argv[])
{

    string cipher_key[26] = {};

    if (argc == 2)
    {
        for (int i = 0; i < 26; i++)
        {
            do
            {
                printf("Key must only contain 26 unique alphanumeric characters");
            }
            while (isalnum(argv[1][i]) != true);

            cipher_key[i] = argv[1][i];
        }
    }
    else
    {
        printf("Please enter a single argument that is 26 unique alphanumeric characters");
    }
}