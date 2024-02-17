#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void ascend(int *, int );
void rdmat(int **, int, int);
void dpmat(int **, int, int);
void strow(int **, int, int);
int main()
{
    int ** a, p, q, i;
    printf("Order of Matrix ");
    scanf("%d %d", &p, &q);
    a = (int **) malloc(p * sizeof(int *));
    for(i=0; i<p; i++)
        a[i] = (int *) malloc(q * sizeof(int *));
    printf("Enter Values ");
    rdmat(a, p, q);
    dpmat(a, p, q);

    getch();
    return 0;
}

void rdmat(int ** a, int p, int q)
{
    int i, j;
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d", &a[i][j]);
}

void dpmat(int ** a, int p, int q)
{
    int i, j;
    for(i=0; i<p; i++)
    {
        ascend(a[i], p);
        for(j=0; j<q; j++)
            printf("\t%d", a[i][j]);
        printf("\n\n");
    }
}

void ascend(int * num, int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
        for(j=i+1; j < n; j++)
            if(num[i] > num[j])
            {
                temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }

}
