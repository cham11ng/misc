#include<stdio.h>
#include<conio.h>
int main()
{
    int age,sum=0, max=0, min=0, i;
    float ave;
    for(i=1;i<=25;i++)
    {
        printf("Age of Person %d : ",i);
        scanf("%d",&age);
        sum=sum+age;
        if(age>max)
            max=age;
        else if(age<min || min==0)
            min=age;
    }
    ave=sum/5.0;
    printf("Maximum Age: %d\n",max);
    printf("Minimum Age: %d\n",min);
    printf("Average Age: %f",ave);
    getch();
}
