#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void arrange(char **, int);
int main()
{
    char ** words;
    int n, i;
    printf ("How many Word's ? ");
    scanf("%d", &n);
    words = (char **) malloc(n * sizeof(char *));
    for(i=0; i<n; i++)
        words[i] = (char *) malloc (20 * sizeof(char));
    for(i=0; i<n; i++)
    {
        printf("Word %d : ", i+1);
        fflush(stdin);
        gets(words[i]);
    }
    arrange(words, n);
    printf("Arranged Words are : \n");
    for(i=0; i<n; i++)
        printf("%s\n", words[i]);
    return 0;
}

void arrange(char ** st, int n)
{
    int i, j;
    char temp[20];
    for(i=0; i < n-1; i++)
        for(j=i+1; j < n; j++)
            if(strcmp(st[i], st[j]) > 0)
            {
                strcpy(temp, st[i]);
                strcpy(st[i], st[j]);
                strcpy(st[j], temp);
            }
}


