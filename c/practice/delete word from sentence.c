#include<stdio.h>
#include<conio.h>
#include<string.h>
char * DEL(char *, char *);
int main()
{
    char sen[50], word[50];
    printf("Sentence : ");
    fflush(stdin); gets(sen);
    printf("Word to delete : ");
    fflush(stdin); gets(word);
    printf("String is : %s", DEL(sen, word));
    return 0;
}

char * DEL(char * sen, char * word)
{
    static char temp[30];
    int i, j, k=0, n = strlen(word);
    for(i=0; sen[i]!='\0'; i++)
    {
        for(j=i; j < i+n; j++)
        {
            if(sen[j] != word[j-i])
                break;
        }
        if(j == i+n)
            i+=n;
        temp[k++]=sen[i];
    }
    temp[k]='\0';
    return temp;
}
