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

// Number of buckets in hash table //TableSize
const unsigned int N = 199933; //Prime Number close to 70% of full dictionary with 143.091 words

// Hash table
node *table[N]; // Array of Nodes (Head Nodes)

//variables
unsigned int word_count = 0;
unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    node *cursor = malloc(sizeof(node));
    if(cursor == NULL)
    {
        printf("Memory Allocation Error for Cursor\n");
        return false;
    }

    cursor = table[hash_value];
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
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
    // TODO
    // sum the ASCII values of the characters in the word and then use modulo to map it to a hash table index
    unsigned int hashValue = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hashValue += tolower(word[i]);
    }
    return hashValue % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // 1. Open Dictionary file
    FILE *dic_file = fopen(dictionary, "r"); // Dictionary text
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
        //n->next = NULL;

        // 2.3 A Hash Table is an Array of Linked Lists. Now is to connect to an array (Hash Table). It will be done by Hash Function to be created. It takes a String and Returns a number (Index).
        hash_value = hash(word);
        n->next = table[hash_value]; //Set new node to point to same place as Head Node
        table[hash_value] = n; //Define Head Node to Start with Value of new Node and keep Pointing to same place. Should not point to new node instead?
        //It will point to n node rather to where n is pointing
        word_count++;
    }

    fclose(dic_file)
    return true; //If done correctly, should not reach false
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
    node *tmp = malloc(sizeof(node));
    if(tmp == NULL)
    {
        printf("Memory Allocation Error for node tmp\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        free(cursor); //Is it necessary?
    }
    return false;
}
