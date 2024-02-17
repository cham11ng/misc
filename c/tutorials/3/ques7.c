#include<stdio.h>
#include<math.h>

int power(int, int);
int tobase(int, int );

int main()
{
    int base, num;
    printf("enter num of 10 base ");
    scanf("%d", &num);
    printf("enter base ");
    scanf("%d", &base);
    printf("Decimal To >> %d base is %d", base, tobase(num, base));
    return 0;

}

int tobase( int num, int db)
{
    int sb=10, i=0, ans=0, rem;
    while (num!=0)
    {
        rem=num%db;
        ans+=(rem*power(sb, i));
        num=num/db;
        i++;
    }
    return ans;
}

int power(int x, int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x, y-1);
}
