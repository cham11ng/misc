#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct
{
	char name[20];
	int age;
	int roll;
	int year;
	char fac[10];
} stdu ;

stdu readstu();
void sortname(stdu *, int);
void dispstu(stdu);

int test;
char other;

int main()
{
	int n, i;
	stdu * s;
	printf("Enter no of Student ");
	scanf("%d", &n);
	s=(stdu *) malloc (n * sizeof(stdu));
	for(i=0; i<n; i++)
		s[i]= readstu();
	sortname(s, n);
	for(i=0; i<n; i++)
		dispstu(s[i]);
	getch();
	return 0;
}

stdu readstu()
{
	stdu s;
	printf("Enter name, age, roll, year, fac\n");
	scanf("%s %d %d %d %s", s.name, &s.age, &s.roll, &s.year, s.fac);
	return s;
}

void dispstu(stdu s)
{
	printf("Name=%s Age=%d Roll=%d Year=%d Fac=%s\n", s.name, s.age, s.roll, s.year, s.fac);
}

void sortname(stdu * s, int n)
{
	stdu temp;
	int i, j;
	for( i=0; i<n; i++)
		for(j=i+1; j<n;j++)
			if(strcmp(s[i].name, s[j].name)>0)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
}

