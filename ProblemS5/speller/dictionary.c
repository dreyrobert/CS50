// Implements a dictionary's functionality

#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
unsigned int numWords = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashNum = hash(word);

    node *cursor = table[hashNum];
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
    char firstLetter = toupper(word[0]);
    // retorna o codigo da letra.
    return ((int) firstLetter) - ((int) 'A');
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE  *dictFile = fopen(dictionary, "r");
    if (dictFile == NULL)
    {
        return false;
    }

    // LENGTH is defined by 45 in dictionary.h
    char str[LENGTH + 1];
    // EOF = final do arquivo.
    while (fscanf(dictFile, "%s", str) != EOF)
    {
        // crio um node temporario
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            // se não tiver espaço, da erro.
            return false;
        }

        // pego o codigo da minha palavra
        int hashNum = hash(str);

        //copio a palavra e coloco no temp->word
        strncpy(temp->word, str, sizeof(str));
        // se não tiver nada, faz ele ser o primeiro.
        if (table[hashNum] == NULL)
        {
            temp->next = NULL;
        }
        // se tiver algo, faz ele ser o primeiro e o proximo estar ligado a você.
        else
        {
            temp->next = table[hashNum];
        }
        // tiro do temp a informação
        table[hashNum] = temp;
        // atualizo o numero de palavras lidas
        numWords += 1;
    }

    fclose(dictFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return numWords;
}

void freenode(node *n)
{
    if (n->next != NULL)
    {
        freenode(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}