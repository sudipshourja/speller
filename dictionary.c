// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#include "dictionary.h"

#define N 10000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Hash table
node *table[N];

// Number of words loaded
unsigned int numWords = 0;

// Lowering the word
void toLowerCaseInPlace(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

// Returns true if word is in dictionary, else false
bool check(char *word)
{
    toLowerCaseInPlace(word);
    // TODO: Hash word to obtain hash value
    unsigned int index = hash(word);

    // Access linked list at that index in the hash table
    node *cursor = table[index];

    // Traverse linked list, looking for the word
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

// To hash a word
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO: Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    for (unsigned int i = 0; i < N; i++)
    {
        table[i] = malloc(sizeof(node));
        table[i]->word[0] = '\0';
        table[i]->next = NULL;
    }

    // Read string from file one at a time
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create new node for each word
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("Error: Not enough memory a new node\n");
            return false;
        }

        // Transfering word to that node
        strcpy(newNode->word, word);

        // Hash word to obtain a hash value
        unsigned int index = hash(word);

        // Insert node into hash table
        newNode->next = table[index];
        table[index] = newNode;

        // Increase number of words loaded
        numWords += 1;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO : Loop though all elemets of hash table
    for (unsigned int i = 0; i < N; i++)
    {
        // Make to pointer pointing to the headnnode
        node *temp = table[i];
        node *cursor = temp;

        // While there is a node delete it
        while (temp != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }

    return true;
}
