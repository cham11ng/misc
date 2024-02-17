#include<stdio.h>
#include<conio.h>
void main()
{
 int n,i,j,t,a[10];
 clrscr();
 printf("How many no.:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);

 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
  { if (a[i]>a[j])
   {
     t=a[i];
     a[i]=a[j];
     a[j]=t;
     }

     }
     printf("\nnumber in asending order:");
     for (i=0;i<n;i++)
     printf("\n%d\t",a[i]);
     getch();
     }