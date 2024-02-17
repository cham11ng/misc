/**Largest Sum between any two Entered number**/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int sumn(int *, int);

int main()
{
    int * numbs, n, i;
    printf("Number of Numbers ");
    scanf("%d", &n);
    numbs=(int *) malloc(n*sizeof(int));
    printf("Numbers : ");
    for(i=0; i<n; i++)
        scanf("%d", &numbs[i]);
    printf("Largest Sum between any two number is %d", sumn(numbs, n));
    getch();
    return 0;
}

int sumn(int * num, int n)
{
    int i, large, sum;
    if(n==1)
        return num[0];

    large=num[0]+num[1];
    for(i=0; i<n-1; i++)
    {
        sum=num[i]+num[i+1];
        if(large<sum)
            large=sum;
    }
    return large;
}
