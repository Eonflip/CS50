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
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hashValue = hash(word);
    node *cursor = table[hashValue];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
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
    char word[LENGTH + 1];
    unsigned int hashValue = hash(word);



    FILE *infile = fopen("dictionary", "r");
    if (infile == NULL)
    {
        printf("Cannot Open File\n");
        return false;
    }

    while (fscanf(infile, "%s", word) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            fclose(infile);
            printf("Not enough memory to load dictionary.\n");

            node *cursor = table[hashValue];
            while (cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);
            }

            return false;
        }

        strcpy(newNode -> word, word);
        newNode->next = NULL;


        if (table[hashValue] == NULL)
        {
            table[hashValue] = newNode;
        }
        else
        {
            node *cursor = table[hashValue];
            while (cursor->next != NULL)
            {
                cursor = cursor -> next;
            }
            cursor->next = newNode;
        }

    }
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            count++;
            cursor = cursor -> next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (unsigned int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        table[i] = NULL;
    }
    return true;
}
