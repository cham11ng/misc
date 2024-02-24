#include <stdio.h>

short issymmetric(int *, short);
void print_matrix(int *, short);
void input_martix(int *, short);

int main()
{
    short m;
    int matrix[100][100], *ptr;

    printf("Enter the no. of rows(or cols) of the square matrix: ");
    scanf("%d", &m);

    ptr = (int *) matrix;

    input_martix(ptr, m);

    printf("The input matrix is:\n");
    print_matrix(ptr, m);

    if (issymmetric(ptr, m))
        printf("The matrix is symmetric!\n");
    else
        printf("The matrix is  not  symmetric!\n");

    return 0;
}

short issymmetric(int *arr, short size)
{
    short i, j, sym_flag=1;

    for (i=0; i<size; i++)
    {
        for (j=i; j<size; j++)
        {
            if ( *(arr+i*size+j) != *(arr+j*size+i) )
            {
                sym_flag = 0;
                break;
            }
        }

        if (!sym_flag)
            break;
    }

    return sym_flag;
}

void input_martix(int *arr, short size)
{
    short i, j;

    for (i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            printf("Enter element in row %d column %d: ", i, j);
            scanf("%d", (arr+i*size+j));
        }
    }
}

void print_matrix(int *arr, short size)
{
    short i, j;

    for (i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            printf("%d\t", *(arr+i*size+j));
        }

        printf("\n");
    }
}
