#include <stdio.h>

void print_matrix(int *, short, short);
void input_martix(int *, short, short);
void add_matrix(int *, int *, int*, short, short);

int main()
{
    short b, a;
    int matrixA[100][100], *ptrA;
    int matrixB[100][100], *ptrB;
    int matrixC[100][100], *ptrC;

    printf("Enter the no. of rows and cols of the matrix: ");
    scanf("%d %d", &a, &b);

    ptrA = (int *) matrixA;
    ptrB = (int *) matrixB;
    ptrC = (int *) matrixC;

    printf("\nEnter the elements of matrix A:\n");
    input_martix(ptrA, a, b);

    printf("\nEnter the elements of matrix B:\n");
    input_martix(ptrB, a, b);

    printf("\nMatrix A is as follows:\n");
    print_matrix(ptrA, a, b);

    printf("\nMatrix B is as follows:\n");
    print_matrix(ptrB, a, b);

    add_matrix(ptrA, ptrB, ptrC, a, b);

    printf("\nC = A + B\nMatrix C is as follows:\n");
    print_matrix(ptrC, a, b);

    return 0;
}

void input_martix(int *arr, short m, short n)
{
    short i, j;

    /////printf("\n\n i = %d  j = %d  m = %d  n = %d \n\n", i, j, m, n);/////

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("Enter element in row %d column %d: ", i, j);
            scanf("%d", (arr+i*n+j));
        }
    }
}

void print_matrix(int *arr, short m, short n)
{
    short i, j;

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%d\t", *(arr+i*n+j));
        }

        printf("\n");
    }
}

void add_matrix(int *A, int *B, int *C, short m, short n)
{
    short i, j;

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            *(C+i*n+j) = *(A+i*n+j) + *(B+i*n+j);
        }
    }
}
