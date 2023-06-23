// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 17602;

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
    int hash_value = 0;

    int len = strlen(word);

    if (len >= 1 && isalpha(word[0]))
    {
        hash_value += 677 * (tolower(word[0]) - 'a');
    }
    if (len >= 2 && isalpha(word[1]))
    {
        hash_value += 27 * (tolower(word[1]) - 'a');
    }
    if (len >= 3 && isalpha(word[2]))
    {
        hash_value += tolower(word[2]) - 'a';
    }

    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

}
