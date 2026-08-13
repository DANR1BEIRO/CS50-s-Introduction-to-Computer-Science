#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

char *concat(char *s1, char *s2);
int main(void)
{
    char *s1 = get_string("String 1: ");
    char *s2 = get_string("String 2: ");

    char *s3 = concat(s1, s2);
    printf("%s\n", s3);
    free(s3);
    return 0;
}

char *concat(char *s1, char *s2)
{
    int total_length = strlen(s1) + strlen(s2) + 1;
    char *concat_string = malloc(total_length);

    if (concat_string == NULL)
        return NULL;

    sprintf(concat_string, "%s %s", s1, s2);

    return concat_string;
}