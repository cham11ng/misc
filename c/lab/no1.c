#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{
 int n,v,c,d,w;
 char a[100];

 printf("Enter the word:");
 gets(a);

 for(n=0; a[n]!='\0'; n++)
 {
  if(a[i]=>'A' && a[i]<='Z') a[i]=tolower(a[i]);
  if(a[i]=='a' && a[i]=='e' && a[i]=='i' && a[i]=='o' &&  a[i]=='u')
  v++;
  else if(a[i]=>0 && a[i]<=9) d++;
  else if(a[i]=" " && a[i]="\n" && a[i]="\t") w++;
  else c++;
  }
  printf("No. of vowels:%d\n",v);
  printf("No. of consonent:%d\n",c);
  printf("No. of digits:%d\n",d);
  printf("No. of white spaces:%d",w);
  getch();
  }
