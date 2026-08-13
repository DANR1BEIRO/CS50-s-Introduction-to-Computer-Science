#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct node
{
    string word;
    struct node *next;
} node;

node *create_new_node();
node *create_linked_list(node *ll, node *n);
void display_linked_list(node *ll);
void free_memory(node *ll);

int main(void)
{
    node *head = NULL;
    node *n = NULL;

    head = create_linked_list(head, n);
    display_linked_list(head);
    free_memory(head);
}

node *create_linked_list(node *head, node *n)
{

    int words = get_int("How many words: ");

    // populating the linked lis
    for (int i = 0; i < words; i++)
    {
        n = create_new_node();
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }
    return head;
}

node *create_new_node()
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->word = get_string("word: ");
    new_node->next = NULL;
    return new_node;
}

void display_linked_list(node *ll)
{
    node *ptr = ll;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%s.\n", ptr->word);
        }
        else
        {
            printf("%s -> ", ptr->word);
        }
        ptr = ptr->next;
    }
}

void free_memory(node *ll)
{
    node *current = ll;
    while (current != NULL)
    {
        node *next_node = current->next;
        free(current);
        current = next_node;
    }
}
