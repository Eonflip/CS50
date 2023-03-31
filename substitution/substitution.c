#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key(26 unique letters)\n");
        return 1;
    }

    int key_length = strlen(argv[1]);

    if (key_length == 26)
    {
        char Seen[UCHAR_MAX + 1] = {0};
        for (int i = 0; i < 26; i++)
        {
            unsigned char c = argv[1][i];
            c = toupper(c);
            if (Seen[c])
            {
                printf("Key must contain 26 unique non-repeating alphanumeric characters\n");
                return 1;
            }
            Seen[c] = 1;
        }
    }

    if (key_length != 26)
    {
        printf("Key must contain 26 alphanumeric characters.\n");
        return 1;
    }

    char cipher[26];
    for (int i = 0; i < 26; i++)
    {
        if (!isalnum(argv[1][i]))
        {
            printf("Key must only contain alphanumeric characters.\n");
            return 1;
        }

        for (int j = 0; j < i; j++)
        {
            if (toupper(argv[1][i]) == toupper(cipher[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }

        cipher[i] = toupper(argv[1][i]);
    }

    // do something with the cipher
    string plaintext = get_string("plaintext: ");
    string cipher_text = malloc(strlen(plaintext) + 1);
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            // convert character to uppercase and subtract ASCII value of 'A' to get index
            int index = toupper(c) - 'A';
            // use index to look up corresponding character in cipher array
            char encrypted_char = cipher[index];
            // copy the encrypted character to the cipher_text array
            cipher_text[i] = encrypted_char;
        }
        else
        {
            // print non-alphabetic character unchanged
            cipher_text[i] = c;
        }

    }
    cipher_text[strlen(plaintext)] = '\0';
    printf("%s", cipher_text);
    free(cipher_text);
    return 0;
}