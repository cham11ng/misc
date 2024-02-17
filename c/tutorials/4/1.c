/**ascending order**/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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
    for(i=0; i<n; i++)
        printf(" %d ", numbs[i]);
    getch();
    return 0;
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
