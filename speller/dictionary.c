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

//dictionary counter
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);

    node *n = table[hash_value];

    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }

    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hash_value = 0;
    int len = strlen(word);

    // Check for first character (assuming it exists)
    if (len >= 1 && isalpha(word[0]))
    {
        hash_value += 677 * (tolower(word[0]) - 'a');
    }

    if (len >= 2)
    {
        if (isalpha(word[1]))
        {
            hash_value += 27 * (tolower(word[1]) - 'a');
        }
        else
        {
            // Handle the case where second character is not a letter (e.g. an apostrophe)
            hash_value += 1;
            return hash_value;
        }
    }

    // Check for third character or apostrophe
    if (len >= 3)
    {
        if (isalpha(word[2]))
        {
            hash_value += tolower(word[2]) - 'a';
        }
        else
        {
            // Handle the case where third character is not a letter
            hash_value += 1;
            return hash_value;
        }
    }
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char dict_word[LENGTH + 1];


    node *root;

    while (fscanf(infile, "%s", dict_word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, dict_word);

        int index = hash(n->word);

        if (table[index] == NULL)
        {
            table[index] = n;
            n->next = NULL;
        }
        // otherwise set next node as table[index], table[index] as current node n
        else
        {
            n->next = table[index];
            table[index] = n;
        }
        dict_size++;

    }

    fclose(infile);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (dict_size != 0)
    {
        return dict_size;
    }
    else
    {
        return 0;
    }

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Iterate over hash table and free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        // Assign cursor
        node *n = table[i];

        while (n != NULL)
        {
            // Make temp equal cursor;
            node *tmp = n;
            // Point cursor to next element
            n = n->next;
            // free temp
            free(tmp);
        }

        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }

    return false;


}
