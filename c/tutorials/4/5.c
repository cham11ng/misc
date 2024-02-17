/**COunt Number of Distinct Element*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void eliminate(int *, int *, int, int *);
void ascend(int *, int);

int main()
{
    int * numbs, eli[50], n, i, k=0;
    printf("Number of Numbers ");
    scanf("%d", &n);
    numbs=(int *) malloc(n*sizeof(int));
    printf("Numbers :");
    for(i=0; i<n; i++)
        scanf("%d", &numbs[i]);
    ascend(numbs, n);
    eliminate(eli, numbs, n, &k);
    for(i=0; i<k; i++)
        printf("%d ", eli[i]);
    getch();
    return 0;
}

void eliminate(int * eli, int * num, int n, int * k)
{
    int i;
    for(i=0; i<n; i++)
        if(num[i]!=num[i+1])
        {
            eli[*k]=num[i];
            (*k)++;
        }
}

void ascend(int * num, int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
        for(j=i+1; j < n; j++)
        {
            if(num[i] > num[j])
            {
                temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
}
