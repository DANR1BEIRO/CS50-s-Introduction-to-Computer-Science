#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int hash(char *word);

int main(void)
{
    char *word = get_string("Word: ");
    printf("Hash value: %i\n", hash(word));
}

int hash(char *word)
{
    int hash_value = toupper(word[0]) - 'A';
    return hash_value;
}