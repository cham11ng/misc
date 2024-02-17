#include<stdio.h>
#include<conio.h>

void read(int *, int *);

int main()
{
    int count=0, sum=0;
    float avg;
    read(&count, &sum);
    avg=sum/count;
    if(count)
        printf("The Average Values %.2f  COunt %d ", avg, count);
    else
        printf("No Number Divisible by 4 beween range 10 and 50");
    return 0;
}

void read(int * count, int * sum)
{
    char check[3];
    int num;
    while(1)
    {
        printf("\tNumber ");
        scanf("%d",&num);
        if(num % 4 == 0 && num >= 10 && num <= 50)
        {
            (*sum)+=num;
            (*count)++;
        }
        printf("More (NO to Exit) : ");
        fflush(stdin);
        gets(check);

        if(strcmp(check,"no") && strcmp(check,"NO"))
            continue;
        else
            break;
    }
}
