#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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
	int roll;
	int year;
} stdu;

stdu readstu();
void sortper(stdu *, int);
void dispstu(stdu);

int main()
{
	int n, i;
	stdu * s;
	printf("Enter no of Student ");
	scanf("%d", &n);
	s=(stdu *) malloc (n * sizeof(stdu));
	for(i=0; i<n; i++)
		s[i]= readstu();
	sortper(s, n);
	for(i=0; i<n; i++)
		dispstu(s[i]);
	getch();
	return 0;
}

stdu readstu()
{
	stdu s;
	int i;
	float sum=0;
	printf("Enter  Name , Roll , Year \n\t");
	scanf("%s %d %d", s.name, &s.roll, &s.year);
	for(i=0; i<3; i++)
	{
		printf("Enter Subject Name / Mark Obtained ");
		scanf("%s %f", s.m[i].sub, &s.m[i].mo);
		sum+=s.m[i].mo;
		s.avg=sum/3;
	}
	return s;
}

void dispstu(stdu s)
{
	int i;
	printf("\nName=%s Roll=%d Year=%d Avg=%.2f\n", s.name, s.roll, s.year, s.avg);
	for(i=0; i<3; i++)
		printf("Subject Name=%s Marks Obtained=%.2f\n", s.m[i].sub, s.m[i].mo);
}

void sortper(stdu * s, int n)
{
	stdu temp;
	int i, j;
	for( i=0; i<n; i++)
		for(j=i+1; j<n;j++)
			if(s[i].avg < s[j].avg)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
}
