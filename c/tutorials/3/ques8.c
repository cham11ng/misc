#include<stdio.h>
#include<conio.h>

int large(int, int, int);
int main()
{
    int num1, num2, num3, lar;
    printf("Three Number ");
    scanf("%d %d %d", &num1, &num2, &num3);

    lar=large(num1, num2, num3);
    printf("Largest Number %d", lar);
    return 0;

}

int large(int a, int b, int c)
{
    if(a>b && a>c)
        return a;
    else if (b>c && b>a)
        return b;
    else
        return c;
}
