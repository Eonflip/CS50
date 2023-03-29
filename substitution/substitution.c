#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    string cipher_key[26] = {}

    for (int i = 0; i < 26; i++)
    {
        cipher_key[i] = argv[1][i]
    }

    if (argc == 2)
    {
        do
        {
            printf("Key must only contain 26 unique alphanumeric characters");
        }
        while (!isalnum(argv[1])
    }
}