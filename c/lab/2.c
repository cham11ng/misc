#include<stdio.h>
#include<conio.h>
#define MAX 16

int acend(int *, int);

int main()
{
    int num[MAX], i, n;
    printf("Number of numbers :");
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &num[i]);
    acend(num, n);
    printf("Number in ascending order ");
    for(i=0; i<n; i++)
        printf("%d\t", num[i]);
    getch();
    return 0;
}

int acend(int num[], int n)
{
    int i, j, temp;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            if(num[i]>num[j])
            {
                temp=num[j];
                num[j]=num[i];
                num[i]=temp;
            }
        }
    return 0;
}
