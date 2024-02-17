#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
 int n,i,j;
 char a[100][10],t[10];
 clrscr();
 printf("How many string:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%s",&a[i]);

 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
  { if (stricmp(a[i],a[j])>0)
   {
    strcpy(t,a[i]);
    strcpy(a[i],a[j]);
    strcpy(a[j],t);
     }

     }
     printf("\nnumber in asending order:");
     for (i=0;i<n;i++)
     printf("\n%s\t",a[i]);
     getch();
     }

