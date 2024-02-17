#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    int rem, sum, temp, i;

    for(i=1; i<=999; i++)
    {
        sum=0;
        temp=i;
        while (temp != 0)
        {
            rem=temp%10;
            sum+=rem*rem*rem;
            temp/=10;
        }
        if(sum==i)
            printf("%d ", i);
    }
    return 0;
}
