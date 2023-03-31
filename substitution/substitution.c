#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool checkUnique(char str[]);

int main(int argc, string argv[])
{
    // Check for correct number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check for valid key length
    int key_length = strlen(argv[1]);
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check for valid key characters
    if (!checkUnique(argv[1]))
    {
        printf("Key must contain 26 unique characters.\n");
        return 1;
    }
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    // Generate ciphertext using key
    char key[26];
    strcpy(key, argv[1]);
    char ciphertext[strlen(plaintext)];
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';

    // Print ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

//function to check whether or not a string has all unique alphanumeric characters
bool checkUnique(char str[])
{
    //initialize an array with all 26 values as false
    bool char_set[26] = { false };
    //write a for loop to iterate through the input string to check it for any repeated characters 
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
        int index = tolower(str[i]) - 'a';
        if (char_set[index])
        {
            return false;
        }
        char_set[index] = true;
    }
    return true;
}
