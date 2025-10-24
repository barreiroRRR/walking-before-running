// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// tracks number of words added to the hash table
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int idx = hash(word);
    node *cursor = table[idx];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0) return true;
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    if (word == NULL || word[0] == '\0')
    {
        return 0;
    }

    unsigned int hash_value = 0;

    for (int i = 0; i < 4 && word[i] != '\0'; i++)
    {
        char c = tolower((unsigned char)word[i]);
        hash_value = hash_value + c;
    }

    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        fclose(input);
        return false;
    }

    // creates a buffer for copying words
    char buffer[LENGTH + 1];
    while (fscanf(input, "%45s", buffer) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        strcpy(n->word, buffer);
        int inx = hash(buffer);
        n->next = table[inx];
        table[inx] = n;
        word_count++;
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor;
    node *tmp;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
