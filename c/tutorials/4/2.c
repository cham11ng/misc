/**Largest Subtraction between any two Entered number**/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int subt( int *, int);

int main()
{
    int * numbs, n, i;
    printf("Number of Numbers ");
    scanf("%d", &n);
    numbs=(int *) malloc(n*sizeof(int));
    printf("Numbers : ");
    for(i=0; i<n; i++)
        scanf("%d", &numbs[i]);
    printf("Largest Sum between any two number is %d", subt(numbs, n));
    getch();
    return 0;
}

int subt(int * num, int n)
{
    int i, j, large, diff;
    if(n==1)
        return num[0];

    large=num[0]-num[1];
    for(i=0; i<n; i++)
        for(j=0; j < n; j++)
            if(i!=j)
            {
                diff=num[i]-num[j];
                if(large<diff)
                    large=diff;
            }

    return large;
}
