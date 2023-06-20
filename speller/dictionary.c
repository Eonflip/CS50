// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen("dictionary", "r")
    if (infile == NULL)
    {
        printf("Cannot Open File\n");
        return 0;
        return false;
    }

    fseek(infile, 0, SEEK_END);
    long fileSize = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    char *buffer = malloc(sizeof(fileSize + 1));
    if (buffer == NULL)
    {
        printf("Not enough memory to read filesize\n");
        return 1;
        return false;
    }

    size_t bytesRead = fread(buffer, 1, fileSize, infile)
    if (bytesRead < fileSize)
    {
        printf("Failed to read file\n");
        return 2;
        return false;
    }

    buffer[bytesRead] = "\0";

    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(const char *dictionary)
{
    // TODO
    char words[50];
    FILE *infile = fopen("dictionary", "r");
    int counter = 0;
    if(loaded)
    {
        while (fscanf(infile, "%s", name) == 1)
        {

        }

    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
