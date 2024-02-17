#include<stdio.h>

float average( float *, int);
int main()
{
    float marks[50], avg;
    int n, i;
    printf("No. of student : ");
    scanf("%d",&n);
    printf("Marks Of Physics : \n");
    for(i=0; i<n; i++)
    {
        printf("Student %d : ", i+1);
        scanf("%f", &marks[i]);
    }
    avg=average(marks, n);
    printf("Average Marks Of Physics in Class : %.2f ", avg);
    return 0;
}

float average(float marks[], int n)
{
    int sum=0, i;
    for(i=0; i<n; i++)
        sum=sum+marks[i];
    return sum/n;
}
