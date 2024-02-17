#include<stdio.h>
#include<conio.h>

int power(int, int);
int binary(int, int, int, int);
int main()
{
    int num, sum = 0, sb, db;
    printf("Number : ");
    scanf("%d", &num);
    printf("Source Base / Destination Base : ");
    scanf("%d %d", &sb, &db);
    printf("Required Ans : %d", binary(sum, num, sb, db));
    return 0;
}

int binary(int sum, int num, int sb, int db)
{
    static int i=0;
    if(num)
        return binary(sum + num % db * power(sb, i++), num/ db, sb, db);
    return sum;
}

int power(int x, int y)
{
    if(y == 0)
        return 1;
    else
        return x * power(x, y-1);
}
