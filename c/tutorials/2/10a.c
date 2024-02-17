/* Write a C program to find the sum of cos(x) series */
#include<stdio.h>
#include<conio.h>
#define PI 3.141592654
int main()
{
    int n=0;
   	float x, term=1, sum=1;

	printf("Angle (in degrees) : ");
	scanf("%f",&x);

	x*=(PI/180.0);

	while(term!=0)
   	{
        n++;
        term*= ((-1)*x*x/(n*(n+1)));
        sum+=term;
    }

    printf("Sum of the cosine series= %f\n",sum);
    getch();
    return 0;
}

