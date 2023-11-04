// Implements a dictionary's functionality

#include <stdbool.h>
//#include <stdio.h> // fscanf, The Constante EOF,

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

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
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // 1. Open Dictionary file
    FILE *d_txt = fopen(dictionary, "r"); // Dictionary text
    if (dic_file == NULL)
    {
        printf("Could not open dictionary.\n");
        return 1;
    }

    // 2. Read file and record letter? to a Linked List
    char word[LENGHT +1]; // Buffer for each word
    while (fscanf(dic_file, "%s", word) != EOF) // 2.1 Read and record on word, while not End of File
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            printf("Memory Allocation Error\n");
            return false;
        }
        // Entender como copiar as palavras no linked list e seguir com o desmembramento. Rever a aula

        // Copying each word of the dictionary to a linked list
        // 2.2 1st word from node and 2nd word from main code created just before while loop
        strcpy(n->word, word);

        // 2.3 A Hash Table is an Array of Linked Lists. Now is to connect to an array (Hash Table). It will be done by Hash Function to be created. It takes a String and Returns a number (Index).
        //n->next = NULL;
        n->next = hash(word);
    }
    return false; //If done correctly, should not reach false
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
