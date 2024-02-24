#include <stdio.h>

void print_r(int *, short int);
void sort_asc(int *, short int);

int main()
{
    short int n, i;
    int list[100];

    printf("How many elements? ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter element no. %d : ", i);
        scanf("%d", (list+i));
    }

    printf("\nBefore sorting:\n");
    print_r(list, n);

    sort_asc(list, n);

    printf("\nAfter sorting:\n");
    print_r(list, n);

    return 0;
}

void print_r(int *arr, short int size)
{
    int i;

    for (i=0; i<size; i++)
    {
        printf("Element[%d] = %d\n", i, *(arr+i));
    }
}

void sort_asc(int *arr, short int size)
{
    int i, j, tmp;

    for (i=0; i<(size-1); i++)
    {
        for (j=(i+1); j<size; j++)
        {
            if (*(arr+i) > *(arr+j))
            {
                tmp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = tmp;
            }
        }
    }
}
