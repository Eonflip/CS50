#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool checkUnique(char str[]);

int main(int argc, string argv[])
{
    int key_length = strlen(argv[1]);
    char cipher[26];

    if (argc != 2)
    {
        printf("Usage: ./substitution key (26 unique letters) \n");
        return 1;
    }
    else if (key_length != 26)
    {
        printf("Key must contain 26 unique alphanumeric characters\n");
        return 1;
    }
    else if (key_length == 26)
    {
        if (checkUnique(argv[1]))
        {
            for(int i = 0; i < 26; i++)
            {
                if (!isalnum(argv[1][i]))
                {
                    printf("Key must only contain alphanumeric characters.\n");
                    return 1;
                }
                else
                {
                    string plaintext = get_string("plaintext: ");
                    char key[] = argv[1];
                    string cipher_key = key;
                    char ciphertext[strlen(plaintext)];

                    for (int i = 0; i < strlen(plaintext); i++) {
                        if (plaintext[i] == ' ')
                        {
                            ciphertext[i] = ' ';
                        }
                        else
                        {
                            int index = plaintext[i] - 'A';

                            ciphertext[i] = key[index];
                        }
                    }
                    printf("Plaintext: %s\n", plaintext);
                    printf("Ciphertext: %s\n", ciphertext);
                    return 0;
                }
            }
        }
    }
}


bool checkUnique(char str[])
{
    bool char_set[256] = { false };

    for (int i = 0; str[i] != '\0'; i++)
    {
        int val = str[i];
        if (char_set[val]) {
            return false;
        }
        else
        {
            char_set[val] = true;
        }
    }
    return true;
}