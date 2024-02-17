#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define pfn "student.dat"

typedef struct
{
	char sub[20];
	float mo;
} mark;

typedef struct
{
    char name[20];
	mark m[5];
	float avg;
	int age;
	int roll;
	int year;
	char fac[10];
} std ;

std readstu(FILE *);
void sortper(std *, int);
void dispstu(FILE *);

int main()
{
	int n, i;
	FILE * fptr;
	std * s;
	printf("No of Student ");
	scanf("%d", &n);
	fptr=fopen(pfn, "wb+");
	s=(std *) malloc (n * sizeof(std));
	for(i=0; i<n; i++)
		s[i]= readstu(fptr);
	rewind(fptr);
    dispstu(fptr);
    fclose(fptr);
	getch();
	return 0;
}

std readstu(FILE * fptr)
{
	std s;
	int i;
	float sum=0;
	printf("Enter  Name , Roll , Year \n\t");
	scanf("%s %d %d", s.name, &s.roll, &s.year);
	for(i=0; i<2; i++)
	{
		printf("Enter Subject Name / Mark Obtained ");
		scanf("%s %f", s.m[i].sub, &s.m[i].mo);
		sum+=s.m[i].mo;
		s.avg=sum/2;
	}
	fwrite(&s, sizeof(s), 1, fptr);
	return s;
}

void dispstu(FILE * fptr)
{
	int i=0, j, n;
	std s[100], temp;
	while(fread(&temp, sizeof(temp), 1, fptr))
        s[i++]=temp;
	n=i;
    sortper(s, n);
    for(i=0; i<n; i++)
    {
        printf("Name=%s Roll=%d Year=%d Avg=%f\n", s[i].name, s[i].roll, s[i].year, s[i].avg);
        for(j=0; j<2; j++)
            printf("Subject Name=%s Marks Obtained=%f\n", s[i].m[j].sub, s[i].m[j].mo);
    }

}

void sortper(std * s, int n)
{
	std temp;
	int i, j;
	for( i=0; i<n; i++)
		for(j=i+1; j<n; j++)
        {
            if(s[i].avg < s[j].avg)
            {
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
            }
        }
}
