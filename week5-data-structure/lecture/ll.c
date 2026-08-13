#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *linked_list = NULL;
    for (int i = 0; i < 3; i++)
    {
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            return 1;
        }

        new_node->number = get_int("Number: ");
        new_node->next = NULL;

        new_node->next = linked_list;
        linked_list = new_node;
    }

    for (node *ptr = linked_list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
    return 0;
}