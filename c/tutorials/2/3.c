#include<stdio.h>
#include<conio.h>
int main()
{
    int n, a=0, b=0;

        do
        {
            printf("Number : ");
            scanf("%d",&n);

            if(n<=0)
                break;

            if(n%2==0)
                a++;
            else if(n%2!=0)
                b++;
        } while(1);
    printf("\n Number of \n Even=%d \n Odd=%d", a, b);
    getch();
    return 0;
}
