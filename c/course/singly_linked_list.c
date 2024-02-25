#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *new = malloc(sizeof(node));

        // Handling allocation error.
        if (new == NULL)
        {
            free(new);
            return 1;
        }

        // Assigning number.
        new->number = number;
        new->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            list = new;
        }
        // If new number is small, insert at the beginning.
        else if (new->number < list->number)
        {
            new->next = list;
            list = new;
        }
        // if belongs later in the list
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // if end of the list
                if (ptr->next == NULL)
                {
                    ptr->next = new;
                    break;
                }

                // if in the middle of list
                if (new->number < ptr->next->number)
                {
                    new->next = ptr->next;
                    ptr->next = new;
                    break;
                }
            }
        }
    }

    // new pointer to point all the list
    node *ls_ptr = list;

    while (ls_ptr != NULL)
    {
        printf("%i\n", ls_ptr->number);
        ls_ptr = ls_ptr->next;
    }

    return 0;
}
