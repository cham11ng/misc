#include <stdio.h>
#include <string.h>
void main()
{
    char s[50];
    int n, i;

    printf("Enter String ");
    gets(s);
    n=strlen(s);

    for(i=0; i<=n; i++)
    {
        if(s[i]>='a' && s[i]<='z')
            s[i]=s[i]-32;
        else if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]+32;
    }

    printf("%s \n",s);
}
