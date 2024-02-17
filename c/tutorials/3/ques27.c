#include<stdio.h>

int woC(char *);
int main()
{
    char string[50];
    printf("Line of Character : ");
    gets(string);
    printf("Number Of Words : %d", woC(string));
    getch();
    return 0;
}

int woC(char str[])
{
    int i,wordcount=0,flag=0;
    for (i=0;str[i]!='\0';i++)
    {
        if((str[i]==' ') || (str[i]=='\n') || (str[i]=='\t'))
        {
            if (flag==1)
                wordcount++;
            flag=0;
        }
        else
            flag=1;
    }
        if(flag==1)
            wordcount++;
    return wordcount;
}
