/**COunt Number of Distinct Element*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int Count(int *, int);
void ascend(int *, int);

int main()
{
    int * numbs, n, i;
    printf("Number of Numbers ");
    scanf("%d", &n);
    numbs=(int *) malloc(n*sizeof(int));
    printf("Numbers :");
    for(i=0; i<n; i++)
        scanf("%d", &numbs[i]);
    ascend(numbs, n);
    printf(" No of Distinct Element is %d ", Count(numbs, n));
    getch();
    return 0;
}

int Count(int * num, int n)
{
    int j, count=0;
        for(j=0; j<n; j++)
        {
            if(num[j]!=num[j+1])
                count++;
        }
    return count;
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
