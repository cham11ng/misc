#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef struct
{
	char name[20];
	int age;
	int roll;
	int year;
	char fac[10];
} std ;

std readstu(FILE *);
void dispstu(FILE *);

void main()
{
	int n, i;
	FILE * fptr;
	std * s;
	printf("No of Student ");
	scanf("%d", &n);
	s=(std *) malloc (n * sizeof(std));
	fptr=fopen("s.txt","w+");
	for(i=0; i<n; i++)
		s[i]= readstu(fptr);

	for(i=0; i<n; i++)
		dispstu(fptr);
    fclose(fptr);
	getch();
}

std readstu(FILE * fptr)
{
	std s;
	printf("Enter name, age, roll, year, fac\n");
	scanf("%s %d %d %d %s", s.name, &s.age, &s.roll, &s.year, s.fac);
	fprintf(fptr,"%s %d %d %d %s\n", s.name, s.age, s.roll, s.year, s.fac);
	return s;
}

void dispstu(FILE * fptr)
{
	std s;
	rewind(fptr);
	fscanf(fptr, "%s %d %d %d %s", s.name, &s.age, &s.roll, &s.year, s.fac);
	printf("Name=%s Age=%d Roll=%d Year=%d Fac=%s\n", s.name, s.age, s.roll, s.year, s.fac);
}
