#include<stdio.h>
#include<conio.h>
int main()
{
    float sum=0.0, n;

    do
    {
          printf("Number : ");
          scanf("%f",&n);
          if(n==0)
            break;
          sum=sum+1/n;

    } while(1);

    printf("Sum of reciprocals is : %f", sum);
    getch();
    return 0;
}
