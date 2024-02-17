#include<stdio.h>
#include<string.h>
#define MAX 200
int arrange(char [][MAX], int);

int main()
{
    char name[MAX][MAX];
    int i, n;
    printf("Number of Name : ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
        scanf("%s", name[i]);

    arrange(name, n);
    printf("Name in Alphabetical Order \n");
    for(i=0; i<n; i++)
        printf( "Name %d = %s \n", i+1, name[i]);
    return 0;
}


int arrange(char name[][MAX], int n)
{
    int i, j;
    char temp[40];
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(strcmp(name[i], name[j]) > 0)
            {
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
    return 0;
}

