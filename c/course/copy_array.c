#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));

    if (list == NULL) // in case of error, malloc return NULL.
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *more = malloc(4 * sizeof(int));

    if (more == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        more[i] = list[i];
    }
    more[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", more[i]);
    }

    free(list);
    free(more);

    return 0;
}
