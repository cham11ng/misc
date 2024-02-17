/**ascending order**/
#include<stdio.h>
#include<conio.h>
#include<string.h>

void ascend(char *);

int main()
{
    char str[50];
    printf("String : ");
    fflush(stdin);
    gets(str);

    ascend(str);
    printf(" %s ", str);
    getch();
    return 0;
}

void ascend(char * str)
{
    int i, j;
    char temp;
    for(i=0; str[i]!='\0'; i++)
        for(j=i+1; str[j]!='\0'; j++)
            if(str[i] > str[j])
            {
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }


}
