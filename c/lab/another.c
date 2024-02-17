#include<stdio.h>
#include<conio.h>
void countchar(char s[],int *v,int *c,int *w,int *s[],int *d);
{
 int i;*s=0;*d=0;*v=0;*c=0;*w=0;
 for(i=0;s[i]!=0;i++)
  {
  if(a[i]>='A' && a[i]<='Z') s[i]+=32;
  if(a[i]>='a' && a[i]<='z')
  {
   switch(s[i])
   {
    case 'a';
    case 'e';
    case 'i';
    case 'o';
    case 'u';
    }
    *v++;
    break;
    default;
    *c++;
    }
    }
    else if(s[i]>='0' && s[i]<='9') *d++;
    else if(s[i]>=" " && s[i]=='\n' && s[i]=='\t') *w++
    else *s++;
    }
    }
    int countwords(char s[])
    {
     int i,wordcount=0,flag=0;
     for (i=0;s[i]!='/0';i++)
     {
       if((s[i]=='')||(s[i]=='\n')||(s[i]=='\t'))
       {
	 if (flag==1) wordcount++;
	  flag=0;
	  }
	  else
	  {
	   flag=1;
	  }
	  }
	  if(flag==1) wordcount++;
	  return wordcount;
       }
       void main()
       {
	char s[100];int v,c,w,d,s,wordcount;
	printf("Enter a line of text:");
	gets(s);
	countchar(s[],&v,&c,&w,&s,&d);
	count=countwords(s);
	printf("Vowels=%d,Consonant=%d,Digits=%d,Whtespace=%d,Special Character=%d",v,c,d,w,s,count);
	getch();
	}